#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct stack {
        int data[MAX];
        int top;
}typedef stack;

void push (stack *s, int ele) {
        if (s->top+1 == MAX) {
                printf("stack full");
                return;
        } else {
                s->data[s->top++] = ele;
        }
        return;

}

int pop (stack *s) {
        if (s->top == -1) {
                //printf("stack empty");
                return -1;
        } else {
                int tmp = s->data[s->top];
                s->top--;
                return tmp;
        }
}

stack * sort(stack *s) {
        stack *t = (stack *)malloc(sizeof(stack));
        t->top = -1;
        int lin;
        int ltmp;
        int tmp;
        push(t, pop(s));
        while(s->top != -1) {
check:
                lin = pop(s);
                ltmp = pop(t);
                /*
                if (ltmp == 0)
                        push(t, lin);
                        */
                if (lin >= ltmp) {
                        push(t, ltmp);
                        push(t, lin);
                } else {
                        tmp = ltmp;
                        push(s, ltmp);
                        goto check;
                }
        }
        return t;
}

int main() {
        stack *s = (stack *)malloc(sizeof(stack));
        int n = MAX;
        s->top = -1;
        for (int i = 0 ; i < MAX; i++) {
        push(s, n--);
        }/*
        printf("%d\n", s->top);
        for (int i = 0 ; i < MAX; i++) {
        printf("%d %d\n", pop(s), s->top);
        }
        return 0;
        */
        stack *t = sort(s);
        printf("%d\n", t->top);
        for (int i = 0 ; i < MAX; i++) {
        printf("%d %d\n", pop(t), t->top);
        }
        return 0;
        /*
        for (int i = 0 ; i < MAX; i++) {
        printf("%d ", t->data[i]);
        }
        */
}
