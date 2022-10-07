CC=gcc
CFLAGS=-Wall -std=c99
BIN=fragesport
SOURCE=main.c question.c question_list.c
HEADERS=question.h question_list.h

$(BIN): $(SOURCE) $(HEADERS) Makefile
	$(CC) $(CFLAGS) -o $(BIN) $(SOURCE)

clean:
	rm -f $(BIN)

run: $(SOURCE) $(HEADERS) Makefile
	./$(BIN)
