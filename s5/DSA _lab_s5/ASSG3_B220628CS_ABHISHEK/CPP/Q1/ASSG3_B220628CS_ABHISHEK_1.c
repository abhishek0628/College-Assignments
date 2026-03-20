//problem
/*
1. To conduct an event, our institute decided to split the students into four groups using a hash
function, h. The procedure for grouping a student A using h is as follows:
h(A) = (Sum of ASCII value of the characters in the first name of ‘A’ + age of ‘A’) % 4, where
‘A′ represents a student structure to hold the student name, roll number as in our institute format
and age. Such a hash value obtained is called a group index.
Eg:- Let A.first name=‘Veena’, A.rollno=B220016CS and A.age=19, then h(A) = (86+101+101+
110+97+19) % 4 = 2; where, 86 - ASCII(V), 101 - ASCII(e), 110 - ASCII(n), 97 - ASCII(a).
If h(A) =0, the student is placed in group 0; if h(A) = 1, the student is placed in group 1; if h(A)
= 2, the student is placed in group 2, and if h(A) = 3, the student is placed in group 3.
Implement the following operations as a menu-driven program. Note that the functions described
below except StudentDetails() take the hash table H as one of the parameters. Once the students’
details are entered, the students are split into four groups based on the hash value.
Operations
(a) GroupIndexAndSplit(A.f irst name, H): Using the hash function, calculate the group index
for a given student A. Print the group index for the given student A.
(b) Group CountAndList(H, k): For group k, count the number of students and list their names
in alphabetical order. Print the count followed by the names.
(c) Group ListByBranch(H, m, Branch): For group m, list the students who belong to the given
Branch. The branch of a student can be identified from the last two characters of the roll
number. If no students from that Branch are found in the group, print−1.
(d) StudentDetails(rollnumber): Retrieve and display the details (first name, age, branch) of
the student with the given roll number. If no student with a given roll number is found, print
−1.
(e) Group T ransf erAllByBranch(H, source m, target m, branch): Change the index of all those
students in the source group index source m, belonging to the specified branch to target group
index target m. Print the number of students transferred/changed.
Note: Assume all the students are from CS, EC, EE, or CE branches.
Input format:
• First line of the input contains an integer ‘n’ ∈[1, 103], the total number of students who are
participating in the event.
• Next ‘n’ consecutive line contains: first name, roll number, and age of each student, separated
by a single space.
• Each subsequent line contains a character from {‘a’, ‘b’, ‘c’, ‘d’,‘e’, ‘f’ }followed by zero or
more positive integers n, followed by zero or two characters.
• Character ’a’ followed by a first name of A (A.f irst name) perform GroupIndexAndSplit(A, H)
operation.
• Character ’b’ followed by a positive integer ’k’ ∈[0, 3]. Perform Group CountAndList(H, k)
operation.
• Character ’c’ followed by a positive integer ’m’ ∈[0, 3], representing the group number, fol-
lowed by two characters representing the branch name (both uppercase and lowercase are con-
sidered the same branch) separated by a space. Perform Group ListByBranch(H, m, Branch)
operation.
• Character ’d’ followed by a string rollnumber, separated by a space.
Perform StudentDetails(rollnumber) operation.
• Character ’e’ followed by a space separated two positive integers followed by two characters
representing the branch name (both uppercase and lowercase are considered the same branch)
separated by a space. Perform Group T ransf erAllByBranch(H, source m, target m, branch)
operation.
• Character ’f ’ is to terminate the sequence of operations.
Output format:
• The output (if any) of each command should be printed on a separate line. However, no
output is printed for ‘f’.
• For option ’a’: Print the group index (0, 1, 2, or 3) for the given student A.
• For option ’b’: Print a positive integer representing the count of students in group k, followed
by their names (strings) in the alphabetical order, separated by a space.
• For option ’c’: Prints the strings representing the first names of the students in group m from
the specified branch in a space-separated manner. Print -1 if no students from that branch
are found in the group.
• For option ’d’: Print the details (f irstname, age, branch) of a given student separated by a
space. If no student is found, then print−1.
• For option ’e’: Print an integer representing the number of students transferred.
Sample test case 1
Input:
5
Abu B210051CS 21
Veena B220016EC 19
Ishan B190016CE 22
Aleena B200036EE 21
Sam B230017CS 21
a Veena
b 1
c 2 EC
c 3 CS
d B190016CE
b 0
d B210151CS
c 2 CS
c 1 CS
e 0 2 CS
e 2 1 ec
f
Output:
2
2 Abu Ishan
Veena
-1
Ishan 22 CE
0
-1
Sam
Abu
0
1
*/
//solution
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#define abhi 21
#define ss 19
#define hs 12
#define Size 1000
struct set
{
    int data;
    int key;
};
typedef struct
{
    char Name[60];
    char roll_No[25];
    int age;
} St;

struct node
{
    St stu;
    struct node *next;
};

struct node *hash[4] = {NULL, NULL, NULL, NULL};

