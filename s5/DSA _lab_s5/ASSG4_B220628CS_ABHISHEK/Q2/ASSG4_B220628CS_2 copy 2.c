//problem
/*
2. You are tasked with developing a patient management system for an emergency room using a
priority queue P Q implemented as a min-heap. Each patient has a unique identifier patient id, a
name name, and a severity level severity. The priority queue is used to manage patients based on
the severity of their condition. The emergency room has the following rules:
• Lower priority values indicate more severe conditions (e.g., a priority of 1 is more urgent than
a priority of 5).
• Each patient has a unique priority, ensuring no two patients have the same severity level.
The system must handle various operations efficiently to manage the patient queue, ensuring that
the heap property is maintained after each operation. The operations are described below:
Operations
(a) AdmitP atient(P Q, patient id, name, severity) :
• Admit a new patient with patient id, name and a severity level into the priority queue
PQ.
• After each admission, print the current state of the priority queue as a space-separated
list of patient id s in level-order traversal (based on severity).
(b) T reatP atient(P Q) :
• Treat and remove the patient with the most severe condition (i.e., the patient with the
lowest severity value) from the priority queue PQ.
• Print the patient id and name of the patient that was treated. Given that no two patients
have the same severity, only one patient will be treated.
• If the priority queue is empty, i.e., if there are no patients to treat, print -1
(c) U pdateSeverity(P Q, patient id, new severity) :
• Update the severity of an existing patient identified by patient id to new severity. Ensure
that the new severity is unique. If the patient is absent in the queue, print -1.
• After updating the severity, print the updated priority queue in level-order traversal to
reflect the changes.
(d) QueryP atient(P Q, patient id) :
• Check if a patient with patient id is in the queue and print their name and severity level.
If the patient is not found, print -1
(e) F indM ostSevere(P Q) :
• Print the patient id name and severity of three patients with the most severe condition
(i.e., three patients with the lowest severity value) without removing them from the queue.
If there are fewer than three patients, print as many as available. If the queue is empty,
print -1
Input Format
• Each line contains a character from {‘a’, ‘b’, ‘c’, ‘d’, ‘e’}followed by at-most two positive
integers n.
• Character ’a’ is followed by a space separated two positive integers, patient id and severity
followed by a string separated by a space. Perform the AdmitPatient(PQ, patient id, name,
severity) operation.
• Character ’b’ performs the TreatPatient(PQ) operation.
• Character ’c’ is followed by a space separated two positive integers, patient id and new severity.
Perform the UpdateSeverity(PQ, patient id, new severity) operation.
• Character ’d’ is followed by a positive integer, patient id. Perform the QueryPatient(PQ,
patient id) operation.
• Character ’e’ performs the FindMostSevere(PQ) operation.
Output Format
• The output (if any) of each command should be printed on a separate line. However, no
output is printed for ‘g’.
• For option ’a’: Print the current state of the priority queue after the admission in level-order
traversal.
• For option ’b’: Print the patient id and name of the patient that was treated, or -1 if the
queue is empty.
• For option ’c’: Print the updated priority queue in level-order traversal, or -1 if the patient
is not found.
• For option ’d’: Print the name and severity of the patient, or -1 if the patient is not found.
• For option ’e’: Print the patient id, name and severity of three most severe patients in the
increasing order of severity (space-separated). Each patient’s details should be printed in a
new line. If there are fewer than three patients, print as many as available in separate lines.
Print -1 if the queue is empty.
Sample test case 1
Input:
a 101 5 Asma
a 102 3 Sajeena
a 103 4 Sourav
b
c 103 2
d 101
a 105 1 Ruchi
a 107 3 Parth
a 120 4 Rohan
e
d 102
Output:
101
102 101
102 101 103
102 sajeena
103 101
asma 5
105 101 103
105 107 103 101
105 107 103 101 120
105 Ruchi 1
103 Sourav 2
107 Parth 3
-1
*/

//solution
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#define capacity 100
struct patient
{
    int id;
    char name[100];
    int sev;
};
struct pq
{
    struct patient arr[capacity];
    int size;
};

