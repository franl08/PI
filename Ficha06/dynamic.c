#include <stdlib.h>
#include <stdio.h>


typedef struct dinStack{
    int size;
    int sp;
    int *values;
} *DStack;

typedef struct dinQueue{
    int size;
    int front;
    int length;
    int *values;
} *DQueue;

void initStack(DStack s){
    s->size = 1;
    s->sp = 0;
    s->values = malloc(sizeof(int));
}

int isEmpty(DStack s){
    return (s->sp == 0);
}

int push(DStack s, int x){
    if(s->sp >= s->size){
        realloc(s->values, s->size * 2 * sizeof(int));
        s->size *= 2;
    }
    s->values[s->sp++] = x;
    return 0;
}

int pop(DStack s, int *x){
    if (--(s->sp) <= 0) return 1;
    else{
        *x = s->values[s->sp];
        return 0;
    }
}

int top(DStack s, int *x){
    if(s->sp - 1 <= 0) return 1;
    else{
        *x = s->values[s->sp - 1];
        return 0;
    } 
}

void initQueue(DQueue q){
    q->size = 0;
    q->length = q->front;
    q->values = malloc(q->front * sizeof(int));
}

int isEmptyQ(DQueue q){
    return (q->length == 0);
}

int enqueue(DQueue q, int x){
    if(q->size <= q->length + q->front){
        q->values = realloc(q->values, 2 * q->size * sizeof(int));
        q->size *= 2;
    }
    q->values[q->front + q->length++] = x;
    return 0;
}

int dequeue(DQueue q, int *x){
    if(q->length == 0) return 1;
    else{
        *x = q->values[q->front + --(q->length)];
        return 0; 
    }
}

int front(DQueue q, int* x){
    if (q->length == 0) return 1;
    else{
        *x = q->values[q->front];
        return 0;
    }
}