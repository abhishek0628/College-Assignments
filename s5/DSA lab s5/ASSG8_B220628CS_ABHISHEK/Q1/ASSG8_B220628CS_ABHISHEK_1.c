//problem
/*
1. You are given a DNA sequence represented as a string S consisting of the characters {A, C, G,
T}and a target DNA pattern P . Write a program that uses the KMP algorithm to find all the
occurrences of the pattern P in the DNA sequence S. Print the index of the last occurrence and
the frequency of P in S.
Input Format
• First line contains a string S representing the DNA sequence (1 ≤|S|≤106).
• The next line contains a string P representing the DNA pattern (1 ≤|P |≤105).
Output Format
• Print the index (starts at 0) of the last occurrence of the pattern P in the text S, followed by
the number of times the pattern P occurs in S separated by a space. If no match is found,
then print−1.
Sample test case:
Input:
AGCTTAGCTAAGCTT
AGCTT
Output:
10 2
*/

//solution
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void computeLPSArray(char* pattern, int m, int* lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* dna_sequence, char* pattern) {
    int n = strlen(dna_sequence);
    int m = strlen(pattern);

    int* lps = (int*)malloc(m * sizeof(int)); 
    computeLPSArray(pattern, m, lps);

    int i = 0; 
    int j = 0;  
    int last_occurrence = -1;
    int frequency = 0;

    while (i < n) {
        if (pattern[j] == dna_sequence[i]) {
            i++;
            j++;
        }

        if (j == m) {
            last_occurrence = i - j; 
            frequency++; 
            j = lps[j - 1]; 
        } else if (i < n && pattern[j] != dna_sequence[i]) {
            if (j != 0) {
                j = lps[j - 1]; 
            } else {
                i++;
            }
        }
    }

    if (frequency > 0) {
        printf("%d %d\n", last_occurrence, frequency);
    } else {
        printf("-1\n");
    }

    free(lps); 
}

int main() {
    char *dna_sequence = (char *)malloc(10000001 * sizeof(char));
    char *pattern = (char *)malloc(100001 * sizeof(char));


    fgets(dna_sequence, 10000001, stdin);
    fgets(pattern, 100001, stdin);

    dna_sequence[strcspn(dna_sequence, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    KMPSearch(dna_sequence, pattern);

    free(dna_sequence);
    free(pattern);

    return 0;
}

