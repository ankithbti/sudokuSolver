###############
## Makefile
###############

BIN=../bin/SudukoSolverBinary
BOOST_INSTALL_ROOT=/Users/ankithbti/Development/Cpp/boost
HTTP_SERVER_BASE=/Users/ankithbti/Development/Cpp/httpServer

ARCH = $(shell uname -m)	# ARCH becomes the output from the uname -m command.
CXX=/usr/bin/g++
CXXFLAGS=-g -O2 -Wall $(INCS)

SRCS =  Board.cpp SudokuHttpHandler.cpp
MAIN_SRC = Main.cpp

OBJS = $(patsubst %.cpp, %.o, $(SRCS))
MAIN_OBJ = $(patsubst %.cpp, %.o, $(MAIN_SRC))

INCS = -I../include \
       -I$(BOOST_INSTALL_ROOT)/include \
       -I$(HTTP_SERVER_BASE)/include \

LIBS = \
        -L${BOOST_INSTALL_ROOT}/lib -lboost_thread \
        -L${BOOST_INSTALL_ROOT}/lib -lboost_system \
	-L$(HTTP_SERVER_BASE)/lib -lHttpServer \
	-lpthread
	
$(BIN): $(OBJS) $(MAIN_OBJ)
	$(CXX) -o $(BIN) $(OBJS) $(MAIN_OBJ) $(LIBS)

all: $(BIN) run

run:
	@echo "----------------------------"
	@echo "Running the programme. "
	@echo "----------------------------"
	$(BIN)
	@echo "----------------------------"

clean:
	rm -rf $(BIN) *.o
