# Author: John Hillert
# Date: 9/3/02
# Description: This is a makefile for lab2.
# It puts together and compiles line.cpp, point.cpp, driver.cpp, 
# line.h, and point.h

CXX = g++
CXXFLAGS = -g -c
LD = g++
LDFLAGS = -g -Wl,-LD_MSG:off=84
 
lab4: string_sequence.o driver.o 
	${LD} ${LDFLAGS} string_sequence.o driver.o -o teststring 

string_sequence.o: string_sequence.h string_sequence.cpp 
	${CXX} ${CXXFLAGS} string_sequence.cpp 

driver.o: driver.cpp string_sequence.h 
	${CXX} ${CXXFLAGS} driver.cpp 

clean:
