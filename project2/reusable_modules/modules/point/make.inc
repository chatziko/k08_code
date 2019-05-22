# This file is part of the point module.
#
# Anyone who wants to use the point module should include this file in their
# Makefile, so that compilation is configured properly
#
 
# Set compiler flags. -I... tells the compiler to look in our directory for
# include files, so that #include "point.h" works.
#
CFLAGS += -I$(MODULES)/point

# We need to compile point.o
#
OBJS += $(MODULES)/point/point.o

# We use the list module, include its make.inc so that it can configure itself.
#
include $(MODULES)/list/make.inc
