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
