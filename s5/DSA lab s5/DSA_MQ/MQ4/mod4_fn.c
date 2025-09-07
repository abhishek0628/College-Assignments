
#include <stdio.h>
#include <stdlib.h>

struct node {
    int task_id;
    int priority;
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

    if (left < h->size && h->arr[left].priority > h->arr[largest].priority)
        largest = left;

    if (right < h->size && h->arr[right].priority > h->arr[largest].priority)
        largest = right;

    if (largest != i) {
        swap(&h->arr[i], &h->arr[largest]);
        maxHeapify(h, largest);
    }
}

void insert(struct heap *h, int task_id, int priority) {
    if (h->size == h->capacity) {
        printf("Heap is full\n");
        return;
    }

    int i = h->size++;
    h->arr[i].task_id = task_id;
    h->arr[i].priority = priority;

    while (i != 0 && h->arr[(i - 1)/2].priority < h->arr[i].priority) {
        swap(&h->arr[i], &h->arr[(i - 1)/2]);
        i = (i - 1)/2;
    }
}
void update(struct heap *heap,int task_id,int priority)
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
    
    
    heap->arr[i].priority=priority;
    // int parent=(i-1)/2;
    if(priority>heap->arr[(i-1)/2].priority)
    {
        while(i!=0 && heap->arr[(i-1)/2].priority<heap->arr[i].priority)
        {
            swap(&heap->arr[i],&heap->arr[(i-1)/2]);
            i=(i-1)/2;

        }
    }
    else maxHeapify(heap,i);
}
int cousins(struct heap *heap,int task_id1,int task_id2)
{
    if(heap==NULL)return 0;
    int i,j;
    for(i=0;i<heap->size;i++)
    {
        if(heap->arr[i].task_id==task_id1)
        {
            break;
        }

    }
    for(j=0;j<heap->size;j++)
    {
        if(heap->arr[j].task_id==task_id1)
        {
            break;
        }

    }
    int max=i>j?i:j;
    if(max==2*i+1 || max==2*i+2||max==2*j+1||2*j+2)
    {
        return 1;
    }
    return 0;
}

void display(struct heap *h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i].task_id);
    }
    printf("\n");
}

void extracted(struct heap *h) {
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
    int task_id, priority,task_id2;
    char ch;

    while (scanf(" %c", &ch) != EOF) {
        switch (ch) {
            case 'i':
                scanf("%d%d", &task_id, &priority);
                insert(h, task_id, priority);
                break;
            case 's':
                display(h);
                break;
            case 'd':
                extracted(h);
                break;
            case 'u':scanf("%d%d",&task_id,&priority);
                     update(h,task_id,priority);
                     break;
            case 'c':scanf("%d%d",&task_id,&task_id2);
                     int r=cousins(h,task_id,task_id2);
                     if(r==1)printf("Yes\n");
                     else printf("no\n");
                     break;
            case 'e':
                return 0;
        }
    }

    return 0;
}
