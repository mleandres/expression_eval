CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Werror -MMD
EXEC = expression_eval
OBJECTS = main.o Expression.o Integer.o Variable.o Unaryop.o Binaryop.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
