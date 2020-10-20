# Compiler
CC = gcc

# Remove command
RM = rm -rf

# Directories
SRCDIR = src
OBJDIR = .obj
BINDIR = bin

# Files
ARRAY_O = .obj/array.o
ARRAY_C = src/array.c
ARRAY_H = src/array.h

SRC = $(filter-out $(SRCDIR)/array.c, $(wildcard $(SRCDIR)/*.c))
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
BIN = $(SRC:$(SRCDIR)/%.c=$(BINDIR)/%)

.PRECIOUS: $(OBJ)

all: $(BINDIR) $(OBJDIR) $(BIN)

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR)/%: $(OBJDIR)/%.o $(ARRAY_O)
	$(CC) $< $(ARRAY_O) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@

$(ARRAY_O): $(ARRAY_C) $(ARRAY_H)
	$(CC) -c $(ARRAY_C) -o $@

clean:
	$(RM) $(BINDIR) $(OBJDIR)
