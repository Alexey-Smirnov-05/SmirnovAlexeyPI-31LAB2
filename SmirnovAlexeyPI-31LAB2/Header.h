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
