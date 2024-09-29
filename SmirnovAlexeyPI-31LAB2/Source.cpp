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

        switch (choice) {
        case 0: {
            Track song;
            printf("Введите название трека: ");
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
            printf("Введите громкость (0-100): ");
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
                printf("Нет треков в плейлисте\n");
            }
            break;
        case 3:
            if (playlist.total_number_of_tracks > 0) {
                Pause pause;
                pause.playlist = &playlist;
                pause_song(&pause);
            }
            else {
                printf("Нет треков в плейлисте\n");
            }
            break;
        case 4:
            if (playlist.total_number_of_tracks > 0) {
                Skip skip;
                skip.playlist = &playlist;
                skip_song(&skip);
            }
            else {
                printf("Нет треков в плейлисте\n");
            }
            break;
        case 5:
            if (playlist.total_number_of_tracks > 0) {
                Previous previous;
                previous.playlist = &playlist;
                previous_song(&previous);
            }
            else {
                printf("Нет треков в плейлисте\n");
            }
            break;
        case 6: {
            if (playlist.total_number_of_tracks > 0) {
                int index;
                printf("Введите индекс трека для удаления: ");
                scanf("%d", &index);
                if (index >= 1 && index <= playlist.total_number_of_tracks) {
                    remove_song(&playlist, index - 1);
                    save_tracks_to_file(&playlist, "playlist.txt"); // Сохраняем изменения в файле
                }
                else {
                    printf("Неверный индекс\n");
                }
            }
            else {
                printf("Нет треков в плейлисте\n");
            }
            break;
        }
        case 7:
            if (playlist.total_number_of_tracks > 0) {
                View view;
                view.playlist = &playlist;
                view_songs(&view);
            }
            else {
                printf("Нет треков в плейлисте\n");
            }
            break;
        
        }
    }
	return 0;
}