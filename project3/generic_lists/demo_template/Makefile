# Where are our moduleS?
MODULES = ../modules

# compile with g++ (although we use .c files)
CC=g++

# Set compiler options here.
#
CFLAGS = -g -Wall -std=c++11

# set the name of the executable file to compile here
PROGRAM = demo_template

# List object files needed to compile the program.
OBJS = main.o

# We use the list module, include its make.inc so that it can configure itself
include $(MODULES)/list_template/make.inc


# Quick and dirty: always clean before building! (by having "clean" as a dependency)
$(PROGRAM): clean $(OBJS)
	$(CC) $(OBJS) -o $(PROGRAM)

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)

