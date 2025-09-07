#include <stdio.h>
#include <stdlib.h>

struct node {
    int task_id;
    int urgency;
};

struct heap {
    struct node *arr;
    int size;
    int capacity;
};

struct heap *create(int capacity) {
    struct heap *h = (struct heap *)malloc(sizeof(struct heap));
    h->size = 0;
    h->capacity = capacity;
    h->arr = (struct node *)malloc(sizeof(struct node) * capacity);
    return h;
}

void swap(struct node *a, struct node *b) {
    struct node temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(struct heap *h, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < h->size && h->arr[left].urgency > h->arr[largest].urgency)
        largest = left;

    if (right < h->size && h->arr[right].urgency > h->arr[largest].urgency)
        largest = right;

    if (largest != i) {
        swap(&h->arr[i], &h->arr[largest]);
        maxHeapify(h, largest);
    }
}

void AddTask(struct heap *h, int task_id, int priority) {
    if (h->size == h->capacity) {
        printf("Heap is full\n");
        return;
    }

    int i = h->size++;
    h->arr[i].task_id = task_id;
    h->arr[i].urgency = priority;

    while (i != 0 && h->arr[(i - 1)/2].urgency < h->arr[i].urgency) {
        swap(&h->arr[i], &h->arr[(i - 1)/2]);
        i = (i - 1)/2;
    }
}
void updateUrgency(struct heap *heap,int task_id,int priority)
{
    int found=0;
    if(heap==NULL)
    {
        printf("-1\n");
        return;
    }
    int i;
    for( i=0;i<heap->size;i++)
    {
        if(heap->arr[i].task_id==task_id)
        {
            found=1;
            printf("%d\n",task_id);
            break;
        }
        
    }
    if(found==0)
    {
        printf("-1\n");
        return;
    }
    
    
    heap->arr[i].urgency=priority;
    // int parent=(i-1)/2;
    if(priority>heap->arr[(i-1)/2].urgency)
    {
        while(i!=0 && heap->arr[(i-1)/2].urgency<heap->arr[i].urgency)
        {
            swap(&heap->arr[i],&heap->arr[(i-1)/2]);
            i=(i-1)/2;

        }
    }
    else maxHeapify(heap,i);
}


void display(struct heap *h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i].task_id);
    }
    printf("\n");
}

void deleteUrgency(struct heap *h) {
    if (h->size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", h->arr[0].task_id);
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    maxHeapify(h, 0);
}

int main() {
    struct heap *h = create(100);
    int task_id, urgency,task_id2;
    char ch;

    while (scanf(" %c", &ch) != EOF) {
        switch (ch) {
            case 'i':
                scanf("%d%d", &task_id, &urgency);
                AddTask(h, task_id, urgency);
                break;
            case 's':
                display(h);
                break;
            case 'd':
                deleteUrgency(h);
                break;
            case 'u':scanf("%d%d",&task_id,&urgency);
                     updateUrgency(h,task_id,urgency);
                     break;
          
            case 'e':
                return 0;
        }
    }

    return 0;
}
