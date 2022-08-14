BD=../build/
QMAKE=$(BD)
CFLAGS= -c -Wall -Wextra -Werror
LDFLAGS=#-Wall -Wextra -Werror
LCOVFLAGS=-fprofile-arcs -ftest-coverage
GTESTFLAGS=-lgtest -I./ -L./
EXE=$(QMAKE)calc.app/Contents/MacOS/calc
APP=$(QMAKE)calc.app
APPDIR=../build/
APP_EXE=$(APPDIR)/qmake.app/Contents/MacOS/qmake
CC=gcc

all: install
	$(APP_EXE)

build:
	gcc s21calc.c test.c -o test -lcheck

./$(BD)qmake.pro:
	cp qmake.pro $(QMAKE)

./$(BD)%.o: */%.c
	$(CC) $(CFLAGS) $< -o $@

./$(BD)%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

install:
	-@mkdir ../build/
	-@cp *.c *.cpp *.h *.pro *.ui ../build
	-@cd ../build; qmake qmake.pro
	-@make -C ../build
	-@cd ../build; rm -rf *.c *.h *.cpp *.ui *.pro *.o Makefile

uninstall:
	rm -rf ../build/*

dvi:
	@open ./manual/manual.html || echo "Please, install application first!"

dist:
	tar -cvf ./calc.tar .
	mv calc.tar ../build

#### GCOV && TEST #####
gcov_report:
	gcc s21calc.c test.c -lcheck --coverage -o test
	-./test
	lcov -t "test" -o calculate.info -c -d .
	genhtml -o report calculate.info
	open ./report/index.html

tests:
	gcc s21calc.c test.c -o test -lcheck
	./test

clean:
	rm -rf *.gcda *.gcno *.gcov *.info *.o *.out *.a *.tar
	rm -rf ./report ../build calc.tar
	rm -rf test

check:
	cp ../../materials/linters/CPPLINT.cfg .
	python3 ../../materials/linters/cpplint.py --filter=-runtime/references --extensions=c *.c
	rm -f CPPLINT.cfg
