CC = gcc
EXT = c

# CFLAGS="-Wall -Wextra -Werror -Wpedantic -std=c99  -o3 -mfma" -std=c11  -Wimplicit-function-declaration
CFLAGS = -Wall -Wextra -std=c11
LIBS=-lm

INC = -Isrc
SRC = src
TEST = test
TARGETS_WITH_EXT = $(wildcard $(SRC)/*.$(EXT))
TARGETS = $(basename $(TARGETS_WITH_EXT))

all: clean dir build link

dir:
	mkdir -p build
	mkdir -p build/$(SRC)
	mkdir -p build/$(TEST)

build: $(TARGETS)

$(TARGETS):
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
