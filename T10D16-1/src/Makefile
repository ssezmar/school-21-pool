CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

all:
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -D Q1 -D Q2 -D Q3 -D Q4 -D Q5 -D Q6 -D Q7 -o ../build/Test_string_h

clean:
	rm -rf ../build

rebuild:
	rm -f ../build/Test_string_h
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -D Q1 -D Q2 -D Q3 -D Q4 -D Q5 -D Q6 -D Q7 -o ../build/Test_string_h

rebuild_all_tests: strlen_tests_rebuild strcmp_tests_rebuild strcpy_tests_rebuild strcat_tests_rebuild strchr_tests_rebuild strstr_tests_rebuild strtok_tests_rebuild

strlen_tests:
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -D Q1 -o ../build/Quest_1
strlen_tests_clean:
	rm -f ../build/Quest_1
strlen_tests_rebuild: strlen_tests_clean strlen_tests
strlen_tests_run: strlen_tests_rebuild 
	../build/Quest_1

strcmp_tests:
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -D Q2 -o ../build/Quest_2
strcmp_tests_clean:
	rm -f ../build/Quest_2
strcmp_tests_rebuild: strcmp_tests_clean strcmp_tests
strcmp_tests_run: strcmp_tests_rebuild
	../build/Quest_2

strcpy_tests:
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -D Q3 -o ../build/Quest_3
strcpy_tests_clean:
	rm -f ../build/Quest_3
strcpy_tests_rebuild: strcpy_tests_clean strcpy_tests
strcpy_tests_run: strcpy_tests_rebuild
	../build/Quest_3

strcat_tests:
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -D Q4 -o ../build/Quest_4
strcat_tests_clean:
	rm -f ../build/Quest_4
strcat_tests_rebuild: strcat_tests_clean strcat_tests
strcat_tests_run: strcat_tests_rebuild 
	../build/Quest_4

strchr_tests:
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -D Q5 -o ../build/Quest_5
strchr_tests_clean:
	rm -f ../build/Quest_5
strchr_tests_rebuild: strchr_tests_clean strchr_tests
strchr_tests_run: strchr_tests_rebuild 
	../build/Quest_5

strstr_tests:
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -D Q6 -o ../build/Quest_6
strstr_tests_clean:
	rm -f ../build/Quest_6
strstr_tests_rebuild: strstr_tests_clean strstr_tests
strstr_tests_run: strstr_tests_rebuild 
	../build/Quest_6

strtok_tests:
	$(CC) $(CFLAGS) s21_string.c s21_string_test.c -D Q7 -o ../build/Quest_7
strtok_tests_clean:
	rm -f ../build/Quest_7
strtok_tests_rebuild: strtok_tests_clean strtok_tests
strtok_tests_run: strtok_tests_rebuild 
	../build/Quest_7

text_processor:
	$(CC) $(CFLAGS) text_processor.c s21_string.c -o ../build/Quest_8
	../build/Quest_8 -w


build:
	mkdir -p ../build
	make strlen_tests_rebuild strcmp_tests_rebuild strcpy_tests_rebuild strcat_tests_rebuild strchr_tests_rebuild strstr_tests_rebuild strtok_tests_rebuild




.PHONY: all strlen_tests clean