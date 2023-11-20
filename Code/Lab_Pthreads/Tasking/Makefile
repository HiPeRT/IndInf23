CC=gcc
RM=rm -rf
EXENAME=tasking
INCDIR=-I LibQ/
LDFLAG=-l stdc++ -l pthread
CFLAG=-fpermissive -Wall $(INCDIR)
CSRCS=main.cpp LibQ/libQ.cpp

all:
	$(RM) *.o $(EXENAME)
	$(CC) $(CFLAG) -o $(EXENAME) $(CSRCS) $(LDFLAG)
	
clean:
	$(RM) *.o $(EXENAME)

run: all
	./$(EXENAME)