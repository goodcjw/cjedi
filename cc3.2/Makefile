CC      = g++
LIBS    = 
DEFS    = -DDEBUG
CFLAGS	= -c -Wall -DDEBUG -g

SOURCES	= cc_3_2.cc

OBJECTS	= $(SOURCES:.cc=.o)
TARGET	= cc_3_2

all: $(SOURCES) $(TARGET)

.cc.o:
	$(CC) $(CFLAGS) $(DEFS) $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@

clean:
	rm $(OBJECTS)
	rm $(TARGET)
