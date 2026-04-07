# Character Frequency Counter in C

## Problem

Eve needs to find the frequency of a given character in a given string. Write a program to help Eve implement it.

**Note:** The characters are **not case-sensitive**. Both uppercase and lowercase are considered the same character.

---

## Input Format

1. First line: an input string consisting of English alphabets (uppercase and lowercase).
2. Second line: a single character whose frequency needs to be computed.

---

## Output Format

* A single integer representing the frequency of the specified character.

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

* Frequency count is **case-insensitive**.
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

    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    scanf(" %c", &ch);
    ch = tolower(ch);

    for(int i = 0; str[i] != '\0'; i++) {
        if(tolower(str[i]) == ch) count++;
    }

    printf("%d\n", count);
    return 0;
}
```

## C++ Code Solution

```cpp
#include<stdio.h>
int main() {
    char str[1000];
    scanf("%[^
]%*c", str);
    char ch;
    int count = 0;
    scanf("%c", &ch);
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ch || str[i] == ch+32) count++;
    }
    printf("%d", count);
    return 0;
}
```

## Java Code Solution

```java
import java.util.*;
public class CharacterFrequency {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        char ch = sc.next().charAt(0);
        str = str.toLowerCase();
        ch = Character.toLowerCase(ch);
        int count = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ch) count++;
        }
        System.out.println(count);
    }
}
```

## Python Code Solution

```python
class Solution:
    def count(self, string, ch):
        c = 0
        ch = ch.lower()
        string = string.lower()
        for char in string:
            if char == ch:
                c += 1
        return c

if __name__ == "__main__":
    s = Solution()
    string = input()
    ch = input()
    print(s.count(string, ch))
```
