# Author: John Hillert
# Date: 9/3/02
# Description: This is a makefile for lab2.
# It puts together and compiles line.cpp, point.cpp, driver.cpp, 
# line.h, and point.h

CXX = g++
CXXFLAGS = -g -c
LD = g++
LDFLAGS = -g -Wl,-LD_MSG:off=84
 
lab2: line.o point.o driver.o 
	${LD} ${LDFLAGS} line.o point.o driver.o -o lab2

point.o: point.h point.cpp 
	${CXX} ${CXXFLAGS} point.cpp 

line.o: line.h line.cpp point.h
	${CXX} ${CXXFLAGS} line.cpp 

driver.o: driver.cpp point.h line.h
	${CXX} ${CXXFLAGS} driver.cpp 

clean