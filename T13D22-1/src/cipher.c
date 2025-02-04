#include <ctype.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "logger.h"

#define MAX_COMMANDS 100

typedef struct {
    int command;
    char file_path[256];
    char text[256];
    int shift;
    char dir_path[256];
} Command;

void print_file_content(const char *file_path, FILE *log_file);
void append_text_to_file(const char *file_path, const char *text, FILE *log_file);
void caesar_cipher_file(const char *file_path, int shift, FILE *log_file);
void clear_file(const char *file_path, FILE *log_file);
void process_directory(const char *dir_path, int shift, FILE *log_file);

int main() {
    Command commands[MAX_COMMANDS];
    int command_count = 0;
    char input[256];
    int valid_sequence = 1;

    FILE *log_file = log_init("program.log");
    if (log_file == NULL) {
        return 1;
    }

    while (1) {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("n/a");
            fflush(stdout);
            logcat(log_file, ERROR, "Failed to read input");
            log_close(log_file);
            return 1;
        }

        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "-1") == 0) {
            break;
        }

        if (strcmp(input, "1") == 0) {
            if (fgets(input, sizeof(input), stdin) == NULL) {
                printf("n/a");
                fflush(stdout);
                logcat(log_file, ERROR, "Failed to read file path");
                log_close(log_file);
                return 1;
            }

            input[strcspn(input, "\n")] = 0;

            if (strlen(input) == 0) {
                printf("n/a");
                fflush(stdout);
                logcat(log_file, WARNING, "Empty file path");
                log_close(log_file);
                return 1;
            }

            if (command_count < MAX_COMMANDS) {
                commands[command_count].command = 1;
                strncpy(commands[command_count].file_path, input,
                        sizeof(commands[command_count].file_path) - 1);
                commands[command_count].file_path[sizeof(commands[command_count].file_path) - 1] = '\0';
                command_count++;
                logcat(log_file, INFO, "File path added");
            } else {
                printf("n/a");
                fflush(stdout);
                logcat(log_file, ERROR, "Command limit reached");
                log_close(log_file);
                return 1;
            }
        } else if (strcmp(input, "2") == 0) {
            if (command_count == 0 || commands[command_count - 1].command != 1) {
                valid_sequence = 0;
            }

            if (fgets(input, sizeof(input), stdin) == NULL) {
                printf("n/a");
                fflush(stdout);
                logcat(log_file, ERROR, "Failed to read text");
                log_close(log_file);
                return 1;
            }

            input[strcspn(input, "\n")] = 0;

            if (strlen(input) == 0) {
                printf("n/a");
                fflush(stdout);
                logcat(log_file, WARNING, "Empty text");
                log_close(log_file);
                return 1;
            }

            if (command_count < MAX_COMMANDS) {
                commands[command_count].command = 2;
                strncpy(commands[command_count].text, input, sizeof(commands[command_count].text) - 1);
                commands[command_count].text[sizeof(commands[command_count].text) - 1] = '\0';
                command_count++;
                logcat(log_file, INFO, "Text added");
            } else {
                printf("n/a");
                fflush(stdout);
                logcat(log_file, ERROR, "Command limit reached");
                log_close(log_file);
                return 1;
            }
        } else if (strcmp(input, "3") == 0) {
            if (fgets(input, sizeof(input), stdin) == NULL) {
                printf("n/a");
                fflush(stdout);
                logcat(log_file, ERROR, "Failed to read shift value");
                log_close(log_file);
                return 1;
            }

            input[strcspn(input, "\n")] = 0;

            if (strlen(input) == 0) {
                printf("n/a");
                fflush(stdout);
                logcat(log_file, WARNING, "Empty shift value");
                log_close(log_file);
                return 1;
            }

            int shift = atoi(input);

            if (fgets(input, sizeof(input), stdin) == NULL) {
                printf("n/a");
                fflush(stdout);
                logcat(log_file, ERROR, "Failed to read directory path");
                log_close(log_file);
                return 1;
            }

            input[strcspn(input, "\n")] = 0;

            if (strlen(input) == 0) {
                printf("n/a");
                fflush(stdout);
                logcat(log_file, WARNING, "Empty directory path");
                log_close(log_file);
                return 1;
            }

            if (command_count < MAX_COMMANDS) {
                commands[command_count].command = 3;
                commands[command_count].shift = shift;
                strncpy(commands[command_count].dir_path, input,
                        sizeof(commands[command_count].dir_path) - 1);
                commands[command_count].dir_path[sizeof(commands[command_count].dir_path) - 1] = '\0';
                command_count++;
                logcat(log_file, INFO, "Directory path and shift value added");
            } else {
                printf("n/a");
                fflush(stdout);
                logcat(log_file, ERROR, "Command limit reached");
                log_close(log_file);
                return 1;
            }
        } else if (strcmp(input, "4") == 0) {
            input[strcspn(input, "\n")] = 0;

            int shift = 23;

            if (fgets(input, sizeof(input), stdin) == NULL) {
                printf("n/a");
                fflush(stdout);
                logcat(log_file, ERROR, "Failed to read directory path");
                log_close(log_file);
                return 1;
            }

            input[strcspn(input, "\n")] = 0;

            if (strlen(input) == 0) {
                printf("n/a");
                fflush(stdout);
                logcat(log_file, WARNING, "Empty directory path");
                log_close(log_file);
                return 1;
            }

            if (command_count < MAX_COMMANDS) {
                commands[command_count].command = 3;
                commands[command_count].shift = shift;
                strncpy(commands[command_count].dir_path, input,
                        sizeof(commands[command_count].dir_path) - 1);
                commands[command_count].dir_path[sizeof(commands[command_count].dir_path) - 1] = '\0';
                command_count++;
                logcat(log_file, INFO, "Directory path and shift value added");
            } else {
                printf("n/a");
                fflush(stdout);
                logcat(log_file, ERROR, "Command limit reached");
                log_close(log_file);
                return 1;
            }
        } else {
            printf("n/a");
            fflush(stdout);
            logcat(log_file, ERROR, "Invalid command");
            log_close(log_file);
            return 1;
        }
    }

    if (!valid_sequence) {
        printf("n/a\n");
        fflush(stdout);
        logcat(log_file, ERROR, "Invalid command sequence");
        log_close(log_file);
        return 1;
    }

    for (int i = 0; i < command_count; i++) {
        if (commands[i].command == 1) {
            print_file_content(commands[i].file_path, log_file);
            printf("\n");
            fflush(stdout);
        } else if (commands[i].command == 2) {
            append_text_to_file(commands[i - 1].file_path, commands[i].text, log_file);
            print_file_content(commands[i - 1].file_path, log_file);
            printf("\n");
            fflush(stdout);
        } else if (commands[i].command == 3) {
            process_directory(commands[i].dir_path, commands[i].shift, log_file);
        } else if (commands[i].command == 4) {
            process_directory(commands[i].dir_path, commands[i].shift, log_file);
        }
    }

    log_close(log_file);
    return 0;
}

