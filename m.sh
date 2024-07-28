#!/bin/bash
file_name=$1

# Export the file name as an environment variable to be used in the Makefile
export file_name

# Run make and suppress the "Nothing to be done for `all'" message
make > make_output.txt 2>&1
if grep -q "Nothing to be done for \`all'" make_output.txt; then
    rm make_output.txt
else
    cat make_output.txt
    rm make_output.txt
fi

if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

./practice
