#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// ��������� ��� �������� ���������� � �����
typedef struct {
    char title[100];
} Track;

// ��������� ��� �������� ���������
typedef struct {
    Track* tracks;
    int total_number_of_tracks; // ����� ���������� ������ � ������� ���������
    int current_track; // ������� ����
} Playlist;

// ��������� ��� �������� ���������
typedef struct {
    int volume;
} Volume;

// ��������� ��� �������� ���������������
typedef struct {
    Playlist* playlist;
    int index;
} Playback;

// ��������� ��� �������� �����
typedef struct {
    Playlist* playlist;
} Pause;

// ��������� ��� �������� �������� � ���������� �����
typedef struct {
    Playlist* playlist;
} Skip;

// ��������� ��� �������� �������� � ����������� �����
typedef struct {
    Playlist* playlist;
} Previous;

// ��������� ��� �������� ��������� ������ � ���������
typedef struct {
    Playlist* playlist;
} View;

// ������� ��� ���������� ����� � ��������
void add_song(Playlist* playlist, Track song) {
    playlist->tracks = (Track*)realloc(playlist->tracks, (playlist->total_number_of_tracks + 1) * sizeof(Track));
    playlist->tracks[playlist->total_number_of_tracks] = song;
    playlist->total_number_of_tracks++;
}

// ������� ��� �������� ����� �� ���������
void remove_song(Playlist* playlist, int index) {
    for (int i = index; i < playlist->total_number_of_tracks - 1; i++) {
        playlist->tracks[i] = playlist->tracks[i + 1];
    }
    playlist->total_number_of_tracks--;
    playlist->tracks = (Track*)realloc(playlist->tracks, playlist->total_number_of_tracks * sizeof(Track));
}

// ������� ��� ��������������� �����
void play_song(Playback* playback) {
    setlocale(LC_ALL, "RUS");
    printf("������ ������: %s\n", playback->playlist->tracks[playback->index].title);
}

// ������� ��� ����� �����
void pause_song(Pause* pause) {
    setlocale(LC_ALL, "RUS");
    printf("�� �����\n");
}

// ������� ��� �������� � ���������� �����
void skip_song(Skip* skip) {
    skip->playlist->current_track++;
    if (skip->playlist->current_track >= skip->playlist->total_number_of_tracks) {
        skip->playlist->current_track = 0;
    }
    Playback playback = { skip->playlist, skip->playlist->current_track };
    play_song(&playback);
}

// ������� ��� �������� �� ���������� ����
void previous_song(Previous* previous) {
    previous->playlist->current_track--;
    if (previous->playlist->current_track < 0) {
        previous->playlist->current_track = previous->playlist->total_number_of_tracks - 1;
    }
    Playback playback = { previous->playlist, previous->playlist->current_track };
    play_song(&playback);
}

// ������� ��� ��������� ���� ������ � ���������
void view_songs(View* view) {
    setlocale(LC_ALL, "RUS");
    printf("����� � ���������:\n");
    for (int i = 0; i < view->playlist->total_number_of_tracks; i++) {
        printf("%d. %s\n", i + 1, view->playlist->tracks[i].title);
    }
}

// ������� ��� ��������� ���������
void change_volume(Volume* volume, int new_volume) {
    if (new_volume >= 0 && new_volume <= 100) {
        volume->volume = new_volume;
        printf("��������� �������� �� %d%%\n", volume->volume);
    }
    else {
        printf("�������� �������� ���������\n");
    }
}

// ������� ��� ���������� ������ � ����
void save_tracks_to_file(Playlist* playlist, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i < playlist->total_number_of_tracks; i++) {
        fprintf(file, "%s\n", playlist->tracks[i].title);
    }

    fclose(file);
}

// ������� ��� �������� ������ �� �����
void load_tracks_from_file(Playlist* playlist, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return;
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        Track song;
        strcpy(song.title, line);
        add_song(playlist, song);
        i++;
    }

    fclose(file);
}
