CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDE_DIR = ../include
INCLUDES = -I$(INCLUDE_DIR)

SRC = main.c parse.c process.c read.c \
      built-ins/cd.c built-ins/exit.c built-ins/export.c \
      built-ins/help.c built-ins/pwd.c built-ins/unset.c

OBJ = $(SRC:.c=.o)
TARGET = shell

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
