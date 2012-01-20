CC      = g++
LIBS    = 
DEFS    = -DDEBUG
CFLAGS	= -c -Wall -DDEBUG -g

SOURCES	= af_1_1.cc

OBJECTS	= $(SOURCES:.cc=.o)
TARGET	= af_1_1

all: $(SOURCES) $(TARGET)

.cc.o:
	$(CC) $(CFLAGS) $(DEFS) $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@

clean:
	rm $(OBJECTS)
	rm $(TARGET)
