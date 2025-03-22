CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = bank

SRCDIR = src
INCDIR = include

SRC = $(SRCDIR)/main.c $(SRCDIR)/account.c $(SRCDIR)/file_io.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -I$(INCDIR) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
