# Where are our moduleS?
MODULES = ../modules

# Set compiler options here.
#
CFLAGS = -g -Wall

# set the name of the executable file to compile here
PROGRAM = demo_untyped

# List object files needed to compile the program.
OBJS = main.o

# We use the list module, include its make.inc so that it can configure itself
include $(MODULES)/list_untyped/make.inc


# Quick and dirty: always clean before building! (by having "clean" as a dependency)
$(PROGRAM): clean $(OBJS)
	$(CC) $(OBJS) -o $(PROGRAM) -lm

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)

