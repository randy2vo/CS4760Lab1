CXX = g++
CXXFLAGS = -Wall -g -std=c++17

all: oss user

oss: oss.cpp
	$(CXX) $(CXXFLAGS) -o oss oss.cpp

user: user.cpp
	$(CXX) $(CXXFLAGS) -o user user.cpp

clean: 
	rm -f oss user *.o
#hello#
