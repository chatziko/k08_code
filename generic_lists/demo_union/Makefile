# Where are our moduleS?
MODULES = ../modules

# Set compiler options here.
# Set -I. so that include files in this directory are always found (even when compiling the modules in other dirs)
#
CFLAGS = -g -Wall -I.

# set the name of the executable file to compile here
PROGRAM = demo_union

# List object files needed to compile the program.
OBJS = main.o

# We use the list module, include its make.inc so that it can configure itself
include $(MODULES)/list_typed/make.inc


# Quick and dirty: always clean before building! (by having "clean" as a dependency)
$(PROGRAM): clean $(OBJS)
	$(CC) $(OBJS) -o $(PROGRAM) -lm

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)

