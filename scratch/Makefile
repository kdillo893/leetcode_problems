CC=gcc
CFLAGS=-W -g 

ODIR=obj
LDIR =../lib

LIBS=-lm

%.o:
	make $(patsubst %, $(ODIR)/%, $@)

#make condition for "objdir/%.o", then need to find ways for objects to make here.
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

_TC_OBJS = typecheck.o
_SW_OBJS = simple_filewrite.o

typecheck: $(_TC_OBJS)
	$(CC) -o $@ $(patsubst %, $(ODIR)/%, $^) $(CFLAGS) $(LIBS)

simple_filewrite: $(_SW_OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o testfile.txt simple_filewrite typecheck 
