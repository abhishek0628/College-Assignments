# Character Frequency Counter in C

## Problem

2. You are given a positive integer N . Print all integers from 1 to N without using any of the looping
constructs.


---

## Input Format

• The first line is a positive integer N ∈[1, 103].

---

## Output Format

• A single line of integers from 1 to N each separated by a single space between them.

---

## Sample Input 1

```
5
```

## Sample Output 1

```
1 2 3 4 5
```

## Notes

* Frequency count is **case-insensitive**.
* Only English alphabets are considered.

---

## C Code Solution

```c
#include<stdio.h>
void print(int n)
{
    if(n==0)return;
    print(n-1);
    printf("%d ",n);
}
int main()
{
    print(5);
    return 0;

}
```

## C++ Code Solution

```cpp
#include<stdio.h>
void print(int n)
{
    if(n==0)return;
    print(n-1);
    printf("%d ",n);
}
int main()
{
    print(5);
    return 0;

}
```

## Java Code Solution

```java
import java.util.*;
class solution{
    void printN(int n){
        if(n==0)return;
        printN(n-1);
        System.out.print(n+" ");
    }
}
public class ASSG1_B220628CS_ABHISHEK_2{
    public static void main(String[] args){
        solution s=new solution();
        Scanner sc=new Scanner(System.in);
        System.out.print("enter number: ");
        int n=sc.nextInt();
        s.printN(n);


    }
}
```

## Python Code Solution

```python
class solution:
    def printN(self,n):
        if n==0:
            return
        self.printN(n-1)
        print(n,end=" ")
if __name__=="__main__":
    n=int(input("enter number: "))
    s=solution()
    s.printN(n)
```
