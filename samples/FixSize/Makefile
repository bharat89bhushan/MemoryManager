all: hello-cpp-world

LIB_PATH = ./../../libs
LIB_FILE = libMemMngr.a
INCLUDE_PATH = ./../../interface

%: %.cc
	g++ -std=c++11 -g $< -I$(INCLUDE_PATH) -L$(LIB_PATH) -lMemMngr -o $@

clean:
	rm hello-cpp-world

rebuild:clean all