void print_file_content(const char *file_path, FILE *log_file) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("n/a");
        fflush(stdout);
        logcat(log_file, ERROR, "Failed to open file");
        return;
    }

    logcat(log_file, INFO, "File opened");

    int ch;
    int is_empty = 1;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
        fflush(stdout);
        is_empty = 0;
    }

    if (is_empty) {
        printf("n/a");
        fflush(stdout);
        logcat(log_file, WARNING, "File is empty");
    }

    fclose(file);
    logcat(log_file, INFO, "File closed");
}

void append_text_to_file(const char *file_path, const char *text, FILE *log_file) {
    FILE *file = fopen(file_path, "a");
    if (file == NULL) {
        printf("n/a");
        fflush(stdout);
        logcat(log_file, ERROR, "Failed to open file for appending");
        return;
    }

    fprintf(file, "%s", text);
    fclose(file);
    logcat(log_file, INFO, "Text appended to file");
}

void caesar_cipher_file(const char *file_path, int shift, FILE *log_file) {
    FILE *file = fopen(file_path, "r+");
    if (file == NULL) {
        printf("n/a");
        fflush(stdout);
        logcat(log_file, ERROR, "Failed to open file for Caesar cipher");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(file_size + 1);
    if (buffer == NULL) {
        printf("n/a");
        fflush(stdout);
        logcat(log_file, ERROR, "Memory allocation failed");
        fclose(file);
        return;
    }

    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';

    for (long i = 0; i < file_size; i++) {
        if (isalpha(buffer[i])) {
            char base = islower(buffer[i]) ? 'a' : 'A';
            buffer[i] = (buffer[i] - base + shift) % 26 + base;
        }
    }

    fseek(file, 0, SEEK_SET);
    fwrite(buffer, 1, file_size, file);
    fclose(file);
    free(buffer);
    logcat(log_file, INFO, "File encrypted with Caesar cipher");
}

void clear_file(const char *file_path, FILE *log_file) {
    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        printf("n/a");
        fflush(stdout);
        logcat(log_file, ERROR, "Failed to open file for clearing");
        return;
    }
    fclose(file);
    logcat(log_file, INFO, "File cleared");
}

void process_directory(const char *dir_path, int shift, FILE *log_file) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        printf("n/a");
        fflush(stdout);
        logcat(log_file, ERROR, "Failed to open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        char file_path[512];
        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);

        struct stat path_stat;
        stat(file_path, &path_stat);

        if (S_ISREG(path_stat.st_mode)) {
            if (strstr(entry->d_name, ".c") != NULL) {
                caesar_cipher_file(file_path, shift, log_file);
            } else if (strstr(entry->d_name, ".h") != NULL) {
                clear_file(file_path, log_file);
            }
        }
    }

    closedir(dir);
    logcat(log_file, INFO, "Directory processed");
}