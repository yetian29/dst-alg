// Array one dimensional

// #include <stdio.h>

// int main(void)
// {
//     int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     int size = sizeof(array) / sizeof(array[0]);
//     // printf("Address base: %p\n", array);
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d\n", array[i]);
//         printf("%p\n", (char *)array + (i * sizeof(int)));
//         // if (i + 1 < size) printf(" | ");
//     }
//     printf("\n");

//     return 0;

// }


// Array two dimensional
// #include <stdio.h>
// int main(void)
// {
//     int array[2][3] = {1, 2, 3, 4, 5, 6};
//     int row = 2, column = 3;
//     int size = sizeof(array) / sizeof(array[0][0]);

//     printf("Size: %d\n", size);
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < column; j++)
//         {
//             printf("%d\n", array[i][j]);
//             printf("%p\n", (char *)array + (sizeof(int) * (i * column + j)));
//             // if (array[i][j] != array[2][2]) printf(" | ");
//         }
//     }
//     printf("\n");

//     return 0;

// }


// Array dynamic
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct
{
    int capacity; // capacity of bucket 
    int tail;  // index tail of array items
    int size; // size of array items
    int *items; // array items
} bucket;

bucket *initializeBucket(int capacity)
{
    bucket *b = malloc(sizeof(bucket));
    if (!b)
    {
        fprintf(stderr, "Allocation memory for bucket failed\n");
        exit(1);
    }
    b->capacity = capacity;
    b->tail = 0; // array items initial is empty
    b->size = 0; // size is 0 because initial array items is empty
    b->items = malloc(b->capacity * sizeof(int));
    if (!b->items)
    {
        fprintf(stderr, "Allocation memory for bucket items failed\n");
        free(b);
        exit(1);
    }
    return b;
}

bool isFull(bucket *b)
{
    return b->size == b->capacity;
}

bool isEmpty(bucket *b)
{
    return b->size == 0;
}

void append(bucket *b, int item)
{
    // Bucket is full
    if (isFull(b))
    {
        b->capacity *= 2;
        b->items = realloc(b->items, b->capacity * sizeof(int));
    }
    b->items[b->tail] = item;
    b->tail++;
    b->size++;

}

void extend(bucket *b, int array[], int lengthArray)
{
    for (int j = 0; j < lengthArray; j++)
    {
        b->items[b->tail] = array[j];
        b->tail++;
        b->size++;
    }


}

void insert(bucket *b, int position, int item)
{
   
    if (b->size == b->capacity)
    {
        b->capacity *= 2;
        b->items = realloc(b->items, b->capacity * sizeof(int));
    }

    for (int i = position; i < b->tail; i++)
    {
        b->items[i + 1] = b->items[i]; // Move right to get the blank cell to insert
    }
    b->items[position] = item;
    b->tail++;
    b->size++;
    
}

void removeItem(bucket *b, int item)
{
    for (int i = 0; i < b->tail; i++)
    {
        if (b->items[i] == item)
        {
            b->items[i] = 0; // case deleted           
        
            for (int j = i; j < b->tail; j++)
            {
                b->items[j] = b->items[j + 1];
            }
            b->tail--;
            b->size--;
            return;
        }

    }
    fprintf(stderr, "Not found item need to remove in bucket\n");
    exit(1);

}

void pop(bucket *b, int position)
{
    if (position < 0 || position >= b->tail)
    {
        fprintf(stderr, "Bucket is empty or index is outside the bucket\n");
        exit(1);
    }
    for (int i = position; i < b->tail; i++)
    {
        b->items[i] = b->items[i+1]; // Move left to fill blank cell 
    }
    b->tail--;
    b->size--;

    
}

void clear(bucket *b)
{ 
    b->tail = 0;
    b->size = 0;   
}

int indx(bucket *b, int item)
{
    for (int i = 0; i < b->tail; i++)
    {
        if (b->items[i] == item) return i;
    }
    fprintf(stderr, "There is no such item\n");
    exit(1);
}

int count(bucket *b, int item)
{
    int c = 0;
    for (int i = 0; i < b->tail; i++)
    {
        if (b->items[i] == item) c++;
    }
    return c;
}


void  reverse(bucket *b, int low, int high)
{
   
    // int ptr_head = low;
    // int ptr_tail = high;
    // while (ptr_head <= ptr_tail)
    // {
    //     int tmp =  b->items[ptr_head];
    //     b->items[ptr_head] = b->items[ptr_tail];
    //     b->items[ptr_tail] = tmp;
    //     ptr_head++;
    //     ptr_tail--;
    // }


    // Base case recursive
    if (low >= high) return; 
    // Recursive
    int tmp = b->items[low];
    b->items[low] = b->items[high];
    b->items[high] = tmp;
    reverse(b, low + 1, high - 1);    
       
}


void out(bucket *b)
{
    if (isEmpty(b))
    {
        printf("Bucket is empty\n");
        return;
    }
    printf("Size array: %d, Capacity: %d, Tail: %d\n", b->size, b->capacity, b->tail);
    for (int i = 0; i < b->tail; i++)
    {
        printf("%d", b->items[i]);
        if (i + 1 < b->tail) printf(" | ");
    }
    printf("\n");
}

void freeBucket(bucket *b)
{
    free(b->items);
    free(b);
}

int main(void)
{
    int capacity = 1;
    int array[] = {6, 7, 8, 9};
    int lengthArray = sizeof(array) / sizeof(array[0]);
    bucket *bucket = initializeBucket(capacity);
    // append(bucket, 1);
    // append(bucket, 2);
    // append(bucket, 3);
    // append(bucket, 4);
    // append(bucket, 5);
    // out(bucket);
    // extend(bucket, array, lengthArray);
    // out(bucket);
    insert(bucket, 0, 1);
    insert(bucket, 0, 2);
    insert(bucket, 2, 3);
    insert(bucket,2, 3);
    out(bucket);
    // removeItem(bucket , 2);
    // removeItem(bucket, 5);
    // out(bucket);
    // pop(bucket, -1);
    // pop(bucket , 3);
    // pop(bucket, 0);
    // pop(bucket, 2);
    // out(bucket);
    // clear(bucket);
    // out(bucket);
    // append(bucket, 5);
    // out(bucket);
    // int i  = indx(bucket, 5);
    // int i = indx(bucket, 1);
    // printf("Index: %d\n", i);
    // int c = count(bucket, 3);
    // printf("Count: %d\n", c);

    reverse(bucket, 0, bucket->size - 1);
    out(bucket);
    freeBucket(bucket);
    return 0;
}

