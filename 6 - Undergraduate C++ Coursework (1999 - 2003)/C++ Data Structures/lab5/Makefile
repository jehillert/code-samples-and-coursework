# Author: John Hillert
# Date: 9/24/02
# Description: This is a makefile for lab5.
# It puts together and compiles node.cpp, node.h, driver.cpp, 

CXX = g++
CXXFLAGS = -g -c
LD = g++
LDFLAGS = -g -Wl,-LD_MSG:off=84
 
lab5: node.o driver.o 
	${LD} ${LDFLAGS} node.o driver.o -o lab5 

node.o: node.h node.cpp 
	${CXX} ${CXXFLAGS} node.cpp 

driver.o: driver.cpp node.h 
	${CXX} ${CXXFLAGS} driver.cpp 

clean:
	