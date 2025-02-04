#include <math.h>
#include <stdio.h>
#include <string.h>

#include "binary.h"
#include "data.h"
#include "get_string.h"

char *input_filepath();
int check_date(Data etalon);
int find_code(const char *filepath, Data etalon);
int cmp(Data record, Data etalon);
Data init_struct();

void print_date(Data record);

int main() {
    int exit = -100;
    char *filepath = NULL;

    if (exit != -100)
        while (getchar() != '\n')
            ;
    exit = 1;
    filepath = input_filepath();
    if (strcmp(filepath, "../-1") == 0)
        exit = -1;
    else {
        Data etalon = init_struct();
        if (scanf("%d.%d.%d", &etalon.day, &etalon.month, &etalon.year) != 3) exit = 0;

        if (check_date(etalon) == 0) exit = 0;

        int code = find_code(filepath, etalon);
        if (code == -1) exit = 0;
        if (exit)
            printf("%d", code);
        else
            printf("n/a");
    }

    free(filepath);

    return 0;
}

void print_date(Data record) { printf("%d.%d.%d\n", record.day, record.month, record.year); }

int check_date(Data etalon) {
    int result = 1;
    if (!(etalon.day >= 0 && etalon.day <= 31)) result = 0;
    if (!(etalon.month >= 0 && etalon.month <= 12)) result = 0;
    if (!(etalon.year >= 0 && etalon.year <= 9999)) result = 0;

    return result;
}

int find_code(const char *filepath, Data etalon) {
    int code = -1;
    FILE *pfile = fopen(filepath, "r");
    if (pfile != NULL) {
        for (int i = 0; i < get_records_count_in_file(pfile) && code == -1; i++) {
            Data temp = read_record_from_file(pfile, i);
            if (cmp(temp, etalon)) code = temp.code;
        }
        fclose(pfile);
    }

    return code;
}

int cmp(Data record, Data etalon) {
    int result = 1;
    if (record.year != etalon.year) result = 0;
    if (record.month != etalon.month) result = 0;
    if (record.day != etalon.day) result = 0;

    return result;
}

Data init_struct() {
    Data res;
    res.year = 0;
    res.month = 0;
    res.day = 0;
    res.hour = 0;
    res.minute = 0;
    res.seconds = 0;
    res.status = 0;
    res.code = 0;

    return res;
}
