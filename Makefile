CC = gcc
CFLAGS = -Wall -Werror -g -c -I include
LDFLAGS = -L lib
LDLIBS = -lraylib -lgdi32 -lwinmm

TARGET = chess.exe
SRC = main.c board.c pieces.c
OBJ = $(SRC:.c=.o)


%.o: %.c
	@echo Compiling $< ...
	@$(CC) $(CFLAGS) $< -o $@

chess : $(OBJ)
	@echo Linking $@ ...
	@$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@
	@echo Done!

clean:
	@rm -rf *.o
	@rm -rf $(TARGET)
	@echo All Clean!