CC=g++ # compiler to use
CXXFLAGS= -Wall -std=c++11 # compiler flags
TARGET= main
SRCS= main.cpp Parser/Parser.cpp Code/Code.cpp
OBJS= $(SRCS:.cpp=.o) # converting to obj file

all = $(TARGET) # default target

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Parser/Parser.o: Parser/Parser.cpp Parser/Parser.hpp
	$(CXX) $(CXXFLAGS) -c Parser/Parser.cpp -o Parser/Parser.o
    
Code/Code.o: Code/Code.cpp Code/Code.hpp
	$(CXX) $(CXXFLAGS) -c Code/Code.cpp -o Code/Code.o

clean:
	rm -f $(TARGET) $(OBJS)
