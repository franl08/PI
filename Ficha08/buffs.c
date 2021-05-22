#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct slist{
    int valor;
    struct slist * prox;
} * LInt;

LInt newLInt(int x, LInt xs){
    LInt r = malloc(sizeof(struct slist));
    if(r){
        r->valor = x;
        r->prox = xs;
    }
    return r;    
}

typedef LInt Stack;

typedef struct{
    LInt inicio, fim;
} Queue;

typedef LInt QueueC;

void initStack(Stack *s){
    *s = NULL;
}

int SisEmpty(Stack s){
    return (s == NULL);
}

int push(Stack *s, int x){
    Stack aux = malloc(sizeof(Stack));
    if(!aux) return 1;
    aux = newLInt(x, *s);
    return 0;
}

int pop(Stack *s, int *x){
    if(!*s) return 1;
    *x = (*s)->valor;
    Stack tmp = *s;
    *s = (*s)->prox;
    free(tmp);
    return 0;
}

int top(Stack s, int *x){
    if(!s) return 1;
    *x = s->valor;
    return 0;
}

void initQueue(Queue *q){
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty(Queue q){
    return (q.inicio == NULL && q.fim == NULL);
}

int enqueue(Queue *q, int x){
    LInt tmp = malloc(sizeof(struct slist));
    if(!tmp) return 1;
    tmp->valor = x;
    tmp->prox = NULL;
    if(!q->fim){
        q->inicio = q->fim = tmp;
    }
    else{
        q->fim->prox = tmp;
        q->fim = tmp;
    }
    return 0;
}

int dequeue(Queue *q, int* x){
    if(!q->inicio) return 1;
    *x = q->inicio->valor;
    LInt tmp = q->inicio;
    q->inicio = q->inicio->prox;
    if (!q->inicio) q->fim = NULL;
    free(tmp);
    return 0;
}

int front(Queue q, int *x){
    if(!q.inicio) return 1;
    *x = q.inicio->valor;
}

void initQueueC(QueueC *q){
    *q = NULL;
}

int QisEmptyC(QueueC q){
    return q == NULL;
}

int enqueueC(QueueC *q, int x){
    LInt tmp = malloc(sizeof(struct slist));
    QueueC beg = *q;
    tmp->valor = x;
    if(*q){
        tmp->prox = beg;
        while((*q)->prox != beg) q = &(*q)->prox;
        (*q)->prox = tmp;
    }
    else{
        tmp->prox = tmp;
        q = tmp;
    }
    return 0;
}

int dequeueC(QueueC *q, int *x){
    if(*q){
        QueueC head = *q;
        *q = (*q)->prox;
        while((*q)->prox != head) q = &(*q)->prox;
        (*q)->prox = head->prox;
        free(head);
        return 0;
    }
    else 
        return 1;
}

int frontC(QueueC q, int *x){
    if(q){
        *x = q->valor;
        return 0;
    }
    else return 1;
}

typedef struct dlist{
    int valor;
    struct dlist *ant, *prox;
} *DList;

typedef struct{
    DList back, front;
} Deque;

void initDeque(Deque *q){
    q->back = q->front = NULL;
}

int DisEmpty(Deque q){
    return (q.front == NULL && q.back == NULL);
}

int pushBack(Deque *q, int x){
    DList tmp = malloc(sizeof(struct dlist));
    tmp->valor = x;
    tmp->prox = NULL;
    tmp->ant = q->back;
    if(!q->back) q->back = q->front = tmp;
    q->back->prox = tmp;
    q->back = tmp;
    return 0;
}

int pushFront(Deque *q, int x){
    DList tmp = malloc(sizeof(struct dlist));
    tmp->valor = x;
    tmp->prox = q->front;
    tmp->ant = NULL;
    if(!q->front) q->front = q->back = tmp;
    q->front->ant = tmp;
    q->front = tmp;
    return 0;
}

int popBack(Deque *q, int *x){
    if(!q->back) return 1;
    *x = q->back->valor;
    DList tmp = q->back;
    q->back->ant->prox = NULL;
    q->back = q->back->ant;
    free(tmp);
    return 0;
}

int popFront(Deque *q, int *x){
    if(!q->front) return 1;
    *x = q->front->valor;
    DList tmp = q->front;
    q->front->prox->ant = NULL;
    q->front = q->front->prox;
    free(tmp);
    return 0;
}

int popMax(Deque *q, int *x){
    if(!q->front) return 1;
    DList lista = q->front;
    DList copy = lista;
    int max = INT_MIN;

    while(copy)
        if(copy->valor > max)
            max = copy->valor;

    while(lista && lista->valor != max) lista = lista->prox;

    lista->ant->prox = lista->prox;
    lista->prox->ant = lista->ant;
    free(lista);
}

int back(Deque q, int *x){
    if(!q.back) return 1;
    *x = q.back->valor;
    return 0;
}

int front(Deque q, int *x){
    if(!q.front) return 1;
    *x = q.front->valor;
    return 0;
}

int main(){
    return 0;
}