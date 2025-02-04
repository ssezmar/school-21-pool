#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary.h"
#include "data.h"
#include "get_string.h"

void menu(int choice, char *filepath);
void print_struct(Data record);
void ouput_file(const char *filepath);
void sort_data(const char *filepath);
void add_to_file(const char *filepath);
int cmp(Data record_1, Data record_2);
void sort(FILE *pfile);
Data input_struct();

int main() {
    int ch = -100;
    char *filepath = NULL;

    if (ch != -100)
        while (getchar() != '\n')
            ;
    ch = 1;

    filepath = input_filepath();
    if (strcmp(filepath, "../-1") != 0) {
        if (strlen(filepath) == 0) {
            printf("n/a");
            exit(1);
            free(filepath);
        }

        if (scanf("%d", &ch) != 1) {
            printf("n/a");
            exit(1);
            free(filepath);
            while (getchar() != '\n')
                ;
            ch = 0;
        } else if (ch != -1) {
            menu(ch, filepath);
        }
    } else {
        ch = -1;
    }

    free(filepath);

    return 0;
}

void menu(int choice, char *filepath) {
    switch (choice) {
        case 0:
            ouput_file(filepath);
            break;
        case 1:
            sort_data(filepath);
            break;
        case 2:
            add_to_file(filepath);
            break;
        default:
            printf("n/a");
            exit(1);
    }
}

void print_struct(Data record) {
    printf("%d %d %d %d %d %d %d %d\n", record.year, record.month, record.day, record.hour, record.minute,
           record.seconds, record.status, record.code);
}

void ouput_file(const char *filepath) {
    FILE *pfile = fopen(filepath, "rb");
    if (pfile == NULL) {
        printf("n/a");
        exit(1);
    } else {
        int quantity = get_records_count_in_file(pfile);
        printf("%d", quantity);
        for (int i = 0; i < quantity; i++) {
            Data temp = read_record_from_file(pfile, i);
            print_struct(temp);
        }
        fclose(pfile);
    }
}

void sort_data(const char *filepath) {
    FILE *pfile = fopen(filepath, "rb+");
    if (pfile == NULL) {
        printf("n/a");
        exit(1);
    } else {
        sort(pfile);
        fclose(pfile);
        ouput_file(filepath);
    }
}

int cmp(Data record_1, Data record_2) {
    if (record_1.year != record_2.year) {
        return record_1.year - record_2.year;
    }
    if (record_1.month != record_2.month) {
        return record_1.month - record_2.month;
    }
    if (record_1.day != record_2.day) {
        return record_1.day - record_2.day;
    }
    if (record_1.hour != record_2.hour) {
        return record_1.hour - record_2.hour;
    }
    if (record_1.minute != record_2.minute) {
        return record_1.minute - record_2.minute;
    }
    return record_1.seconds - record_2.seconds;
}

void sort(FILE *pfile) {
    int size = get_records_count_in_file(pfile);
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            Data rec_1 = read_record_from_file(pfile, j);
            Data rec_2 = read_record_from_file(pfile, j + 1);

            if (cmp(rec_1, rec_2) > 0) {
                swap_records_in_file(pfile, j, j + 1);
            }
        }
    }
}

void add_to_file(const char *filepath) {
    FILE *pfile = fopen(filepath, "rb+");
    if (pfile == NULL) {
        printf("n/a");
        exit(1);
    } else {
        int flag = 1;
        Data record_to_write = input_struct(&flag);
        if (flag) {
            write_record_in_file(pfile, &record_to_write, get_records_count_in_file(pfile));
            sort(pfile);
            fclose(pfile);
            ouput_file(filepath);
        } else {
            printf("n/a");
            exit(1);
        }
    }
}

Data input_struct(int *flag) {
    Data temp;
    if (scanf("%d", &temp.year) != 1) *flag = 0;
    if (scanf("%d", &temp.month) != 1) *flag = 0;
    if (scanf("%d", &temp.day) != 1) *flag = 0;
    if (scanf("%d", &temp.hour) != 1) *flag = 0;
    if (scanf("%d", &temp.minute) != 1) *flag = 0;
    if (scanf("%d", &temp.seconds) != 1) *flag = 0;
    if (scanf("%d", &temp.status) != 1) *flag = 0;
    if (scanf("%d", &temp.code) != 1) *flag = 0;
    if (!flag) {
        printf("n/a");
        exit(1);
    }

    return temp;
}
