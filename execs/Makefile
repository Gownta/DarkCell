CXX = g++
CXXFLAGS = -O2 -g -Wall -MMD -std=gnu++0x -Wno-deprecated $(addprefix -I, $(shell find . -type d))

PYGENS = $(shell find . -type f -name '*.cpp.py')
PYSRCS = $(patsubst %.cpp.py, %.cpp, ${PYGENS})
SOURCES = $(shell find . -type f -name '*.cpp') ${PYSRCS}
OBJECTS = ${SOURCES:.cpp=.o}
DEPENDS = ${OBJECTS:.o=.d}

EXEC = dcc

${EXEC} : ${OBJECTS}
	@echo "building $@"
	@${CXX} $^ -o $@

%.o : %.cpp
	@echo "compiling $<"
	@${CXX} -c ${CXXFLAGS} $< -o $@

%.cpp : %.cpp.py
	@echo "generating $@"
	@python $^

${OBJECTS} : Makefile

clean :
	rm -f ${DEPENDS} ${OBJECTS} ${PYSRCS} ${EXEC}

-include ${DEPENDS}

