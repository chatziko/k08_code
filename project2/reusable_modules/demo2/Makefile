# Where are our moduleS?
MODULES = ../modules

# Set compiler options here.
#
CFLAGS = -g -Wall

# set the name of the executable file to compile here
PROGRAM = demo2

# List object files needed to compile the program.
OBJS = main.o

# We use the point module, include its make.inc so that it can configure itself
include $(MODULES)/point/make.inc


# Note: normally we should list .h dependencies of all .o files so that make
# BUT: things get tricky when conditional compilation is used (make does not detect changes in variables!)
# Simple solution: always clean before building! (by having "clean" as a dependency)
# (there are better solutions, but for our needs this one is good and simple)
#
$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM) -lm

clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)

