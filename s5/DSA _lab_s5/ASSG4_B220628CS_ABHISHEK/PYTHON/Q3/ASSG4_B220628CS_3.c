//problem
/*
3. You are tasked with designing a job dispatcher using a priority queue Que implemented as a min-
heap. The job dispatcher selects a job to be executed from a pool of jobs based on its priority.
Each job has a unique job-id JID (1 ≤JID ≤100) and a priority p (1 ≤p ≤10).Only one job can
be executed at a time, and the pool of jobs can be updated with more jobs as they arrive. New
jobs are added to the pool upon arrival and are removed from the pool when they are scheduled
for execution.
From the pool, the job dispatcher selects the job with the highest priority for execution. Job with
the lowest priority value has higher priority(e.g., a priority of 1 is higher than a priority of 5). The
selected job is then removed from the pool after execution.
Note:
• The priority queue should be implemented using a min-heap, where jobs with lower numerical
priority values are given precedence.
• The JID values are unique. There are no two jobs with the same priority p.
Your program should be implemented using the following functions:
Operations
(a) Add(Que, JID, p): It adds a new job with job-id JID and priority p to the pool of jobs.
(b) Schedule(Que): It schedules the job with the highest priority from the pool of jobs for execu-
tion and then removes it from the pool of jobs. Print -1 if the pool is empty.
(c) Next-job(Que): It displays the JID of the next job to be executed, which will be the job with
the highest priority from the pool of jobs. The job is not removed from the pool. Print -1 if
the queue is empty.
(d) Replace-priority(Que, JID, np): It replaces the priority of job JID in the pool of jobs with
the new priority np. If the JID is not in the pool of jobs, print -1. After updating the priority,
the job should be repositioned within the heap to maintain the min-heap property.
(e) Display(Que): It prints the details (JID and p) of each job in the pool of jobs. Print -1 if the
pool is empty.
Input Format:
• Each line contains a character from {‘a’, ‘b’, ‘c’, ‘d’, ‘e’, ‘g’}followed by zero or more positive
integers n.
• Character ‘a’ is followed by two positive integers JID and p. Perform the Add(Que, JID, p)
operation.
• Character ‘b’ performs the Schedule(Que) operation.
• Character ‘c’ performs the Next-job(Que) operation.
• Character ‘d’ is followed by two positive integers JID and np. Perform the Replace-priority(Que,
JID, np) operation.
• Character ‘e’ performs the Display(Que) operation.
• Character ‘g’ is to terminate the sequence of operations.
Output Format:
• The output (if any) of each command should be printed on a separate line. However, no
output is printed for ‘a’ and ‘g’.
• For Option ‘b’: Print the JID of the scheduled job. If the pool is empty, print -1.
• For Option ‘c’: Print the JID of the next job to be executed. If the pool is empty, print -1.
• For Option ‘d’: After replacing the priority, if the JID is found in the pool, no output is
required. If the JID is not found, print -1.
• For Option ‘e’: Print the job details (JID and p) of each job as a space-separated list of
elements in the level-order traversal. Where each pair of (JID p) should be printed in a new
line. If the pool is empty, print -1.
Sample test case 1
Input:
c
a 18 3
a 17 2
a 10 4
a 16 1
a 9 5
e
c
b
d 20 1
d 9 6
e
c
g
Output:
-1
16 1
17 2
10 4
18 3
9 5
16
16
-1
17 2
18 3
10 4
9 6
17
*/

//solution
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#define capacity 100
struct job
{
    int jid;
    int pr;
};
struct pq
{
    int size;
    struct job arr[capacity];
};
void reverse(struct job *a, struct job *q)
{
    struct job t = *a;
    *a = *q;
    *q = t;
}
void min_heapify(struct pq *pq, int i)
{
    int s = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int tempp = 0;
    int flag = 0;
    if (l < pq->size && pq->arr[l].pr < pq->arr[s].pr)
        s = l;
    if (r < pq->size && pq->arr[r].pr < pq->arr[s].pr)
        s = r;
    if (s != i)
    {
        reverse(&pq->arr[i], &pq->arr[s]);
        min_heapify(pq, s);
    }
    tempp++;
    flag = tempp;
}

void Add_job(struct pq *pq, int jid, int priority)
{
    int tempp = 0;
    int flag = 0;
    if (pq->size >= capacity)
    {
        return;
    }
    for(int i=0;i<pq->size;i++)
    {
        if(pq->arr[i].pr==priority)
        {
            return;
        }
    }

    struct job new_Job = {jid, priority};
    pq->arr[pq->size] = new_Job;
    pq->size++;

    int i = pq->size - 1;
    while (i != 0 && pq->arr[(i - 1) / 2].pr > pq->arr[i].pr)
    {
        reverse(&pq->arr[i], &pq->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    tempp++;
    flag = tempp;
}
void Schedule_job(struct pq *pq)
{
    int tempp = 0;
    int flag = 0;
    if (pq->size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq->arr[0].jid);
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    min_heapify(pq, 0);
    tempp++;
    flag = tempp;
}
void Next_Job(struct pq *pq)
{
    int tempp = 0;
    int flag = 0;
    if (pq->size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq->arr[0].jid);
}

void Replace_Pr(struct pq *pq, int JID, int pr2)
{
    int tempp = 0;
    int flag = 0;
    int index = -1;
    for (int i = 0; i < pq->size; i++)
    {
        if (pq->arr[i].jid == JID)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("-1\n");
        return;
    }
    tempp++;
    flag = tempp;

    int pr1 = pq->arr[index].pr;
    pq->arr[index].pr = pr2;

    if (pr2 < pr1)
    {
        while (index != 0 && pq->arr[(index - 1) / 2].pr > pq->arr[index].pr)
        {
            reverse(&pq->arr[index], &pq->arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    else
    {
        min_heapify(pq, index);
    }
}

int main()
{
    int tempp = 0;
    int flag = 0;
    struct pq pq = {.size = 0};
    char ch;
    int JID, pr, pr2;

    while (scanf(" %c", &ch) != EOF)
    {
        switch (ch)
        {
        case 'a':
            scanf("%d %d", &JID, &pr);
            Add_job(&pq, JID, pr);
            break;
        case 'b':
            Schedule_job(&pq);
            break;
        case 'c':
            Next_Job(&pq);
            break;
        case 'd':
            scanf("%d %d", &JID, &pr2);
            Replace_Pr(&pq, JID, pr2);
            break;
        case 'e':
            for (int i = 0; i < pq.size; i++)
            {
                printf("%d %d\n", pq.arr[i].jid, pq.arr[i].pr);
            }
            break;
        case 'g':
            return 0;
        }
    }
    tempp++;
    flag = tempp;

    return 0;
}
