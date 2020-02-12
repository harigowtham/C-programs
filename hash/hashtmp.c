#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);


// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}

void arr_int(int size, int* arr) {
    int i;
    printf("arr size:%d\n", size);

    for (i= 0; i < size; i++) {
        arr[i] = 0;
    }
}

void hash(int requestTime_count, int* requestTime, int* arr) {
    int i, a;
    printf("arr size:%d\n", requestTime_count);

    for (i= 0; i < requestTime_count; i++) {
        a = requestTime[i];
//    printf("a:%d\n", a);
        arr[a] = arr[a] + 1;
    }
}

int hash_1(int size, int* arr) {
    int i, drop_1, tmp;
    printf("arr size:%d\n", size);

    for (i= 0; i < size; i++) {
        if (arr[i] > 3) {
                drop_1 = arr[i] - 3;
                printf("droped:%d\n", drop_1);
                arr[i] = 3;

        }}
    return drop_1;
}


int hash_2(int size, int* arr) {
    int i, drop_2, dec;
    int count =0;
    int dec_count =0;
    int tmp = 1;
    printf("arr size:%d\n", size);

    for (i= 0; i < size; i++) {
            if (arr[i] != 0) {
        count = arr[i] + count;
            }
    }
    printf("count:%d\n", count);
    i--;
check:
    printf("a[i]:%d\n", arr[i]);
    while (arr[i] > 0 && count > 20 )  {
    printf("a[i]:%d\n", arr[i]);
            arr[i] = (arr[i])-1;
            dec_count++;
            tmp = count - dec_count-1;
    }
    printf("count:%d\n", count);
    printf("dec_count:%d\n", dec_count);
    count = count - dec_count;
    printf("count:%d\n", count);
    printf("dec_count:%d\n", dec_count);
    if (count > 20) {
            i--;
            goto check;
    }
                printf("droped:%d\n", dec_count);
    return dec_count;
}


int hash_3(int size, int* arr) {
    int i, drop_2, dec;
    int count =0;
    int dec_count =0;
    int tmp = 1;
    printf("arr size:%d\n", size);

    for (i= 0; i < size; i++) {
            if (arr[i] != 0) {
        count = arr[i] + count;
            }
    }
    printf("count:%d\n", count);
    i--;
check:
    printf("a[i]:%d\n", arr[i]);
    while (arr[i] > 0 && count > 60 )  {
    printf("a[i]:%d\n", arr[i]);
            arr[i] = (arr[i])-1;
            dec_count++;
            tmp = count - dec_count-1;
    }
    printf("count:%d\n", count);
    printf("dec_count:%d\n", dec_count);
    count = count - dec_count;
    printf("count:%d\n", count);
    printf("dec_count:%d\n", dec_count);
    if (count > 60) {
            i--;
            goto check;
    }
                printf("droped:%d\n", dec_count);
    return dec_count;
}

// Complete the droppedRequests function below.
int droppedRequests(int requestTime_count, int* requestTime) {
    int txn, i, j, last_req;
    int  drop_1 =0;
    int drop_2= 0;
    int drop_3= 0;
    int dropped_so_far = 0;
    int sec_1,sec_10, sec_60;
    quickSort(requestTime, 0, requestTime_count-1);
    int hashsize = (requestTime[requestTime_count - 1] + 1);
    printf("hash size:%d\n", hashsize);
    int hasharr[hashsize];
    arr_int(hashsize,hasharr);
    printf("arry:\n:");
    printArray(requestTime, requestTime_count);
    printf("sorted:\n");
    printArray(requestTime, requestTime_count);
    hash(requestTime_count,requestTime, hasharr);
    printf("\nhased:\n");
    printArray(hasharr, hashsize);
    printf("\nhased_1:\n");
    drop_1 = hash_1(hashsize, hasharr);
                printf("dropped_so_far:%d\n", drop_1);
    printArray(hasharr, hashsize);
    printf("\nhased_2:\n");
    drop_2 = hash_2(hashsize, hasharr);
                printf("dropped_so_far:%d\n", drop_2);
    dropped_so_far = drop_1 + drop_2;
    printArray(hasharr, hashsize);
    printf("droped_so_far:%d\n", dropped_so_far);
    printf("\nhased_3:\n");
    drop_3 = hash_3(hashsize, hasharr);
                printf("dropped_so_far:%d\n", drop_3);
    dropped_so_far = drop_1 + drop_2 + drop_3;
    printArray(hasharr, hashsize);
    printf("droped_so_far:%d\n", dropped_so_far);
    /*
    last_req = requestTime[0];
    while (i< requestTime_count) {
        last_req = requestTime[i];
        while (last_req == requestTime[j]) {
            j++;
            if (j < 3) {
                sec_1++;
            }
        }
        while (per_10sec == requestTime[k]) {
            k++;
        }
        i = j;

    }
    */
    return 1;

}

int main()
{
        /*
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* requestTime_count_endptr;
    char* requestTime_count_str = ltrim(rtrim(readline()));
    int requestTime_count = strtol(requestTime_count_str, &requestTime_count_endptr, 10);

    if (requestTime_count_endptr == requestTime_count_str || *requestTime_count_endptr != '\0') { exit(EXIT_FAILURE); }

    int* requestTime = malloc(requestTime_count * sizeof(int));

    for (int i = 0; i < requestTime_count; i++) {
        char* requestTime_item_endptr;
        char* requestTime_item_str = ltrim(rtrim(readline()));
        int requestTime_item = strtol(requestTime_item_str, &requestTime_item_endptr, 10);

        if (requestTime_item_endptr == requestTime_item_str || *requestTime_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(requestTime + i) = requestTime_item;
    }
    */
    int requestTime[24] = {1,1,1,1,2,2,2,3,3,3,6,6,6,5,5,5,4,4,7,7,7,8,8,8};
    int requestTime_count = sizeof(requestTime)/sizeof(requestTime[0]);

    int res = droppedRequests(requestTime_count, requestTime);
/*
    fprintf(fptr, "%d\n", res);

    fclose(fptr);
*/
    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

