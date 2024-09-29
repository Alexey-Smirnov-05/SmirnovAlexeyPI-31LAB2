#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Структура для хранения информации о треке
typedef struct {
    char title[100];
} Track;

// Структура для хранения плейлиста
typedef struct {
    Track* tracks;
    int total_number_of_tracks; // Общее количество треков в текущем плейлисте
    int current_track; // Текущий трек
} Playlist;

// Структура для хранения громкости
typedef struct {
    int volume;
} Volume;

// Структура для хранения воспроизведения
typedef struct {
    Playlist* playlist;
    int index;
} Playback;

// Структура для хранения паузы
typedef struct {
    Playlist* playlist;
} Pause;

// Структура для хранения перехода к следующему треку
typedef struct {
    Playlist* playlist;
} Skip;

// Структура для хранения возврата к предыдущему треку
typedef struct {
    Playlist* playlist;
} Previous;

// Структура для хранения просмотра треков в плейлисте
typedef struct {
    Playlist* playlist;
} View;

// Функция для добавления трека в плейлист
void add_song(Playlist* playlist, Track song) {
    playlist->tracks = (Track*)realloc(playlist->tracks, (playlist->total_number_of_tracks + 1) * sizeof(Track));
    playlist->tracks[playlist->total_number_of_tracks] = song;
    playlist->total_number_of_tracks++;
}

// Функция для удаления трека из плейлиста
void remove_song(Playlist* playlist, int index) {
    for (int i = index; i < playlist->total_number_of_tracks - 1; i++) {
        playlist->tracks[i] = playlist->tracks[i + 1];
    }
    playlist->total_number_of_tracks--;
    playlist->tracks = (Track*)realloc(playlist->tracks, playlist->total_number_of_tracks * sizeof(Track));
}

// Функция для воспроизведения трека
void play_song(Playback* playback) {
    setlocale(LC_ALL, "RUS");
    printf("Сейчас играет: %s\n", playback->playlist->tracks[playback->index].title);
}

// Функция для паузы трека
void pause_song(Pause* pause) {
    setlocale(LC_ALL, "RUS");
    printf("На паузе\n");
}

// Функция для перехода к следующему треку
void skip_song(Skip* skip) {
    skip->playlist->current_track++;
    if (skip->playlist->current_track >= skip->playlist->total_number_of_tracks) {
        skip->playlist->current_track = 0;
    }
    Playback playback = { skip->playlist, skip->playlist->current_track };
    play_song(&playback);
}

// Функция для возврата на предыдущий трек
void previous_song(Previous* previous) {
    previous->playlist->current_track--;
    if (previous->playlist->current_track < 0) {
        previous->playlist->current_track = previous->playlist->total_number_of_tracks - 1;
    }
    Playback playback = { previous->playlist, previous->playlist->current_track };
    play_song(&playback);
}

// Функция для просмотра всех треков в плейлисте
void view_songs(View* view) {
    setlocale(LC_ALL, "RUS");
    printf("Треки в плейлисте:\n");
    for (int i = 0; i < view->playlist->total_number_of_tracks; i++) {
        printf("%d. %s\n", i + 1, view->playlist->tracks[i].title);
    }
}

// Функция для изменения громкости
void change_volume(Volume* volume, int new_volume) {
    if (new_volume >= 0 && new_volume <= 100) {
        volume->volume = new_volume;
        printf("Громкость изменена на %d%%\n", volume->volume);
    }
    else {
        printf("Неверный диапазон громкости\n");
    }
}
