// DIDNT YET START

#include<stdio.h>
#include<limits.h>

/*Declaring heap globally so that we do not need to pass it as an argument every time*/
/* Heap implemented  here is Min Heap */

int heap[1000000], heapSize;
/*Initialize Heap*/
void Init() {
    heapSize = 0;
    heap[0] = -INT_MAX;
}

/*Insert an element into the heap */
void Insert(int element) {
    heapSize++;
    heap[heapSize] = element; /*Insert in the last place*/
    /*Adjust its position*/
    int now = heapSize;
    while (heap[now / 2] > element) {
        heap[now] = heap[now / 2];
        now /= 2;
    }
    heap[now] = element;
}

void printheap() {
        for (int i = 1; i <= heapSize; i++) {
                printf("%d", heap[i]);
        }
}

int main() {
    int number_of_elements;
    int iter, element;
    Init();
    //int
    for (iter = 0; iter < number_of_elements; iter++) {
        scanf("%d", &element);
        Insert(element);
    }
    printf("heapsize:%d \n", heapSize);
    printheap();
    printf("\n");
    printf("heapsize:%d \n", heapSize);
    for (iter = 0; iter < number_of_elements; iter++) {
        printf("%d ", DeleteMin());
    }
    printf("last print heap o/p");
    printheap();
    printf("\n");
    return 0;
}
