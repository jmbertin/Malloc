#!/bin/bash

cd ..
make re > /dev/null
cp libmalloc_x86_64_Linux.so tests/
cd tests

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

run_test() {
    local test_number=$1
    local is_custom=$2
    local label="Mandatory"

    if [[ "$is_custom" == "true" ]]; then
        label="custom tests"
    fi

    echo -e "Test ${test_number}: ${label}"

    gcc "test${test_number}.c" -L. -lmalloc_x86_64_Linux -o test_program 2> /dev/null

    if [[ $? -ne 0 ]]; then
        echo -e "${RED}Compilation failed${NC}"
        return
    fi

    export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
    ./test_program > "test${test_number}_result.txt"

    if [[ "$is_custom" == "false" ]]; then
        diff "test${test_number}_result.txt" "expected_results/test${test_number}.txt" > "test${test_number}_diff.txt"

        if [[ -s "test${test_number}_diff.txt" ]]; then
            echo -e "${RED}DIFF KO${NC}"
			echo "!!! Normal on test 4 and 6, memory adresses could be different !!!"
			cat test${test_number}_diff.txt
        else
            echo -e "${GREEN}DIFF OK${NC}"
        fi
    fi

    echo -e "------------------------------------------------------------------"
}

# Test 0
run_test 0 false

# Test 1
run_test 1 false

# Test 2
run_test 2 false

# Test 3
run_test 3 false

# Test 4
run_test 4 false

# Test 5
run_test 5 false

# Test 6 (custom test)
run_test 6 false

# Cleaning
echo "Cleaning..."
rm libmalloc_x86_64_Linux.so
cd ..
make fclean > /dev/null
cd tests
rm test_program
rm *.txt
