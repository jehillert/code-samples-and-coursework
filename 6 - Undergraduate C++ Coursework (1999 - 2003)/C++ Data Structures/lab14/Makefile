# Author: John Hillert
# Date: 9/24/02
# Description: This is a makefile for lab14.
# It puts together and compiles w_field.cpp, w_field.h, driver.cpp

CXX = g++
CXXFLAGS = -g -c
LD = g++
LDFLAGS = -g -Wl,-LD_MSG:off=84
 
lab14: w_field.o driver.o 
	${LD} ${LDFLAGS} w_field.o driver.o -o lab14

w_field.o: w_field.h w_field.cpp 
	${CXX} ${CXXFLAGS} w_field.cpp 

driver.o: driver.cpp w_field.h 
	${CXX} ${CXXFLAGS} driver.cpp 

clean:
	r