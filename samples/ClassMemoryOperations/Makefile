all: class-memory-operations

LIB_PATH = ./../../libs
LIB_FILE = libMemMngr.a
INCLUDE_PATH = ./../../interface

%: %.cpp
	g++ -std=c++11 -g $< -I$(INCLUDE_PATH) -L$(LIB_PATH) -lMemMngr -o $@

clean:
	rm class-memory-operations

rebuild:clean all
