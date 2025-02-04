#include "s21_string.h"

#include <stdlib.h>

int s21_strlen(const char *str) {
    int len = 0;
    while ((str) && (*str != '\0')) {
        len++;
        str++;
    }
    return len;
}

int s21_strcmp(const char *str1, const char *str2) {
    if (!str1 && !str2) {
        return 0;
    } else if (!str1) {
        return -1;
    } else if (!str2) {
        return 1;
    }

    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
        }
        str1++;
        str2++;
    }
    if (*str1 == '\0' && *str2 == '\0') {
        return 0;
    } else if (*str1 == '\0') {
        return -1;
    } else {
        return 1;
    }
}

char *s21_strcpy(char *dest, const char *src) {
    if (!dest || !src) {
        return NULL;
    }

    int length = s21_strlen(src) + 1;

    for (int ind = 0; ind < length; ind++) {
        dest[ind] = src[ind];
    }

    return dest;
}

char *s21_strcat(char *dest, char *src) {
    if (!dest && !src) {
        return NULL;
    }
    if (!dest) {
        return src;
    }
    if (!src) {
        return dest;
    }
    int length1 = s21_strlen(dest);
    int length2 = s21_strlen(src) + 1;

    for (int ind = 0; ind < length2; ind++) {
        dest[length1 + ind] = src[ind];
    }

    return dest;
}

char *s21_strchr(const char *str, int c) {
    while (*str != '\0') {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }
    if (c == '\0') {
        return (char *)str;
    }
    return 0;
}

char *s21_strstr(const char *haystack, const char *needle) {
    if (*needle == '\0') {
        return (char *)haystack;
    }

    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        while (*h == *n && *h != '\0' && *n != '\0') {
            h++;
            n++;
        }

        if (*n == '\0') {
            return (char *)haystack;
        }

        haystack++;
    }

    return 0;
}

char *s21_strtok(char *str, const char *delim) {
    static char *last_pos = NULL;
    if (str == NULL) {
        str = last_pos;
    }

    if (str == NULL) {
        return NULL;
    }

    char *start = str;
    while (*start != '\0' && s21_strchr(delim, *start) != NULL) {
        start++;
    }

    if (*start == '\0') {
        last_pos = NULL;
        return NULL;
    }

    char *end = start;
    while (*end != '\0' && s21_strchr(delim, *end) == NULL) {
        end++;
    }

    char *result = start;
    if (*end != '\0') {
        *end = '\0';
        last_pos = end + 1;
    } else {
        last_pos = NULL;
    }

    return result;
}