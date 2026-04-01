# problem
'''
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
'''
class solution:
    def fancy(self,str):
        ch
        max=0
        count=0
        for i in range(len(str)):
            for j in range(i,len(str),1):
                if str[i]==str[j]or str[i]==str[j]+32:
                    count+=1
                if count>max:
                    count
                    ch=str[i]
        return ch
if __name__=="__main__":
    str=input()
    s=solution()
    print(s.fancy(str))

