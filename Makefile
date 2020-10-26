# Compiler
CC = gcc

# Make directory command
MAKE = mkdir -p

# Remove command
RM = rm -rf

# Directories
SRCDIR = src
OBJDIR = .obj
BINDIR = bin

# Files
ARRAY_O = $(OBJDIR)/array.o
ARRAY_C = $(SRCDIR)/array.c
ARRAY_H = $(SRCDIR)/array.h

SRC = $(filter-out $(SRCDIR)/array.c, $(wildcard $(SRCDIR)/*.c))
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
BIN = $(SRC:$(SRCDIR)/%.c=$(BINDIR)/%)

.PRECIOUS: $(OBJ)

all: $(BIN)

$(BINDIR)/%: $(OBJDIR)/%.o $(ARRAY_O) | $(BINDIR)
	$(CC) $< $(ARRAY_O) -o $@

$(BINDIR):
	$(MAKE) $(BINDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) -c $< -o $@

$(OBJDIR):
	$(MAKE) $(OBJDIR)

$(ARRAY_O): $(ARRAY_C) $(ARRAY_H)
	$(CC) -c $(ARRAY_C) -o $@

clean:
	$(RM) $(BINDIR) $(OBJDIR)
