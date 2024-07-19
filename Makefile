CC=g++ # compiler to use
CXXFLAGS= -Wall -std=c++11 # compiler flags
TARGET= main
SRCS= src/main.cpp src/Parser/Parser.cpp src/Code/Code.cpp src/SymbolTable/SymbolTable.cpp
OBJS= $(SRCS:.cpp=.o) # converting to obj file

all = $(TARGET) # default target

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

src/Parser/Parser.o: src/Parser/Parser.cpp src/Parser/Parser.hpp
	$(CXX) $(CXXFLAGS) -c src/Parser/Parser.cpp -o src/Parser/Parser.o
    
src/Code/Code.o: src/Code/Code.cpp src/Code/Code.hpp
	$(CXX) $(CXXFLAGS) -c src/Code/Code.cpp -o src/Code/Code.o

src/SymbolTable/SymbolTable.o: src/SymbolTable/SymbolTable.cpp src/SymbolTable/SymbolTable.hpp
	$(CXX) $(CXXFLAGS) -c src/SymbolTable/SymbolTable.cpp -o src/SymbolTable/SymbolTable.o


clean:
	rm -f $(TARGET) $(OBJS)
