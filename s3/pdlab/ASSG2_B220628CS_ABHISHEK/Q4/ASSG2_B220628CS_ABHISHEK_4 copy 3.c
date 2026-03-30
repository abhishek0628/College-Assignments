//problem
/*
4. In a distant land, an ancient scroll contains a sequence of distinct numbers. The scroll’s magical
power is said to be activated only when the sequence is rotated at some point. The sequence
represents the wisdom of the ancients and contains various hidden insights. However, accessing
this powerful knowledge is not an easy task. The sequence of numbers is sorted in ascending order
and then rotated at an unknown point, making it difficult to navigate and find specific elements.
You are a brave adventurer and have managed to obtain the scroll. As you unravel its secrets, you
discover a cryptic message hinting at a ”secret number” hidden within the rotated sequence. The
message warns that this secret number will only be revealed to one who can uncover it with the
minimum number of comparisons.
Given a rotated sequence of distinct elements and the secret number you seek, your task is to
write a program that finds the secret number’s position within the sequence(starting with zero) by
doing minimum number of comparisons (on an average). If the secret number is not present, your
program should print -1.
Along with the secret number’s position, you also need to print the number of comparisons your
program made to find the secret number’s position.
(Hint: Use binary search)
Input Format:
• The first line is an integer n ∈[1, 107], total numbers in the scroll.
• The second line contains ’n’ integer numbers within the range ∈[0, 108] separated by a space,
indicating a sequence of numbers inside the scroll.
• The third line is an integer k ∈[1, 107], the secret number.
Output Format:
• A single line contains two integer values separated by a space, representing the secret number’s
position and the number of comparisons done by the program.
Sample Input 1:
9
10
5 3
5 6 7 8 9 10 1 2 3
Sample Output 1:
Sample Input 2:
4
5
1 1
3 5 1 2
Sample Output 2:
1 1
*/

//solution
#include <stdio.h>

int find_secret_number(int arr[], int n, int k, int *comparisons) {
    int l = 0, h = n - 1;
    *comparisons = 0;  

    while (l <= h) {
        (*comparisons)++;
        int mid = l + (h - l) / 2;

       
        if (arr[mid] == k) {
            return mid;
        }

        
        if (arr[l] <= arr[mid]) {  
            if (arr[l] <= k && k < arr[mid]) {
                h = mid - 1; 
            } else {
                l = mid + 1;  
            }
        } else {  
            if (arr[mid] < k && k <= arr[h]) {
                l = mid + 1;  
            } else {
                h = mid - 1;  
            }
        }
    }

    return -1;  
}

int main() {
    int n, k;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    int comparisons = 0;
    int position = find_secret_number(arr, n, k, &comparisons);

    printf("%d %d\n", position, comparisons);

    return 0;
}
