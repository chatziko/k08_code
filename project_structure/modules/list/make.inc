# This file is part of the list module.
#
# Anyone who wants to use the list module should include this file in their
# Makefile, so that compilation is configured properly
#
 
# Set compiler flags. -I... tells the compiler to look in our directory for
# include files, so that #include "list.h" works.
#
CFLAGS += -I$(MODULES)/list

# Always compile common.o (but we will add more .o files to be compiled below!)
#
OBJS += $(MODULES)/list/common.o

# CONDITIONAL COMPILATION
#
# Use the LIST_IMPL=[linked|sequential] flag to select whether a linked or
# sequential implementation of lists is used. We need to do 2 things:
#  1. compile the correct implementation (linked.o OR sequential.o)
#  2. set (with -D...) the correct preprocessor flag (LST_IMPL_LINKED OR
#     LST_IMPL_SEQUENTIAL) so that #ifdef works in the code (see list.h)
#
ifeq ($(LST_IMPL),linked)
	# linked implementation
	CFLAGS += -DLST_IMPL_LINKED
	OBJS += $(MODULES)/list/linked.o
else
	# sequential implementation (default)
	CFLAGS += -DLST_IMPL_SEQUENTIAL
	OBJS += $(MODULES)/list/sequential.o
endif
