CXX = g++
CXXFLAGS	= -std=c++17 -g -Wall

all: db

clean:
	rm ourdb.o db.o ourstore.o db

db: ourdb.o db.o ourstore.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp ourdb.o db.o ourstore.o -o db

ourdb.o: ourdb.cpp
	$(CXX) $(CXXFLAGS) -c ourdb.cpp

db.o: db.cpp
	$(CXX) $(CXXFLAGS) -c db.cpp

ourstore.o: ourstore.cpp
	$(CXX) $(CXXFLAGS) -c ourstore.cpp