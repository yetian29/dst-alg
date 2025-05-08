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

void out(bucket *b)
{
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
    bucket *bucket = initializeBucket(capacity);
    append(bucket, 1);
    append(bucket, 2);
    append(bucket, 3);
    out(bucket);
    // freeBucket(bucket);
    return 0;
}

