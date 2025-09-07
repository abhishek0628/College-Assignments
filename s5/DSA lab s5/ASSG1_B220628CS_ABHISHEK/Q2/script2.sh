#!/bin/zsh

# This script will compile and run C code, and test the output against expected output

numberOfFiles=$2

declare -i passed=0

gcc $1 -lm

if [ $? -eq 0 ]; then                                      # If compilation was successful
    echo -e "\033[38;5;22mCompilation successful\033[0m"   # Print in green
else
    echo -e "\033[31mCompilation failed\033[0m"            # Print in red
    exit 1
fi

for ((i = 1; i <= $numberOfFiles; i++)); do
    timeout 2s "./a.out" <"./in$i.txt" > "./output$i.txt"

    returnStatus=$?

    if [ $returnStatus -eq 0 ]; then                       # Checking execution return status
        echo -e "\033[38;5;22mExecution successful for TC $i\033[0m"
    else
        echo -e "\033[31mExecution failed for TC $i\033[0m"
        continue
    fi

    diff -q -Z "./out$i.txt" "./output$i.txt"              # -q => Single line output, whether files match or differ

    if [ $? -eq 0 ]; then
        passed=$((passed + 1))
        echo -e "\033[38;5;22mTest passed for TC $i\033[0m"
    else
        echo -e "\033[31mTest failed for TC $i \033[0m"
        diff -Z -y --color "./out$i.txt" "./output$i.txt"  # Print differences if any
                                                           # -y => Side-by-side output
                                                           # -Z => Ignores trailing spaces
                                                           # -B => Ignores blank lines (if needed)
        echo " "
    fi
done

echo -e "\033[1;42;30mPassed $passed/$2 test cases\033[0m"

exit 0
