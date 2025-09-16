//problem
/*
1. You are the sole maintainer of a museum, where all articles are initially arranged in increasing
order of their size in meters. However, another team discovered some new items and placed them
randomly after the last arranged item. Now, there's an upcoming festival on D days, and you need
to rearrange these scattered items (second part) along with the existing ones (first part) so that
visitors can enjoy the fest with minimal confusion. Condition is that in one day, you can rearrange
one item from the second part to its correct position in the first part, by appropriately shifting the
items. At the end of the day, after the shifting operation the first part increases its size by one.
Your task is to provide the complete list of item sizes to your manager, representing the
arrangement after D days. (Hint Insertion sort).
Input Format:
● The first line contains integer N ∈ [1, 10^3] representing numbers of items.
● The second line contains sizes(float) of N elements, size ∈ [1, 10^3] which represent
length in meters.
● Third line contains integer X ∈ [0, 10^3] representing new items in the items list.
● Fourth line contains an integer D∈ [0, 10^3], representing the number of days
and D ≤ X.
Output Format:
● First line contains all item’s size rearranged in D days. (precise 2 decimal places)
Sample Input:
5
2 5 300 2.1 10
3
2
Sample Output:
2.00 2.10 5.00 300.00 10.00
*/

//solution
#include<stdio.h>
int main()
{
    return 0;
}