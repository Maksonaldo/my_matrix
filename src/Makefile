CC = g++ -g
FLAGS = -c -Wall -Werror -Wextra
TEST = my_test.cpp
HEADER = my_matrix_oop.h
OS := $(shell uname -s)
SOURCES = my_matrix_oop.cpp
OBJECTS = $(SOURCES:.cpp=.o)
LFLAGS = -lgtest -L. -lmy_matrix_oop
RFLAGS = -fprofile-arcs -ftest-coverage
ifeq ($(OS), Linux)
    ROPEN = xdg-open
	LDFLAGS += -lrt -lm -lpthread -lsubunit
	LEAKS=valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes -s
else
    ROPEN = open
	LEAKS=CK_FORK=no leaks --atExit --
endif


ifeq ($(OS), Linux) 
	LDFLAGS += -lrt -lm -lpthread -lsubunit
endif

all: clean my_matrix_oop.a test

$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CC) $(FLAGS) $(SOURCES)

my_matrix_oop.a: $(OBJECTS)
	ar rc $@ $(OBJECTS)
	cp $@ lib$@
	ranlib $@
	cp $@ lib$@

test: ${TEST} my_matrix_oop.a
	$(CC) $? -o test.out $(LFLAGS)
	./test.out

gcov_report: $(SOURCES)
	$(CC) $(FLAGS) $(SOURCES) $(RFLAGS)
	ar rcs libmy_matrix_oop.a $(OBJECTS)
	$(CC) -o test ${TEST} $(LFLAGS) -lgcov
	rm -f *.o
	./test
	lcov -t "lcov" -o lcov.info -c -d .
	genhtml -o report lcov.info
	$(ROPEN) ./report/index.html

linter:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=cpp *.cpp *.h
	rm -rf CPPLINT.cfg

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unmatchedSuppression  *.cpp

leaks:
	CK_FORK=no leaks --atExit -- ./test.out

style_check: linter cppcheck

clean:
	-rm -rf *.o *.a *.gcno *.gcda *.info gcov ./test ./report a.out *.dSYM test.out

rebuild: clean all

