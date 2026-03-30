//problem
/*
3. Our institute decided to split the students into four groups to conduct an event. The procedure
for splitting is as follows:
h(A) = (Sum of ASCII value of the characters in the first name of ‘A’ + age of ‘A’) % 4, where
‘A’ represents a student.
Eg:- h(Veena) = (86+101+101+110+97+19) % 4 = 2; where, 86 - ASCII(V), 101 - ASCII(e),
110 - ASCII(n), 97 - ASCII(a), 19 - age(Veena).
If h(A) =0, the student is placed in group 0; if h(A) = 1, the student is placed in group 1; if h(A)
= 2, the student is placed in group 2, and if h(A) = 3, the student is placed in group 3.
Write a program to perform the operations count the number of students in each group, the student
list in a group as per the order of insertion, and the student list who belongs to the same branch in
a group.
Note: Assume all the students are from CS, EC, EE, or CE branches.
Input format:
• First line of the input contains an integer ‘n’ ∈[1, 103], the total number of students who are
participating in the event.
• Next ‘n’ consecutive line contains: first name, roll number, and age; separated by single space.
• The input contains a character ’c’ followed by an integer ’k’ ∈[0, 3] to display the count and
student list of the group ’k’.
• The input contains an integer ’m’ ∈[0, 3], representing the group number, followed by two
characters representing the branch name (both uppercase and lowercase are considered the
same branch).
5
• The input contains a character ’e’ to represent the end of the input.
Output format:
• The output (if any) of each command should be printed on a separate line.
• For input lines starting with the character ’c’ followed by an integer ’k’ ∈[0, 3], prints an
integer ’x’ followed by x number of strings separated by a space.
• For input lines starting with an integer ’m’ ∈[0, 3] followed by two characters, prints the
strings (first name) separated by a space, if any student exit in the group ’m’. Otherwise,
print -1.
Sample Input:
4
Veena B220016EC 19
Abu B210051CS 21
Ishan B190016CE 22
Aleena B200036EE 21
c 0
1 CS
c 1
c 2
c 3
3 EC
2 ec
e
Sample Output:
0
Abu
2 Abu Ishan
1 Veena
1 Aleena
-1
Veena
4. Open addressing is a method for handling collisions in hashing. The three different methods for
open addressing are linear probing, quadratic probing, and double hashing. A brief description of
the three methods is given below:
In linear probing, the function used to calculate the next location during collision is: h′(k) =
(h(k) + i) mod m, i = 1, 2. . . .
In quadratic probing, the function used to calculate the next location during collision is: h′(k) =
(h(k) + i2) mod m, i = 1, 2. . .
In double hashing scheme, the primary hash function is, h1(k) = k mod N , where N is the table
size. The secondary hash function is, h2(k) = R−(key mod R) where R is the maximum prime
number less than the table size. Double hashing can be done using: (h1(key) + i ∗h2(key))
mod N, i = 0, 1, 2. . . .
Given a set of keys and the table size, write a program to print the locations at which the keys are
stored using the above-mentioned three methods and also print the total number of collisions that
occur during mapping for each of the three methods.
Input format:
• First line of the input contains an integer, the table size.
• Second line contains space-separated(single space) integer numbers, the keys to be inserted.
Output format:
6
• First line of the output contains space-separated (single space) integers, the locations obtained
using linear probing.
• Second line contains an integer, the total number of collisions that occurred during linear
probing.
• Third line of the output contains space-separated (single space) integers, the locations obtained
using quadratic probing.
• Fourth line contains an integer, the total number of collisions that occurred during quadratic
probing.
• Fifth line of the output contains space-separated (single space) integers, the locations obtained
using double hashing.
• Sixth line contains an integer, the total number of collisions that occurred during double
hashing.
Sample Input:
7
76 93 40 47 10 55
Sample Output:
6 2 5 0 3 1
4
6 2 5 0 3 1
6
6 2 5 1 3 4
2
5. Given an array A of N integers and an integer K, return the count of distinct integers in all windows
of size K.
Input Format:
• The first line contains two integers N and K (space-separated), N giving size of input
arrays A and K indicating the size of the window.
• The second line contains N positive integers (space-separated) in input array A.
Output Format:
• First Line Contains Space Separated Count of distinct integers in each window of size K.
Constraints:
• Time Complexity Should be O(N).
Sample Input 1:
10 4
2 8 2 3 4 5 5 6 5 2
Sample Output 1:
3 4 4 3 3 2 3
*/

//solution
