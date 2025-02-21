CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDE_DIR = ../include
INCLUDES = -I$(INCLUDE_DIR)

#SRC = src/main.c src/parse.c src/process.c src/read.c \
      src/built-ins/cd.c src/built-ins/exit.c src/built-ins/export.c \
      src/built-ins/help.c src/built-ins/pwd.c src/built-ins/unset.c
SRC = $(wildcard src/*.c src/built-ins/*.c)
OBJ = $(SRC:.c=.o)
TARGET = shell

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
