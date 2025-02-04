#include "s21_string.h"

#include <stdio.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();
void s21_strtok_test();

int main() {
#ifdef Q1
    printf("*************Testing s21_strlen*************\n");
    s21_strlen_test();
#endif
#ifdef Q2
    printf("*************Testing s21_strcmp*************\n");
    s21_strcmp_test();
#endif
#ifdef Q3
    printf("*************Testing s21_strcpy*************\n");
    s21_strcpy_test();
#endif
#ifdef Q4
    printf("*************Testing s21_strcat*************\n");
    s21_strcat_test();
#endif
#ifdef Q5
    printf("*************Testing s21_strch*************\n");
    s21_strchr_test();
#endif
#ifdef Q6
    printf("*************Testing s21_strstr*************\n");
    s21_strstr_test();
#endif
#ifdef Q7
    printf("*************Testing s21_strtok*************\n");
    s21_strtok_test();
#endif
    return 0;
}

void s21_strlen_test() {
    printf("Test1\nInput: str = \"Hello, world!\", Expected: 13, Actual: %d, Test: %s",
           s21_strlen("Hello, world!"), s21_strlen("Hello, world!") == 13 ? "SUCCESS" : "FAIL");

    printf("Test2\nInput: str = NULL, Expected: 0, Actual: %d, Test: %s", s21_strlen(NULL),
           s21_strlen(NULL) == 0 ? "SUCCESS" : "FAIL");

    printf("Test3\nInput: str = \"\", Expected: 0, Actual: %d, Test: %s", s21_strlen(""),
           s21_strlen("") == 0 ? "SUCCESS" : "FAIL");
}

void s21_strcmp_test() {
    printf("Test1\nInput: s1 = \"Hello\", s2 = \"World\", Expected: < 0, Actual: %d, Test: %s",
           s21_strcmp("Hello", "World"), s21_strcmp("Hello", "World") < 0 ? "SUCCESS" : "FAIL");

    printf("Test2\nInput: s1 = NULL, s2 = \"World\", Expected: != 0, Actual: %d, Test: %s",
           s21_strcmp(NULL, "World"), s21_strcmp(NULL, "World") != 0 ? "SUCCESS" : "FAIL");

    printf("Test3\nInput: s1 = \"Hello\", s2 = \"Hello\", Expected: 0, Actual: %d, Test: %s",
           s21_strcmp("Hello", "Hello"), s21_strcmp("Hello", "Hello") == 0 ? "SUCCESS" : "FAIL");
}

void s21_strcpy_test() {
    char dest1[13] = {0};
    printf(
        "Test1\nInput: dest = \"%s\", src = \"Hello, world!\", Expected: \"Hello, world!\", Actual: \"%s\", "
        "Test: %s",
        dest1, s21_strcpy(dest1, "Hello, world!"), s21_strcmp(dest1, "Hello, world!") ? "SUCCESS" : "FAIL");
    char *dest2 = NULL;
    printf("Test2\nInput: dest = \"%s\", src = \"Hello, world!\", Expected: NULL, Actual: \"%s\", Test: %s",
           dest2, s21_strcpy(dest2, "Hello, world!"), dest2 == NULL ? "SUCCESS" : "FAIL");

    char dest3[1] = {0};
    printf("Test3\nInput: dest = \"%s\", src = \"\", Expected: \"\", Actual: \"%s\", Test: %s", dest3,
           s21_strcpy(dest3, ""), s21_strcmp(dest3, "") == 0 ? "SUCCESS" : "FAIL");
}

