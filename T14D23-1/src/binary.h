#ifndef BINARY_H
#define BINARY_H

#include "data.h"

// Функция для чтения записи заданного типа из файла по её порядковому номеру.
struct Data read_record_from_file(FILE *pfile, int index) {
    // Вычисление смещения, на котором должна находиться нужная запись от начала файла.
    int offset = index * sizeof(struct Data);
    // Перемещение указателя позиции на вычисленное смещение от начала файла.
    fseek(pfile, offset, SEEK_SET);

    // Чтение записи указанного типа из файла.
    struct Data record;
    fread(&record, sizeof(struct Data), 1, pfile);

    // В целях безопасности возвращаем указатель позиции файла в начало файла.
    rewind(pfile);

    // Возвращаем прочитанную запись
    return record;
}

// Функция для записи записи указанного типа в файл по заданному порядковому номеру.
void write_record_in_file(FILE *pfile, const struct Data *record_to_write, int index) {
    // Вычисление смещения, на котором должна находиться нужная запись от начала файла.
    int offset = index * sizeof(struct Data);
    // Перемещение указателя позиции на вычисленное смещение от начала файла.
    fseek(pfile, offset, SEEK_SET);

    // Запись записи указанного типа в файл.
    fwrite(record_to_write, sizeof(struct Data), 1, pfile);

    // На всякий случай принудительно заставляем подсистему ввода-вывода записать содержимое своего буфера в
    // файл прямо сейчас.
    fflush(pfile);

    // В целях безопасности возвращаем указатель позиции файла в начало файла.
    rewind(pfile);
}

// Функция для взаимного обмена двух записей в файле по их индексам.
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    // Читаем обе записи из файла в переменные
    struct Data record1 = read_record_from_file(pfile, record_index1);
    struct Data record2 = read_record_from_file(pfile, record_index2);

    // Перезаписываем записи в файле
    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}

// Функция для получения размера файла в байтах.
int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);  // Перемещение указателя позиции в конец файла.
    size = ftell(pfile);  // Чтение количества байт от начала файла до текущего указателя позиции.
    rewind(pfile);  // В целях безопасности перемещаем указатель позиции обратно в начало файла.
    return size;
}

// Функция для получения количества записей в файле
int get_records_count_in_file(FILE *pfile) { return get_file_size_in_bytes(pfile) / sizeof(struct Data); }

#endif
