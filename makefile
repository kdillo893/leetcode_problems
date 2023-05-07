CC=gcc
#cflags: -I to include header files from this directory (can add more)
CFLAGS=-I. 
WARNINGS=-Wall -Wextra
#DEPS= nothing right now...

clean:
	rm *.o *.out testfile.txt

leetcode:
	$(CC) $(WARNINGS) -o leetcode.out leetcode_main.c $(CFLAGS)

cleanasm:
	rm *.s
