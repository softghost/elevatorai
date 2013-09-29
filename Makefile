CC           = gcc
CFLAGS       = -Wall -Wextra
RELEASEFLAGS = -O2 -NDEBUG
DEBUGFLAGS   = -O0 -g3
PROFILEFLAGS = -pg

OBJDIR = obj
SRCDIR = src

TARGET  = elevator
SOURCES = $(shell find $(SRCDIR)/ -type f -name "*.c")
HEADERS = $(shell find $(SRCDIR)/ -type f -name "*.h")
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

default: rel

rel: CFLAGS += $(RELEASEFLAGS)
rel: $(TARGET)

dbg: CFLAGS += $(DEBUGFLAGS)
dbg: $(TARGET)

prof: CFLAGS += $(PROFILEFLAGS)
prof: $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	@mkdir -p `dirname $@`
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(LIBS) -o $@

clean:
	@rm -f $(TARGET)
	@rm -rf $(OBJDIR)/
