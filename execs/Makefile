CXX = g++
CXXFLAGS = -O2 -g -Wall -MMD -std=gnu++0x -Wno-deprecated $(addprefix -I, $(shell find . -type d))

SOURCES = $(shell find . -type f -name '*.cpp')
OBJECTS = ${SOURCES:.cpp=.o}
DEPENDS = ${OBJECTS:.o=.d}

EXEC = dcc

${EXEC} : ${OBJECTS}
	@echo "building $@"
	@${CXX} $^ -o $@

%.o : %.cpp
	@echo "compiling $@"
	@${CXX} -c ${CXXFLAGS} $< -o $@

${OBJECTS} : Makefile

clean :
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}

