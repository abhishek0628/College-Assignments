#!/bin/bash

# This script will compile and run c code, and test the output against expected output

numberOfFiles=$2

declare -i passed=0

gcc $1 -lm

if [ $? -eq 0 ]; then                                      #if compilation was successful
    echo -e "\e[38;5;22mCompilation successful\e[0m"       #Print in green
else
    echo -e "\e[31mCompilation failed\e[0m"                #Print in red
    exit 1
fi

for ((i = 1; i <= $numberOfFiles; i++)); do
    timeout 2s "./a.out" <"./in$i.txt"> "./output$i.txt"

    returnStatus=$?

    if [ $returnStatus -eq 0 ]; then                                  #Checking execution return status
        echo -e "\e[38;5;22mExecution successful for TC $i\e[0m"
    else
        echo -e "\e[31mExecution failed for TC $i\e[0m"
        continue
    fi

    diff -q -Z "./out$i.txt" "./output$i.txt"             # -q => Just gives a single line output, whether files match or differ

    if [ $? -eq 0 ]; then
    	passed=$((passed + 1))
        echo -e "\e[38;5;22mTest passed for TC $i\e[0m"      

    else
        echo -e "\e[31mTest failed for TC $i \e[0m"
        diff -Z -y --color "./out$i.txt" "./output$i.txt"    # Print difference only if there exists any difference 
		                                                     # -y => Print difference side-by-side
															 # -Z => Ignores trailing spaces 
															 # -B => Ignores new-lines, but the output still shows the difference in number of white lines
        echo " "
    fi
done

echo -e "\e[1;42;30;102mpassed $passed/$2 test cases\e[0m" 

exit 0
