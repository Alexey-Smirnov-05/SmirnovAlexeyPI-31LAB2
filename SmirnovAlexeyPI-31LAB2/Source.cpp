#include "Header.h"

int main() {
    setlocale(LC_ALL, "RUS");
    Playlist playlist;
    playlist.total_number_of_tracks = 0;
    playlist.current_track = 0;
    playlist.tracks = (Track*)malloc(sizeof(Track));

    Volume volume;
    volume.volume = 50; // Громкость по умолчанию

    load_tracks_from_file(&playlist, "playlist.txt");

    int choice;
    while (1) {
        printf("Меню плеера:\n");
        printf("0. Добавить трек\n");
        printf("1. Изменить громкость\n");
        printf("2. Воспроизвести\n");
        printf("3. Пауза\n");
        printf("4. Следующий трек\n");
        printf("5. Предыдущий трек\n");
        printf("6. Удалить трек\n");
        printf("7. Просмотреть треки в плейлисте\n");
        printf("8. Выход\n");
        printf("Действие: ");
        scanf("%d", &choice);


    }
	return 0;
}