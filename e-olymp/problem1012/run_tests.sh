#!/bin/bash

TEST_DIR=tests
TESTS=$(ls $TEST_DIR | grep -v ".a" | sed "s/^/$TEST_DIR\//")

RED="\033[31m"
GREEN="\033[32m"
BLUE="\033[34m"
YELLOW="\033[1;33m"
RESET="\033[0m"

RUN_CMD=""
if [[ $1 == *".py" ]]; then
    RUN_CMD="python"
fi

for test in $TESTS; do
    result=$($RUN_CMD $1 <$test)
    if [[ $result -eq $(<$test.a) ]]; then
        echo -e ${GREEN}OK${RESET} $test
    else
        echo -e ${RED}FAIL${RESET} $test
    fi
done
