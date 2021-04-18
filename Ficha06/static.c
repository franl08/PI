#include <stdlib.h>
#include <stdio.h>

#define MAX 100

typedef struct staticStack{
    int sp;
    int values[MAX];
} STACK, *SStack;

typedef struct staticQueue{
    int front;
    int length;
    int values[MAX];
} QUEUE, *SQueue;

void SinitStack(SStack s){
    s->sp = 0;
}

int SisEmpty(SStack s){
    return (s->sp == 0);
}

int Spush(SStack s, int x){
    int pos = s->sp++;
    if (pos != MAX){
        s->values[pos] = x;
        return 0;
    }
    else return 1;
}

int Spop(SStack s, int* x){
    if(--(s->sp) > 0){
        *x = s->values[s->sp];
        return 0;
    }
    else return 1;
}

int Stop(SStack s, int* x){
    if(s->sp != 0){
        *x = s->values[s->sp - 1];
        return 0;
    }
    else return 1;
}

void SinitQueue(SQueue q){
    q->length = 0;
}

int SisEmptyQ(SQueue q){
    return (q->length == 0);
}

int Senqueue(SQueue q, int x){
    if(q->front + q->length >= MAX) return 1;
    else{
        q->values[q->front + q->length++] = x;
        return 0;
    }
}

int Sdequeue(SQueue q, int* x){
    if(q->length == 0) return 1;
    else{
        *x = q->values[(q->front)++];
        return 0;
    }
}

int Sfront(SQueue q, int* x){
    if(q->length == 0) return 1;
    else{
        *x = q->values[q->front];
        return 0;
    }
}