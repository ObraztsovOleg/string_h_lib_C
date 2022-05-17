SRC_DIR := ./
TEST_SRC_DIR := ./test/

LIB_SRC = $(shell find $(SRC_DIR) -maxdepth 1 -name 's21*.c')
LIB_OBJ := $(LIB_SRC:.c=.o)

TEST_SRC = $(shell find $(TEST_SRC_DIR) -maxdepth 1 -name 's21*.c')
TEST_OBJ := $(TEST_SRC:.c=.o)
OS := $(shell uname -s)

CFLAGS := -c -Wall -Wextra -Wall -std=c11
GCOV_CFLAGS := -fprofile-arcs -ftest-coverage -fPIC


ifeq ($(OS), Linux)
    LFLAGS := -lm -lrt -lpthread -lsubunit -lcheck $(shell pkg-config --libs check)  # <--- unix
else
    LFLAGS =  -lcheck $(shell pkg-config --libs check)                               # <--- macOs
endif

GCOV_LFLAGS := --coverage

TEST_CFLAGS += $(GCOV_CFLAGS)
TEST_CFLAGS += $(CFLAGS)

TEST_LFLAGS += $(GCOV_LFLAGS)
TEST_LFLAGS += $(LFLAGS)

LIB_CFLAGS += $(CFLAGS)

LIB_LFLAGS += $(LFLAGS)

CC := gcc
COV := gcovr

all: s21_string.a test
 
test: $(TEST_OBJ) main.o $(LIB_OBJ)
	$(CC) $(TEST_OBJ) main.o $(LIB_OBJ) $(TEST_LFLAGS) -o s21_string

$(TEST_OBJ): %.o: %.c
	$(CC) $(CFLAGS) $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) $< -o $@

$(LIB_OBJ): %.o: %.c
	$(CC) $(TEST_CFLAGS) $< -o $@

gcov_report:
	-@mkdir ./html_report
	$(COV) -r . --html --html-details -o ./html_report/coverage_report.html

s21_string.a:
	$(CC) $(LIB_CFLAGS) $(LIB_SRC)
	ar rc s21_string.a $(LIB_OBJ)
	ranlib s21_string.a

clean:
	rm -rf *.o a.out \
	*.html           \
	*.css            \
	*.gcno           \
	*.gcda           \
	*.a              \
	./test/*.o	     \
	./test/*.gcda    \
	./test/*.gcno    \
	./log.txt        \
	s21_string

.PHONY: all          \
		clean        \
		test         \
		s21_string.a \
		gcov_report
