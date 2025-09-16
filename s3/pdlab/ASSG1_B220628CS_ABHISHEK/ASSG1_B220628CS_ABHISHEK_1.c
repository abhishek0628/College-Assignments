//problem
/*
1. Eve needs to find the frequency of a given character in a given string. Write a C programming
code to help Eve implement it. Note that the characters are not case-sensitive. (i.e. Both upper
and lowercase is considered to be the same character.)
Input Format:
• The first line is an input string that contains English alphabets with uppercase, and lowercase
characters. That is characters can be ∈[A−Z, a−z].
• The second line is the character whose frequency needs to be computed.
Output Format:
• An integer representing the frequency of the corresponding character.
Sample Input 1:
This is a test string
i
Sample Output 1:
3
Sample Input 2:
Malayalam
m
Sample Output 2:
2

*/

//solution
#include<stdio.h>
int main()
{
    char str[1000];
    scanf("%[^\n]%*c",str);
    char ch;
    int count=0;
    scanf("%c",&ch);
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]==ch|| str[i]==ch+32)
        {
            count++;

        }
    }
    printf("%d",count);
    return 0;
}