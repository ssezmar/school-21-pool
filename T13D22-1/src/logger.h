#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <time.h>

typedef enum { DEBUG, INFO, WARNING, ERROR } LogLevel;

FILE *log_init(const char *log_file);
void logcat(FILE *log_file, LogLevel level, const char *message);
void log_close(FILE *log_file);

#endif