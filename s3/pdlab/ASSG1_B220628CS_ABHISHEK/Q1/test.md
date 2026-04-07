# Character Frequency Counter in C

## Problem

Eve needs to find the frequency of a given character in a given string. Write a C program to help Eve implement it.

**Note:** The characters are **not case-sensitive**. That is, both uppercase and lowercase are considered the same character.

---

## Input Format

1. The first line contains an input string consisting of English alphabets (uppercase and lowercase).
   Characters ∈ `[A-Z, a-z]`.
2. The second line contains a single character whose frequency needs to be computed.

---

## Output Format

* A single integer representing the frequency of the specified character in the input string.

---

## Sample Input 1

```
This is a test string
i
```

## Sample Output 1

```
3
```

---

## Sample Input 2

```
Malayalam
m
```

## Sample Output 2

```
2
```

---

## Notes

* The frequency count is **case-insensitive**.
* Only English alphabets are considered.

---

## C Code Solution

```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[1000];
    char ch;
    int count = 0;

    // Read string with spaces
    fgets(str, sizeof(str), stdin);
    // Remove newline character if any
    str[strcspn(str, "\n")] = 0;

    // Read the character to count
    scanf(" %c", &ch);

    // Convert character to lowercase
    ch = tolower(ch);

    // Loop through string and count occurrences
    for(int i = 0; str[i] != '\0'; i++) {
        if(tolower(str[i]) == ch) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
```
