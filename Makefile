CC = gcc
CFLAGS = -Wall -Wextra -pthread
OBJ = main.o server.o http.o routes.o app.o booking.o storage.o sync.o logger.o
TARGET = server

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
