#include <stdio.h>
#include <stdlib.h>

struct hashtable {
    int capacity;
    int size;
    long long int *arr;
};


struct hashtable *create(int capacity) {
    struct hashtable *ht = (struct hashtable *)malloc(sizeof(struct hashtable));
    ht->size = 0;
    ht->capacity = capacity;
    ht->arr = (long long int *)malloc(sizeof(long long int) * capacity);
    for (int i = 0; i < capacity; i++) {
        ht->arr[i] = -1; 
    }
    return ht;
}

// // Function to sum the parts of the Aadhaar number
// int hash(long long int aadhaar, int m) {
//     int part1 = (aadhaar / 10000000000LL) % 10000; // First 4 digits
//     int part2 = (aadhaar / 100000000) % 10000; // Next 4 digits
//     int part3 = aadhaar % 10000; // Last 4 digits
//     int sum = part1 + part2 + part3;
//     return sum % m; // Hash value
// }
int hash(long long int num,int n)
{
    
    int arr[12]={0};
    int index=11;
    while(num>0 && index>=0)
    {
        int r=num%10;
        arr[index--]=r;
        num=num/10;

    }
    
    int x1=0;
    int x2=0;
    int x3=0;
    for(int i=0;i<=3;i++)
    {
        x1=x1*10+arr[i];
    }
    for(int i=4;i<=7;i++)
    {
        x2=x2*10+arr[i];
    }
    for(int i=8;i<=11;i++)
    {
        x3=x3*10+arr[i];
    }
    return (x1+x2+x3)%n;
}

void rehash(struct hashtable *ht) {
    int old_capacity = ht->capacity;
    int new_capacity = old_capacity * 2;
    long long int *old_arr = ht->arr;

    ht->arr = (long long int *)malloc(sizeof(long long int) * new_capacity);
    ht->capacity = new_capacity;
    ht->size = 0;

    for (int i = 0; i < new_capacity; i++) {
        ht->arr[i] = -1; 
    }

    
    for (int i = 0; i < old_capacity; i++) {
        if (old_arr[i] != -1) {
          
            long long int data = old_arr[i];
            int index = hash(data, new_capacity);
            int j = 1;
            int i=index;
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


void insert(struct hashtable *ht, long long int aadhaar) {
    if (ht->size >= ht->capacity * 0.6) {
        rehash(ht);
    }

    int index = hash(aadhaar, ht->capacity);
    int i=index;
    int j = 1;
    while (ht->arr[index] != -1) {
        index = (i + j * j) % ht->capacity; 
        j++;
    }
    ht->arr[index] = aadhaar;
    ht->size++;
}

// Function to display the hash table
void display(struct hashtable *ht) {
    for (int i = 0; i < ht->capacity; i++) {
        printf("%lld ", ht->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int capacity;
    long long int data;
    scanf("%d", &capacity);
    struct hashtable *ht = create(capacity);
    char command;
    
    while (scanf(" %c", &command) != EOF) {
        switch (command) {
        case 'i':
            scanf("%lld", &data);
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
