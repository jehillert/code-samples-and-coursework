# Author: John Hillert
# Date: 11/05/02 
# Description: This is a makefile for lab11.
# It compiles tester.cpp and uses bst.h

CXX = g++
CXXFLAGS = -g -c
LD = g++
LDFLAGS = -g -Wl,-LD_MSG:off=84
 
lab11: tester.o 
	${LD} ${LDFLAGS} tester.o -o tester 

tester.o: tester.cpp 
	${CXX} ${CXXFLAGS} tester.cpp 

clean:
	rm -