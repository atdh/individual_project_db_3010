CXX = g++
CXXFLAGS	= -std=c++17 -g -Wall

all: db

clean:
	rm ourdb.o db.o db

db: ourdb.o db.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp ourdb.o db.o -o db

ourdb.o: ourdb.cpp
	$(CXX) $(CXXFLAGS) -c ourdb.cpp

db.o: db.cpp
	$(CXX) $(CXXFLAGS) -c db.cpp


