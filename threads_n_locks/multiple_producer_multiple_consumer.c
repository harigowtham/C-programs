#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear =-1;

pthread_t tidp[2];
pthread_t tidc[2];
int counter;
pthread_mutex_t lock;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;

int isFull()
{
    if( (front == rear + 1) || (front == 0 && rear == SIZE-1)) return 1;
    return 0;
}

int isEmpty()
{
    if(front == -1) return 1;
    return 0;
}

void enQueue(int element)
{
    if(isFull()) printf("\n Queue is full!! \n");
    else
    {
        if(front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n Inserted -> %d", element);
    }
}


int deQueue()
{
    int element;
    if(isEmpty()) {
        printf("\n Queue is empty !! \n");
        return(-1);
    } else {
        element = items[front];
        if (front == rear){
            front = -1;
            rear = -1;
        } /* Q has only one element, so we reset the queue after dequeing it. ? */
        else {
            front = (front + 1) % SIZE;

        }
        printf("\n Deleted element -> %d \n", element);
        return(element);
    }
}




void display()
{
    int i;
    if(isEmpty()) printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ",front);
        printf("\n Items -> ");
        for( i = front; i!=rear; i=(i+1)%SIZE) {
            printf("%d ",items[i]);
        }
        printf("%d ",items[i]);
        printf("\n Rear -> %d \n",rear);
    }
}

void* produce(void* arg)
{
	pthread_mutex_lock(&lock);

        while (!isEmpty)
                pthread_cond_wait(&not_full, &lock);
	printf("\n produce %d has started\n", counter);
        counter++;
        enQueue(1);
        enQueue(2);
        enQueue(3);
        enQueue(4);

	printf("\n produce %d has finished\n", counter);

        pthread_cond_signal(&not_empty);
	pthread_mutex_unlock(&lock);

	return NULL;
}

void* consume(void* arg)
{
	pthread_mutex_lock(&lock);

        while (!isFull)
                pthread_cond_wait(&not_empty, &lock);
	printf("\n consume %d has started\n", counter);
        counter++;
        deQueue();
        deQueue();
        deQueue();

	printf("\n consume %d has finished\n", counter);

        pthread_cond_signal(&not_full);
	pthread_mutex_unlock(&lock);

	return NULL;
}

int main(void)
{
	int i = 0;
	int j = 0;
	int error;
        display();
	if (pthread_mutex_init(&lock, NULL) != 0) {
		printf("\n mutex init has failed\n");
		return 1;
	}

	while (i < 2) {
        error = pthread_create(&(tidp[i]),
                        NULL,
                        &produce, NULL);
        if (error != 0)
                printf("\nThread can't be created :[%s]",
                                strerror(error));
        i++;
        }

	while (j < 2) {
        error = pthread_create(&(tidc[j]),
                        NULL,
                        &consume, NULL);
        if (error != 0)
                printf("\nThread can't be created :[%s]",
                                strerror(error));
        j++;
        }

	pthread_join(tidp[0], NULL);
	pthread_join(tidc[0], NULL);
	pthread_join(tidp[1], NULL);
	pthread_join(tidc[1], NULL);
	pthread_mutex_destroy(&lock);
        display();

	return 0;
}

//edited the single producer and single consumer to multiple ones. will try to work on the simpler ones soon
