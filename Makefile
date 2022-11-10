TARGET = main

all:
	gcc _src/main.c _src/command.c _src/ADT/array_modif.c _src/ADT/functions.c _src/ADT/mesinkar.c _src/ADT/mesinkata_modif.c _src/ADT/queue_modif.c -o $(TARGET)

clean:
	rm $(TARGET)