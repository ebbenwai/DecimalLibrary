CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

OS = $(shell uname)

ifeq ($(OS),Linux)
    det_OS = -lcheck  -lm -lrt -lpthread -lsubunit
else
    det_OS = -lcheck -lm -lpthread
endif

all : clean s21_decimal.a test gcov_report

test: 
	$(CC) $(CFLAGS) --coverage all*.c test.c -o test $(det_OS)

s21_decimal.o: all*.c s21*.h
	$(CC) $(CFLAGS) all*.c  -c 

s21_decimal.a : s21_decimal.o
	ar rcs s21_decimal.a *.o
	ranlib s21_decimal.a

gcov_report: test
	./test
	lcov -t "result" -o res.info -c -d .
	genhtml -o report res.info
	open report/index.html

check:
	cp ../materials/linters/.clang-format ./
	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -i *.c *.h
	
	rm .clang-format

clean:
	rm -rf report *.gc* *.o *.info *.a test.dSYM test
	
rebuild: clean all

