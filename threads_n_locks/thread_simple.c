#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    sleep(1);
    printf("Printing GeeksQuiz from Thread \n");
    return NULL;
}

int main()
{
    pthread_t thread_id;
    printf("Before Thread\n");
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    pthread_join(thread_id, NULL);
    printf("After Thread\n");
    exit(0);
}

/* arg:
 * 1:  pointer to thread_id which is set by this function
 * 2: specifies attributes. If the value is NULL, then default attributes shall be used.
 * 3:  name of function to be executed for the thread to be created.
 * 4: used to pass arguments to the function, myThreadFun.
 * */

/* The pthread_join() function for threads is the equivalent of wait() for processes. A call to pthread_join blocks the calling thread until the thread with identifier equal to the first argument terminates.*/

/* the way you compile this is different
 * gcc thread_simple.c -lpthread
 * we are linking pthread to get those executables
 * more about it on https://www.geeksforgeeks.org/multithreading-c-2/
 * */
