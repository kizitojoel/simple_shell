#!/bin/bash

for file in commands/*.c; do
    # Get the file name without extension
    filename=$(basename "$file" .c)

    # Compile the C file and generate an executable
    gcc -o "$filename" "$file"
done
