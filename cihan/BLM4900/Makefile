CC 	= gcc
CFLAS 	= -Wall -O2 
TARGET 	= Test
OBJS	= misc.o

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) main.c -o $(TARGET)

misc.o:
	$(CC) -c misc.c

clean:
	rm -f *.o
	rm -f $(TARGET)
rebuild:
	
	make clean
	make all
