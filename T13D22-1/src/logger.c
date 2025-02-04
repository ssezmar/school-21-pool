#include "logger.h"

FILE *log_init(const char *log_file) {
    FILE *file = fopen(log_file, "a");
    if (file == NULL) {
        perror("Failed to open log file");
    }
    return file;
}

void logcat(FILE *log_file, LogLevel level, const char *message) {
    if (log_file == NULL) {
        return;
    }

    const char *level_str;
    switch (level) {
        case DEBUG:
            level_str = "DEBUG";
            break;
        case INFO:
            level_str = "INFO";
            break;
        case WARNING:
            level_str = "WARNING";
            break;
        case ERROR:
            level_str = "ERROR";
            break;
        default:
            level_str = "UNKNOWN";
            break;
    }

    time_t now = time(NULL);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&now));

    fprintf(log_file, "[%s] [%s] %s\n", level_str, time_str, message);
    fflush(log_file);
}

void log_close(FILE *log_file) {
    if (log_file != NULL) {
        fclose(log_file);
    }
}