int Grp_indx_n_lst(const char *Name, int age)
{
    int count = 0;
    int l = strlen(Name);
    while (l--)
    {
        count += Name[l];
    }
    return (count + age) % 4;
}
int isprime(int n)
{
    if (n == 0 || n == 1)
        return 0;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void add_st_grp(int indx, St stu)
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->stu = stu;
    temp->next = hash[indx];
    hash[indx] = temp;
    tempp++;
    flagg++;
    ceill++;
}

int compare(const void *a, const void *b)
{
    int pp=0;
    pp++;
    return strcmp(*(const char **)a, *(const char **)b);
}

void Grp_cnt_lst(int k)
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    
    struct node *temp = hash[k];
    int count = 0;
    char *names[Size];

    while (temp != NULL)
    {
        names[count] = temp->stu.Name;
        count++;
        temp = temp->next;
    }
    tempp++;
    tempp=flagg;

    qsort(names, count, sizeof(char *), compare);

    printf("%d", count);
    for (int i = 0; i < count; i++)
    {
        printf(" %s", names[i]);
    }
    tempp++;
    flagg++;
    ceill++;
    printf("\n");
}
int prime(int n)
{
    for (int i = n - 1; i >= 2; i--)
    {
        if (isprime(i))
        {
            return i;
        }
    }
    return -1;
}

void Grp_lst_brnch(int m, const char *branch)
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    struct node *temp = hash[m];
    int found = 0;

    while (temp != NULL)
    {
        if (strcasecmp(branch, &temp->stu.roll_No[strlen(temp->stu.roll_No) - 2]) == 0)
        {
            if (found > 0)
            {
                printf(" ");
            }
            printf("%s", temp->stu.Name);
            found++;
        }
        temp = temp->next;
    }
    tempp=flagg;
    flagg++;

    if (!found)
    {
        printf("-1\n");
    }
    
    else
    {
        printf("\n");
    }
    tempp++;
    flagg++;
    ceill++;
}

void St_dtls(const char *rollNo)
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    for (int i = 0; i < 4; i++)
    {
        struct node *temp = hash[i];
        while (temp != NULL)
        {
            if (strcmp(temp->stu.roll_No, rollNo) == 0)
            {
                printf("%s %d %s\n", temp->stu.Name, temp->stu.age, &temp->stu.roll_No[strlen(temp->stu.roll_No) - 2]);
                return;
            }
            temp = temp->next;
        }
    }
    tempp++;
    flagg++;
    ceill++;
    printf("-1\n");
}

void Grp_trnf_brnch(int sourceM, int targetM, const char *branch)
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    struct node **current = &hash[sourceM];
    int count = 0;

    while (*current != NULL)
    {
        tempp++;
        if (strcasecmp(branch, &(*current)->stu.roll_No[strlen((*current)->stu.roll_No) - 2]) == 0)
        {
            struct node *temp2 = *current;
            *current = (*current)->next;

            temp2->next = hash[targetM];
            hash[targetM] = temp2;
            count++;
        }
        else
        {
            current = &(*current)->next;
        }
        flagg--;
    }
    tempp++;
    flagg++;
    ceill++;

    printf("%d\n", count);
}

int main()
{
    int tempp=0;
    int flagg=0;
    int ceill=0;
    int n;
    scanf("%d", &n);
    St st[Size];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d", st[i].Name, st[i].roll_No, &st[i].age);
        int groupIndex = Grp_indx_n_lst(st[i].Name, st[i].age);
        add_st_grp(groupIndex, st[i]);
    }
    char ch;
    while (scanf(" %c", &ch) && ch != 'f')
    {
        tempp++;
        switch (ch)
        {
        case 'a':
        {
            char Name[50];
            scanf("%s", Name);
            tempp++;
            for (int i = 0; i < n; i++)
            {
                if (strcmp(st[i].Name, Name) == 0)
                {
                    int grp_indx = Grp_indx_n_lst(st[i].Name, st[i].age);
                    printf("%d\n", grp_indx);
                    break;
                }
            }
            flagg--;
            break;
        }
        flagg--;

        case 'b':
        {
            ceill++;
            int k;
            scanf("%d", &k);
            tempp++;
            Grp_cnt_lst(k);
            break;
        }

        case 'c':
        {
            flagg++;
            int m;
            char branch[3];
            scanf("%d %s", &m, branch);
            tempp++;
            Grp_lst_brnch(m, branch);
            break;
        }

        case 'd':
        {
            tempp++;
            char roll_No[25];
            scanf("%s", roll_No);
            flagg--;
            St_dtls(roll_No);
            break;
        }

        case 'e':
        {
            tempp++;
            int src, trgt;
            char branch[3];
            ceill++;
            scanf("%d %d %s", &src, &trgt, branch);
            Grp_trnf_brnch(src, trgt, branch);
            break;
        }

        default:
            printf("case not matched\n");
            break;
        }
    }
    tempp++;
    flagg++;
    ceill++;

    return 0;
}
