CC = gcc
CFLAGS = -W
TARGET = stream_mgr

$(TARGET) : main.o rwfile.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o rwfile.o

main.o : main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

rwfile.o : rwfile.c
	$(CC) $(CFLAGS) -c -o rwfile.o rwfile.c

clean :
	rm *.o stream_mgr
	rm -r OUTPUT
