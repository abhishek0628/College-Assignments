//problem
/*
2. You are given a large document represented as a string T and a potentially plagiarized section
represented as a pattern P . Implement the Boyer-Moore algorithm to detect whether the pattern
P appears in the document T , and if it does, return the first index at which it appears. If the
pattern is not found, return -1.
Input Format
• First part of the input contains a string T representing the large document (1 ≤|T |≤107)
and the next part contains a string P representing the pattern (1 ≤|P |≤105) separated by
a new line character (‘\n’).
Output Format
• Print the index (starts at 0) of the first occurrence of the pattern P in the text T . If no
occurrence of the pattern is found, then print -1.
Sample test case:
Input:
Convolutional neural networks (CNNs) are widely regarded as the most effective for image
classification. They learn spatial hierarchies of features through backpropagation and can
handle complex visual tasks.
spatial hierarchies
Output:
116
*/

//solution
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_SIZE 256

void createBadCharTable(char *pattern, int m, int *badChar) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        badChar[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        badChar[(unsigned char) pattern[i]] = i;
    }
}

void createGoodSuffixTable(char *pattern, int m, int *goodSuffix) {
    int lastPrefixPosition = m;
    for (int i = m; i > 0; i--) {
        if (strncmp(pattern, pattern + i, m - i) == 0) {
            lastPrefixPosition = i;
        }
        goodSuffix[m - i] = lastPrefixPosition - i + m;
    }
    for (int i = 0; i < m - 1; i++) {
        int suffixLength = 0;
        while (i - suffixLength >= 0 && pattern[i - suffixLength] == pattern[m - 1 - suffixLength]) {
            suffixLength++;
        }
        if (pattern[i - suffixLength] != pattern[m - 1 - suffixLength]) {
            goodSuffix[m - 1 - suffixLength] = m - 1 - i + suffixLength;
        }
    }
}

int boyerMooreSearch(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    if (m > n) {
        return -1;
    }

    int *badChar = (int *)malloc(ALPHABET_SIZE * sizeof(int));
    int *goodSuffix = (int *)malloc(m * sizeof(int));

    if (badChar == NULL || goodSuffix == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    createBadCharTable(pattern, m, badChar);
    createGoodSuffixTable(pattern, m, goodSuffix);

    int shift = 0;
    while (shift <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            free(badChar);
            free(goodSuffix);
            return shift;
        } else {
            int badCharShift = j - badChar[(unsigned char) text[shift + j]];
            int goodSuffixShift = goodSuffix[j];
            shift += (badCharShift > goodSuffixShift) ? badCharShift : goodSuffixShift;
        }
    }

    free(badChar);
    free(goodSuffix);
    return -1;
}

int main() {
    char *text = (char *)malloc(10000001 * sizeof(char));
    char *pattern = (char *)malloc(100001 * sizeof(char));

    if (text == NULL || pattern == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    fgets(text, 10000001, stdin);
    text[strcspn(text, "\n")] = 0;

    fgets(pattern, 100001, stdin);
    pattern[strcspn(pattern, "\n")] = 0;

    int result = boyerMooreSearch(text, pattern);
    printf("%d\n", result);

    free(text);
    free(pattern);

    return 0;
}
