CXX = g++
CXXFLAGS	= -std=c++17 -g -Wall

all: 
	$(CXX) $(CXXFLAGS) *.cpp -o main

clean:
	rm *.o
