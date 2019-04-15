# This file is part of the stack module.
#
# Anyone who wants to use the stack module should include this file in their
# Makefile, so that compilation is configured properly
#
 
# Set compiler flags. -I... tells the compiler to look in our directory for
# include files, so that #include "stack.h" works.
#
CFLAGS += -I$(MODULES)/stack

# We need to compile stack.o
#
OBJS += $(MODULES)/stack/stack.o

# We use the list module, include its make.inc so that it can configure itself.
#
include $(MODULES)/list/make.inc
