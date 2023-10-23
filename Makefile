CC = gcc
EXT = c

# CFLAGS="-Wall -Wextra -Werror -Wpedantic -std=c99  -o3 -mfma"
CFLAGS = -Wall -Wextra -std=c11
# LIBS="-lm"
LIBS =

INC = -I src
SRC = src
TARGETS_WITH_EXT = $(wildcard $(SRC)/*.$(EXT))
TARGETS = $(basename $(TARGETS_WITH_EXT))

all: clean build link

build: $(TARGETS)

$(TARGETS):
	mkdir -p build
	mkdir -p build/src
	mkdir -p build/test
	$(CC) $(CFLAGS) $(INC) -c $@.$(EXT) -o build/$@.o

link:
	$(CC) $(CFLAGS) $(INC) -o build/$(SRC)/main $(wildcard build/$(SRC)/*.o) $(LIBS)

build_and_link:
	$(CC) $(CFLAGS) $(INC) $(SRC)/*.$(EXT) -o build/main

run:
	./build/$(SRC)/main

clean:
	rm -rf build/*
	rm -rf *.o
	rm -rf compile_commands.json

.PHONY: all clean run link build
