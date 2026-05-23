# Problem
'''
3. You are given an array of ‘n’ integers (both positive and negative) so that the sequence strictly
increases until it reaches a peak, and then strictly decreases. This is known as a mountain array.
You are given such an array. The peak element is an element at position ‘i’ such that:
arr[ i-1 ] < arr[ i ] and arr[ i+1 ] < arr[ i ]
You are asked to use the best known algorithm to minimize the number of comparisons done by
your program on an average to find the peak (Hint: Binary Search).
Along with the peak element, you should also print the number of comparisons done by your
program for finding the peak.
Input Format:
• First line contains the number of elements ’n’ in the array n ∈[1, 103].
• Second line contains the elements in the array arr ∈[−103
, 103].
Output Format:
• an integer containing the peak element.
• an integer indicating the number of comparisons done by the program
Sample Input 1:
9
1 3 5 6 7 8 5 3 2
Sample Output 1:
8
6
Sample Input 2:
5
1 2 3 4 5
Sample Output 2:
5
5
'''


# solution

