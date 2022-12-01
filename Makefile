TARGET = main

all:
	gcc _src/main.c _src/command.c _src/ADT/array_modif.c _src/ADT/functions.c _src/ADT/mesinkar.c _src/ADT/mesinkata_modif.c _src/ADT/queue_modif.c _src/game/dinerdash/dinerdash.c _src/game/dinerdash/list_pesanan.c _src/game/dinerdash/queue.c _src/game/game_kartu/game_kartu.c _src/game/game_kartu/drawnlist.c _src/game/game_kartu/list.c _src/game/game_kartu/main_game.c _src/game/game_kartu/queue.c _src/game/game_kartu/stack.c _src/game/GameToH/GameToH.c _src/ADT/stack_modif.c _src/ADT/map_scoreboard.c _src/ADT/arrPoint.c _src/ADT/linkedlist.c _src/ADT/point.c _src/game/snakeonmeteor/*.c -o $(TARGET)

clean:
	rm $(TARGET)