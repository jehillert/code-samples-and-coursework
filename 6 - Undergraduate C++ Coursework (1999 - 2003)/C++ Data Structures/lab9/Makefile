# Author: John Hillert
# Date: 10/21/02
# Description: This is a makefile for lab9.
# It puts together and compiles runway.cpp, S_runway.cpp, S_runway.h, 

CXX = g++
CXXFLAGS = -g -c
LD = g++
LDFLAGS = -g -Wl,-LD_MSG:off=84
 
lab9: S_runway.o runway.o 
	${LD} ${LDFLAGS} runway.o S_runway.o -o runway 

S_runway.o: S_runway.h S_runway.cpp 
	${CXX} ${CXXFLAGS} S_runway.cpp 

runway.o: runway.cpp S_runway.h 
	${CXX} ${CXXFLAGS} runway.cpp 

clean:
	