# problem

'''
3. Alice and Bob were studying trigonometric functions and they planned to code a program to
compute an approximate value of sin(x) for given a value of x. They decided to use the following
Taylor’s series of sin(x) for computing the same.
sin(x) = x−(x3/3!)+(x5/5!)−(x7/7!) +(x9/9!)−···

Given x and n, compute the sine of x using the series. The computation should use all terms in
the series, whose degree of x is less than or equal to n. (That is including the term containing xn
if present).
Note 1 : Convert x to radian value x = x ∗(3.1415/180)
Note 2: Restrict the precision of the output to 4 decimal places.
Input Format:
• The first line of the input contains a real-valued number ∈[0−360] which is the value of x.
• The second line of the input contains a positive integer n ∈[1−103].
Output Format:
• The output is a real-valued number with exactly 4 decimal point precision.
Sample Input 1:
40
5
Sample Output 1:
0.6428
Sample Input 2:
20
2
Sample Output 2:
0.3420
'''




