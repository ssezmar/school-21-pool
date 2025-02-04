#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Использование: $0 <путь_до_файла_лога>"
    exit 1
fi

log_file="$1"

if [ ! -f "$log_file" ]; then
    echo "Ошибка: Файл '$log_file' не найден."
    exit 1
fi

total_entries=0
unique_files=0
hash_changes=0

temp_files=$(mktemp)
temp_hashes=$(mktemp)

while IFS= read -r line; do
    total_entries=$((total_entries + 1))
    
    file=$(echo "$line" | awk '{print $1}')
    hash=$(echo "$line" | awk '{print $4}')

    echo "$file" >> "$temp_files"

    echo "$hash" >> "$temp_hashes"
done < "$log_file"

unique_files=$(sort -u "$temp_files" | wc -l)

hash_changes=$(sort "$temp_hashes" | uniq -u | wc -l)

rm "$temp_files" "$temp_hashes"

echo "$total_entries $unique_files $hash_changes"