CXX = g++
CXXFLAGS = -O2 -g -Wall -MMD -std=gnu++0x -Wno-deprecated

OBJECTS = DarkCell.o

DEPENDS = ${OBJECTS:.o=.d}
EXEC = dcc

${EXEC} : ${OBJECTS}
	${CXX} $^ -o $@

${OBJECTS} : Makefile

clean :
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}

