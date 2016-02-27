#Makefile for compiling work
#(C) Benjamin Hugo, 2015
#You are free to modify and reuse this in your own practicals
#This file is in the public domain

CPP=g++
CPPFLAGS=-std=c++11
EXE_NAME=driver
#define a generic rule: to go from .cpp to .o files make should invoke the c++ compiler
#the syntax tells make to invoke the compiler without linking (-c), outputting a .o file reading a .cpp file, additionally specifying flags

$(EXE_NAME): driver.o DatabaseUtils.o
	$(CPP) -o $(EXE_NAME) driver.o DatabaseUtils.o $(CPPFLAGS) 

DatabaseUtils.o : DatabaseUtils.h DatabaseUtils.cpp
	$(CPP) -c -o DatabaseUtils.o DatabaseUtils.cpp $(CPPFLAGS)

driver.o : DatabaseUtils.h driver.cpp
	$(CPP) -c -o driver.o driver.cpp $(CPPFLAGS)

#Never submit binaries to your git repo or vula, so create a rule for cleaning up the binary objects just leaving your source code behind
clean:
	@rm *.o driver
#special rule to run your code... your tutor will probably love you for this!
run:
	./driver
