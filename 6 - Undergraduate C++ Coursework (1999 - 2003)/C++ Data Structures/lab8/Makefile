# Author: John Hillert
# Date: 10/15/02 
# Description: This is a makefile for lab8.
# It compiles calc.cpp and uses node2.h

CXX = g++
CXXFLAGS = -g -c
LD = g++
LDFLAGS = -g -Wl,-LD_MSG:off=84
 
lab8: calc.o 
	${LD} ${LDFLAGS} calc.o -o calc 

calc.o: calc.cpp 
	${CXX} ${CXXFLAGS} calc.cpp 

clean:
	rm 