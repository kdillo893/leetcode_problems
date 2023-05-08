.DEFAULT_GOAL=leetcode

CC=gcc
CFLAGS= -I. -g 
WARNINGS= -Wall -Wextra
LIBS= 
#DEPS= nothing right now...

FUNCDIR := funcs
OBJDIR := objs
OBJS := $(addprefix $(OBJDIR)/, findball.o helpers.o ishappynum.o longcommonprefix.o mergesort.o multiplystrings.o removeNthFromEnd.o spiralorder.o)
#OBJS := $(addprefix $(OBJDIR)/, *.o)

%.o : | $(OBJDIR)

$(OBJDIR)/%.o : $(FUNCDIR)/%.c
	$(CC) $(CFLAGS) $(WARNINGS) -c -o $@ $<

#Explicitly listing rules for the files, because the pattern doesn't seem to work..

#findball.o: funcs/findball.c
#	$(CC) $(CFLAGS) $(WARNINGS) -c funcs/findball.c findball.o
#helpers.o: funcs/helpers.c
#	$(CC) $(CFLAGS) $(WARNINGS) -c funcs/helpers.c helpers.o
#ishappynum.o: funcs/ishappynum.c
#	$(CC) $(CFLAGS) $(WARNINGS) -c funcs/ishappynum.c ishappynum.o
#longcommonprefix.o: funcs/longcommonprefix.c
#	$(CC) $(CFLAGS) $(WARNINGS) -c funcs/longcommonprefix.c longcommonprefix.o
#mergesort.o: funcs/mergesort.c
#	$(CC) $(CFLAGS) $(WARNINGS) -c funcs/mergesort.c mergesort.o
#multiplystrings.o: funcs/multiplystrings.c
#	$(CC) $(CFLAGS) $(WARNINGS) -c funcs/multiplystrings.c multiplystrings.o
#removeNthFromEnd.o: funcs/removeNthFromEnd.c
#	$(CC) $(CFLAGS) $(WARNINGS) -c funcs/removeNthFromEnd.c removeNthFromEnd.o
#spiralorder.o: funcs/spiralorder.c
#	$(CC) $(CFLAGS) $(WARNINGS) -c funcs/spiralorder.c spiralorder.o
#

clean:
	rm *.o objs/*.o ./leetcode

leetcode: $(OBJS) 
	$(CC) $(CFLAGS) $(WARNINGS) -o leetcode leetcode_main.c $^

