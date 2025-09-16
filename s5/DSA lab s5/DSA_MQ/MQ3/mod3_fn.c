
#include <stdio.h>
#include <stdlib.h>

struct hashtable {
    int capacity;
    int size;
    int *arr;
};


struct hashtable *create(int capacity) {
    struct hashtable *ht = (struct hashtable *)malloc(sizeof(struct hashtable));
    ht->size = 0;
    ht->capacity = capacity;
    ht->arr = (int *)malloc(sizeof(int) * capacity);
    for (int i = 0; i < capacity; i++) {
        ht->arr[i] = -1; 
    }
    return ht;
}

int hash(int data,int n)
{
    return data%n;
}
void rehash(struct hashtable *ht) {
    int old_capacity = ht->capacity;
    int new_capacity = old_capacity * 2;
    int *old_arr = ht->arr;

    ht->arr = (int *)malloc(sizeof(int) * new_capacity);
    ht->capacity = new_capacity;
    ht->size = 0;

    for (int i = 0; i < new_capacity; i++) {
        ht->arr[i] = -1; 
    }


    for (int i = 0; i < old_capacity; i++) {
        if (old_arr[i] != -1) {
            
            int data = old_arr[i];
            int index = hash(data, new_capacity);
            int i=index;
            int j = 1;
            while (ht->arr[index] != -1) {
                index = (i + j * j) % new_capacity; 
                j++;
            }
            ht->arr[index] = data;
            ht->size++;
        }
    }

    free(old_arr);
}


void insert(struct hashtable *ht,  int data) {
    if (ht->size >= ht->capacity * 0.75) {
        rehash(ht);
    }

    int index = hash(data, ht->capacity);
    int i=index;
    int j=1;
    
    while (ht->arr[index] != -1) {
        index = (i + j * j) % ht->capacity; 
        j++;
    }
    ht->arr[index] = data;
    ht->size++;
}


void display(struct hashtable *ht) {
    for (int i = 0; i < ht->capacity; i++) {
        printf("%d ", ht->arr[i]);
    }
    printf("\n");
}


int main() {
    int capacity;
    int data;
    scanf("%d", &capacity);
    struct hashtable *ht = create(capacity);
    char command;
    
    while (scanf(" %c", &command) != EOF) {
        switch (command) {
        case 'i':
            scanf("%d", &data);
            insert(ht, data);
            break;
        case 'd':
            display(ht);
            break;
        case 'e':
            free(ht->arr); 
            free(ht); 
            return 0;
        }
    }

    free(ht->arr); 
    free(ht);
    return 0;
}
