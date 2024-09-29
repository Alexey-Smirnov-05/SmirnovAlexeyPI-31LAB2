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