void reverse(struct patient *a, struct patient *b)
{
    struct patient temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(struct pq *pq, int i)
{
    int index = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int tempp = 0;
    int flag = 0;

    if (left < pq->size && pq->arr[left].sev < pq->arr[index].sev)
        index = left;
    if (right < pq->size && pq->arr[right].sev < pq->arr[index].sev)
        index = right;
    if (index != i)
    {
        reverse(&pq->arr[i], &pq->arr[index]);
        min_heapify(pq, index);
    }
    tempp++;
    flag = tempp;
}

void display_(struct pq *pq)
{
    int tempp = 0;
    int flag = 0;
    for (int i = 0; i < pq->size; i++)
    {
        printf("%d ", pq->arr[i].id);
    }
    tempp++;
    flag = tempp;
    printf("\n");
}

void Add_Patient(struct pq *pq, int patient_id, char *name, int sev)
{
    int tempp = 0;
    int flag = 0;
    if (pq->size >= capacity)
    {
        printf("Priority queue is full.\n");
        return;
    }
    for(int i=0;i<pq->size;i++)
    {
        if (pq->arr[i].sev == sev)
        {
            return;
        }
    }

    struct patient newPatient = {patient_id, "", sev};
    strcpy(newPatient.name, name);
    pq->arr[pq->size] = newPatient;
    pq->size++;
    int parent;

    int i = pq->size - 1;
    while (i != 0 && pq->arr[(i - 1) / 2].sev > pq->arr[i].sev)
    {
        reverse(&pq->arr[i], &pq->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    tempp++;
    flag = tempp;

    display_(pq);
}

void extract(struct pq *pq)
{
    int tempp = 0;
    int flag = 0;
    if (pq->size == 0)
    {
        printf("-1\n");
        return;
    }
    tempp++;
    flag = tempp;

    printf("%d %s\n", pq->arr[0].id, pq->arr[0].name);
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    min_heapify(pq, 0);
}

void Update_Severity(struct pq *pq, int id, int s2)
{
    int tempp = 0;
    int flag = 0;
    int index = -1;
    for (int i = 0; i < pq->size; i++)
    {
        if (pq->arr[i].id == id)
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

    int s1 = pq->arr[index].sev;
    pq->arr[index].sev = s2;

    if (s2 < s1)
    {
        while (index != 0 && pq->arr[(index - 1) / 2].sev > pq->arr[index].sev)
        {
            reverse(&pq->arr[index], &pq->arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    else
    {
        min_heapify(pq, index);
    }
    tempp++;
    flag = tempp;

    display_(pq);
}

void ask_Patient(struct pq *pq, int id)
{
    int tempp = 0;
    int flag = 0;
    for (int i = 0; i < pq->size; i++)
    {
        if (pq->arr[i].id == id)
        {
            printf("%s %d\n", pq->arr[i].name, pq->arr[i].sev);
            return;
        }
    }

    printf("-1\n");
}

void Find_Most_Severe(struct pq *pq)
{
    int tempp = 0;
    int flag = 0;
    if (pq->size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d %s %d\n", pq->arr[0].id, pq->arr[0].name, pq->arr[0].sev);
    if (pq->size == 1)
        return;
    if (pq->size == 2)
    {
        printf("%d %s %d\n", pq->arr[1].id, pq->arr[1].name, pq->arr[1].sev);
        return;
    }
    if (pq->size >= 3)
    {
        if (pq->arr[1].sev > pq->arr[2].sev)
        {
            printf("%d %s %d\n", pq->arr[2].id, pq->arr[2].name, pq->arr[2].sev);
        }
        else
        {
            printf("%d %s %d\n", pq->arr[1].id, pq->arr[1].name, pq->arr[1].sev);
        }
        if (pq->arr[1].sev > pq->arr[2].sev)
        {
            printf("%d %s %d\n", pq->arr[1].id, pq->arr[1].name, pq->arr[1].sev);
        }
        else
        {
            printf("%d %s %d\n", pq->arr[2].id, pq->arr[2].name, pq->arr[2].sev);
        }
    }
    tempp++;
    flag = tempp;
}

int main()
{
    int tempp = 0;
    int flag = 0;
    struct pq pq = {.size = 0};
    char ch;
    int id, sev, s2;
    char name[100];

    while (scanf(" %c", &ch) != EOF)
    {
        switch (ch)
        {
        case 'a':
            scanf("%d %d %s", &id, &sev, name);
            Add_Patient(&pq, id, name, sev);

            break;
        case 'b':
            extract(&pq);
            break;
        case 'c':
            scanf("%d %d", &id, &s2);
            Update_Severity(&pq, id, s2);
            break;
        case 'd':
            scanf("%d", &id);
            ask_Patient(&pq, id);
            break;
        case 'e':
            Find_Most_Severe(&pq);
            break;
        case 'g':
            return 0;
        }
    }
    tempp++;
    flag = tempp;

    return 0;
}