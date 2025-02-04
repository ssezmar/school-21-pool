#!/bin/bash

# Check count of arguments
if [ "$#" -ne 3 ]; then
    echo "Использование: $0 <путь_до_файла> <строка_для_замены> <замена>"
    exit 1
fi

file_path="$1"
search_string="$2"
replace_string="$3"
log_file="src/files.log"

# Check files
if [ ! -f "$file_path" ]; then
    echo "Ошибка: Файл '$file_path' не найден."
    exit 1
fi

# Check to none string
if [ -z "$search_string" ]; then
    echo "Ошибка: Строка для замены не может быть пустой."
    exit 1
fi

# Replace substrings in files
if grep -q "$search_string" "$file_path"; then

    # Replace
    sed -i "s/$search_string/$replace_string/g" "$file_path"

    size=$(stat -c%s "$file_path")
    datetime=$( date +%F' '%R )
    sha_sum=$(sha256sum "$file_path" | awk '{ print $1 }')

    # Writing log

    echo "$file_path — $size — $datetime — $sha_sum — sha256" >> $log_file

    echo "Замена выполнена."
else
    echo "Строка '$search_string' не найдена в файле '$file_path'."
fi