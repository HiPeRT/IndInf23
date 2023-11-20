CC=gcc
AR=ar
RM=rm -rf
LIBNAME=libQ.a
CFLAG=-c -Wall
ARFLAG=-rcs
CSRC=libQ.cpp
COBJ=libQ.o

all:
	$(RM) *.o $(LIBNAME)
	$(CC) $(CFLAG) $(CSRC) -o $(COBJ)
	${AR} ${ARFLAG} $(LIBNAME) $(COBJ)
	
clean:
	$(RM) $(COBJ) $(LIBNAME)