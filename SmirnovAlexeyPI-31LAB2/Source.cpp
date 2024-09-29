#include "Header.h"

int main() {
    setlocale(LC_ALL, "RUS");
    Playlist playlist;
    playlist.total_number_of_tracks = 0;
    playlist.current_track = 0;
    playlist.tracks = (Track*)malloc(sizeof(Track));

    Volume volume;
    volume.volume = 50; // ��������� �� ���������

    load_tracks_from_file(&playlist, "playlist.txt");

    int choice;
    while (1) {
        printf("���� ������:\n");
        printf("0. �������� ����\n");
        printf("1. �������� ���������\n");
        printf("2. �������������\n");
        printf("3. �����\n");
        printf("4. ��������� ����\n");
        printf("5. ���������� ����\n");
        printf("6. ������� ����\n");
        printf("7. ����������� ����� � ���������\n");
        printf("8. �����\n");
        printf("��������: ");
        scanf("%d", &choice);

        switch (choice) {
        case 0: {
            Track song;
            printf("������� �������� �����: ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            fgets(song.title, sizeof(song.title), stdin);
            song.title[strcspn(song.title, "\n")] = 0;
            add_song(&playlist, song);
            save_tracks_to_file(&playlist, "playlist.txt");
            break;
        }
        case 1: {
            int new_volume;
            printf("������� ��������� (0-100): ");
            scanf("%d", &new_volume);
            change_volume(&volume, new_volume);
            break;
        }
        case 2:
            if (playlist.total_number_of_tracks > 0) {
                Playback playback = { &playlist, playlist.current_track };
                play_song(&playback);
            }
            else {
                printf("��� ������ � ���������\n");
            }
            break;

        }
    }
	return 0;
}