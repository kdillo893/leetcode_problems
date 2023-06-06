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

#Notes for self:
#	 $<  translates to "the first prereq"
#	 $@  translates to "the target of the make"
#	 $^  translates to "all prereqs" (objs would be every object file), spec by pattern
#	 %   is wildcard
#	 *   is a different wildcard...
#	 $() is reference to a variable defined in the makefile, substitutes the value in.
#	 ... didn't figure out how to "specify variable for sub-prereq"...
#
#	 normal prereqs | order-only-prereqs (see 4.2 of make manual)
#	 	normal prereqs assume "new prereq means we must rebuild the target"
#	 	order-only prereqs will not force a rebuild of the target.
