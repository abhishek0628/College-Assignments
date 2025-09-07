//problem
/*
4. We are given an input string str of length n, which is transformed into a fancy string f ancystr. The
fancy string f ancystr is created by repeating the i-th element in the string str, i times consecutively
for 1 ≤i ≤n. Design a program to identify the character that appears the most number of times
in this fancy string f ancystr. For example, if the given input string str is ‘bbbcca’, the fancy
string is ‘bbbbbbcccccccccaaaaaa’. Thus the character that appears the most number of times in
the fancy string f ancystr is ‘c’. If multiple characters have the same frequency, print the character
that appears first in the input string. Assume that all the string indexing starts at 1.
Note 1: While computing the frequency the characters are considered to be case-sensitive. (That
is lower and upper case characters are considered to be different characters.)
Input Format:
• The input is a string with uppercase, lowercase characters belonging to [A−Z, a−z]
Output Format:
• A single character belongs to [A-Z, a-z]
Sample Input 1:
PpQpq
Sample Output 1:
p
Sample Input 2:
AcbBCcAD
Sample Output 2:
A
*/

//solution
#include<stdio.h>
char fancy(char str[],int n)
{
    char ch;
    char ch2;
    char str2[1000];
    int count=0;
    int max=0;
    for(int i=0;str[i]!='\n';i++)
    {

        for(int j=0;j<n;j++)
        {
            ch=str[j];
            if(ch==str[i]||ch-32==str[i]||ch+32||str[i])
            {
                count++;

            }
            if(count>max)
            {
                max=count;
                ch2=ch;
            }
            count=0;
            
        }
    }
    return ch2;
}
int main()
{
    char str[1000];
    scanf("%s",str);
    printf("%c",fancy(str,1000));
    return 0;
}