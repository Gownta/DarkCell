CXX = g++
CXXFLAGS = -O2 -g -Wall -MMD -std=gnu++0x -Wno-deprecated $(addprefix -I, $(shell find . -type d))

OBJECTS = $(patsubst %.cpp,%.o,$(wildcard **/*.cpp)) $(patsubst %.cpp,%.o,$(wildcard *.cpp))

DEPENDS = ${OBJECTS:.o=.d}
EXEC = dcc

${EXEC} : ${OBJECTS}
	${CXX} $^ -o $@

${OBJECTS} : Makefile

clean :
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}