void s21_strcat_test() {
    char dest1[20] = "Hello, ";
    printf("Test1\nInput: dest = \"%s\"", dest1);
    printf(", src = \"world!\", Expected: \"Hello, world!\", Actual: \"%s\", Test: %s",
           s21_strcat(dest1, "world!"), s21_strcmp(dest1, "Hello, world!") == 0 ? "SUCCESS" : "FAIL");

    char *dest2 = NULL;
    printf("Test2\nInput: dest = NULL, src = \"world!\", Expected: NULL, Actual: \"%s\", Test: %s",
           s21_strcat(dest2, "world!"), dest2 == NULL ? "SUCCESS" : "FAIL");

    char dest3[1] = "";
    printf("Test3\nInput: dest = \"\", src = \"\", Expected: \"\", Actual: \"%s\", Test: %s",
           s21_strcat(dest3, ""), s21_strcmp(dest3, "") == 0 ? "SUCCESS" : "FAIL");
}

void s21_strchr_test() {
    char str1[] = "Hello, world!";
    char *result1 = s21_strchr(str1, 'o');
    printf("Test1\nInput: str = \"%s\", c = 'o', Expected: \"%s\", Actual: \"%s\", Test: %s", str1, result1,
           s21_strchr(str1, 'o'), result1 == s21_strchr(str1, 'o') ? "SUCCESS" : "FAIL");

    char str2[] = "";
    char *result2 = s21_strchr(str2, 'a');
    printf("Test2\nInput: str = \"%s\", c = 'a', Expected: \"%s\", Actual: \"%s\", Test: %s", str2, result2,
           s21_strchr(str2, 'a'), result2 == s21_strchr(str2, 'a') ? "SUCCESS" : "FAIL");

    char str3[] = "a";
    char *result3 = s21_strchr(str3, 'a');
    printf("Test3\nInput: str = \"%s\", c = 'a', Expected: \"%s\", Actual: \"%s\", Test: %s", str3, result3,
           s21_strchr(str3, 'a'), result3 == s21_strchr(str3, 'a') ? "SUCCESS" : "FAIL");
}

void s21_strstr_test() {
    char str1[] = "Hello, world!";
    char *result1 = s21_strstr(str1, "world");
    printf("Test1\nInput: haystack = \"%s\", needle = \"world\", Expected: \"%s\", Actual: \"%s\", Test: %s",
           str1, result1, s21_strstr(str1, "world"),
           result1 == s21_strstr(str1, "world") ? "SUCCESS" : "FAIL");

    char str2[] = "";
    char *result2 = s21_strstr(str2, "a");
    printf("Test2\nInput: haystack = \"%s\", needle = \"a\", Expected: \"%s\", Actual: \"%s\", Test: %s",
           str2, "NULL", s21_strstr(str2, "a"), result2 == NULL ? "SUCCESS" : "FAIL");

    char str3[] = "a";
    char *result3 = s21_strstr(str3, "a");
    printf("Test3\nInput: haystack = \"%s\", needle = \"a\", Expected: \"%s\", Actual: \"%s\", Test: %s",
           str3, "a", s21_strstr(str3, "a"), result3 == s21_strstr(str3, "a") ? "SUCCESS" : "FAIL");
}

void s21_strtok_test() {
    char str1[] = "Hello, world! How are you?";
    char *delim1 = " ,";
    char *result1 = s21_strtok(str1, delim1);
    printf("Test1\nInput: str = \"%s\"", str1);
    printf(", delim = \"%s\", Expected: \"%s\", Actual: \"%s\", Test: %s", delim1, result1,
           s21_strtok(str1, delim1), result1 == s21_strtok(str1, delim1) ? "SUCCESS" : "FAIL");

    char *str2 = NULL;
    char *delim2 = " ,";
    printf("Test2\nInput: str = \"%s\"", str2);
    char *result2 = s21_strtok(str2, delim2);
    printf(", delim = \"%s\", Expected: NULL, Actual: %p, Test: %s", delim2, result2,
           result2 == NULL ? "SUCCESS" : "FAIL");

    char str3[] = "";
    char *delim3 = " ,";
    char *result3 = NULL;
    printf("Test3\nInput: str = \"%s\"", str3);
    printf(", delim = \"%s\", Expected: NULL, Actual: %p, Test: %s", delim3, result3,
           result3 == NULL ? "SUCCESS" : "FAIL");
}