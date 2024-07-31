#!/bin/bash
file_name=$1

# Export the file name as an environment variable to be used in the Makefile
export file_name

# Run make and redirect output to a file
make > make_output.txt 2>&1

# Check the return status of the make command
if [ $? -ne 0 ]; then
    cat make_output.txt
    echo "Compilation failed"
    rm make_output.txt
    exit 1
fi

# If make was successful, check for the specific "Nothing to be done for `all'" message
if grep -q "Nothing to be done for \`all'" make_output.txt; then
    rm make_output.txt
else
    cat make_output.txt
    rm make_output.txt
fi

# Run the compiled program
./practice
