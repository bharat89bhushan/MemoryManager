OUTFILE = libMemMngr.a
OUT_DIR = ./../libs/

all: $(OUT_DIR)$(OUTFILE)

OBJ_FILE = MemoryManager.o

SRC_FILE = %.cpp
SRC_DIR = ./src

INCLUDE_PATH = ./include
INTERFACE_PATH = ./../interface


$(OUT_DIR)$(OUTFILE):	$(SRC_DIR)/$(OBJ_FILE)
	ar rsc $(OUT_DIR)$(OUTFILE) $<
	#ar rsc $(OUT_DIR)$(OUTFILE) $(SRC_DIR)/*.o


$(SRC_DIR)/$(OBJ_FILE): $(SRC_DIR)/%.o: $(SRC_DIR)/$(SRC_FILE)
	g++ -g -c -I$(INCLUDE_PATH) -I$(INTERFACE_PATH) $< -o $@
	#g++ -c $< -I$(INCLUDE_PATH) -I$(INTERFACE_PATH) -o $(SRC_DIR)/*.cpp
	
	
clean:
	rm $(SRC_DIR)/*.o $(OUT_DIR)libMemMngr.a
