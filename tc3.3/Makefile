CC      = g++
LIBS    = 
DEFS    = -DDEBUG
CFLAGS	= -c -Wall -DDEBUG -g

SOURCES	= tc_3_3.cc

OBJECTS	= $(SOURCES:.cc=.o)
TARGET	= tc_3_3

all: $(SOURCES) $(TARGET)

.cc.o:
	$(CC) $(CFLAGS) $(DEFS) $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@

clean:
	rm $(OBJECTS)
	rm $(TARGET)
