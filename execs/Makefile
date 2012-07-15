CXX = g++
CXXFLAGS = -O2 -g -Wall -MMD -std=gnu++0x -Wno-deprecated $(addprefix -I, $(shell find . -type d))

PYGENS = $(shell find . -type f -name '*.cpp.py')
PYSRCS = $(patsubst %.cpp.py, %.cpp, ${PYGENS})
SOURCES = $(shell find . -type f -name '*.cpp') ${PYSRCS} lex.yy.cpp
OBJECTS = ${SOURCES:.cpp=.o}
DEPENDS = ${OBJECTS:.o=.d}

EXEC = dcc

${EXEC} : ${OBJECTS}
	@echo "linking    $@"
	@${CXX} $^ -o $@

%.o : %.cpp
	@echo "compiling  $<"
	@${CXX} -c ${CXXFLAGS} $< -o $@

%.cpp : %.cpp.py
	@echo "generating $@"
	@python $^

lex.yy.cpp : Parser/tokens.lang
	@echo "generating $@"
	@flex -olex.yy.cpp Parser/tokens.lang

# ${OBJECTS} : Makefile
# ${PYSRCS} : Makefile

clean :
	@rm -f ${DEPENDS} ${OBJECTS} ${PYSRCS} ${EXEC}

-include ${DEPENDS}

.SECONDARY : ${PYSRCS}

