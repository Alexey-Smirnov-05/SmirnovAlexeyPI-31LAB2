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


    }
	return 0;
}