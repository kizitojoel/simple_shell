#!/bin/bash

# Get a list of .c files in the current directory
c_files=(commands/*.c)

# Create an array for non-underscore files
non_underscore_files=()

# Separate the files based on underscore prefix
for file in "${c_files[@]}"; do
  if [[ ${file:0:10} != "commands/_" ]]; then
    non_underscore_files+=("$file")
  fi
done

# Compile each non_underscore file together with all underscore files
for file in "${non_underscore_files[@]}"; do
  filename=$(basename "$file" .c)
  echo "$filename"
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 commands/_*.c "$file" -o "$filename"
done
