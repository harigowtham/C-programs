/*
#include<stdio.h>
static int queue[5];
static  int cap = 5;
//t size = 0;
static       int front = -1;
static int rear = -1;
void enqueue(int q[], int data) {
        if (rear == cap-1)
                printf("q full");
        else {
                q[rear] = data;
                rear = (rear+1);
                printf("rear:%d\n", rear);
        }
}
void dequeue(int q[]) {
        if (front ==-1 || front > rear)
                printf("queue empty");
        else {
                q[front]=0;
                front = front+1;
                printf("front:%d\n", front);
        }
}
void printq(int q[]) {
        for(int i = front; i<(rear+1); i++) {
                printf("%d,", q[i]);
        }
}
int main() {
        enqueue(queue,1);
        enqueue(queue,2);
        enqueue(queue,3);
        enqueue(queue,4);
        printq(queue);
        dequeue(queue);
//        enqueue(queue,5);
//        enqueue(queue,10);
        printq(queue);
        return 0;
}
*/
/*
 * C Program to Implement a Queue using an Array
 */
#include <stdio.h>

#define MAX 50
int queue_array[MAX];
int rear = - 1;
int front = - 1;
main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        } /*End of switch*/
    } /*End of while*/
} /*End of main()*/
insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        /*If queue is initially empty */
        front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} /*End of insert()*/

delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
} /*End of delete() */
display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} /*End of display() */
