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

clean:
	rm *.o objs/*.o ./leetcode

leetcode: $(OBJS) 
	$(CC) $(CFLAGS) $(WARNINGS) -o leetcode leetcode_main.c $^

