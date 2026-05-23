//problem
/*
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
*/

// solution
import java.util.*;
class solution{
    void  peak(int arr[]){
        int n=arr.length;
        int low=0;
        int high=n-1;
        int cmp=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid==n-1){
                if(arr[mid]>arr[mid-1]){
                    cmp++;
                    System.out.println(arr[mid]);
                    System.out.print(cmp);

                    return;
                }
            }
            if(mid==0){
                if(arr[mid]>arr[mid+1]){
                    cmp++;
                    System.out.println(arr[mid]);
                    System.out.print(cmp);
                    return;
                }
            }
            if(arr[mid]>arr[mid+1]&& arr[mid]>arr[mid-1]){
                cmp+=2;
                // System.out.print(cmp);
                System.out.println(arr[mid]);
                System.out.print(cmp);
                return;
            }
            else if(arr[mid]>arr[mid-1]&& arr[mid]<arr[mid+1]){
                cmp+=2;
                low=mid+1;
            }
            else if(arr[mid]>arr[mid+1]&& arr[mid]<arr[mid-1]){
                cmp+=2;
                high=mid-1;
            }
        }
        
    }
}
public class ASSG2_B220628CS_ABHISHEK_3{
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        solution s=new solution();
        // int[] arr=new int(n);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            int p=sc.nextInt();
            arr[i]=p;
        }
        // System.out.print(s.peak(arr));
        s.peak(arr);
    }
}