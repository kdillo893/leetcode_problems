.DEFAULT_GOAL=leetcode

CC=gcc
CFLAGS= -I. -g 
WARNINGS= -Wall -Wextra
LIBS= 
#DEPS= nothing right now...

FUNCDIR := funcs
OBJDIR := objs

SOURCES := $(wildcard $(FUNCDIR)/*.c)
OBJS := $(patsubst $(FUNCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES)) 

###### rule definitions

all:
	$(MAKE) clean leetcode

%.o : | $(OBJDIR)

$(OBJDIR)/%.o : $(FUNCDIR)/%.c
	$(CC) $(CFLAGS) $(WARNINGS) -I./$(FUNCDIR) -c -o $@ $<

clean:
	rm objs/*.o ./leetcode

leetcode: $(OBJS) 
	$(CC) $(CFLAGS) $(WARNINGS) -o leetcode leetcode_main.c $^

