//problem
/*
3. Alice and Bob were studying trigonometric functions and they planned to code a program to
compute an approximate value of sin(x) for given a value of x. They decided to use the following
Taylor’s series of sin(x) for computing the same.
sin(x) = x−
x3
3! +
x5
51−
x7
7! +
x9
9!−···
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
*/

//solution
#include <stdio.h>
#include <math.h>
//function to calculate the factorial
int fact(int n) 
{
    if (n == 0 )
        return 1;
        if(n==1)
        return 1;
    return fact(n - 1) * n;
}

//function to calculate the sin value
float sin(int x, int n)
{
    float x2=x*(3.1415/180);
    float sum = 0;
    int count=0;
    for (int i = 0; i <=n; i++)
    {
        int term=2*i+1;
        float exp=pow(x2,term)/fact(term);

        if(i%2==0)
        {
            sum=sum+exp;
        }
        else 
        sum=sum-exp;
    }
    printf("%d\n",count);
    return sum;
}
int main()
{
    int x,n;
    scanf("%d%d",&x,&n);
    float temp=sin(x,n);
    printf("%0.4f",temp);
   
    return 0;

}


