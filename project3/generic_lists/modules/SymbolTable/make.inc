ifndef ST_MAKE_INC	# include guard for make.inc
ST_MAKE_INC=1

# This file is part of the list module.
#
# Anyone who wants to use the list module should include this file in their
# Makefile, so that compilation is configured properly
#
 
# Set compiler flags. -I... tells the compiler to look in our directory for
# include files, so that #include works.

CFLAGS += -I$(MODULES)/SymbolTable

OBJS += $(MODULES)/SymbolTable/SymbolTable.o


endif #include guard
