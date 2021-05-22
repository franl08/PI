#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nodo{
    int valor;
    struct nodo *esq, *dir;
} * ABin;

ABin removeMenor(ABin* a){
    if(!*a) return NULL;
    while((*a)->esq)
        a = &(*a)->esq;
    ABin ans = *a;
    if ((*a)->dir) *a = (*a)->dir;
    return ans;
}

void removeRaiz(ABin *a){
    if(a){
        ABin newRoot = removeMenor(&(*a)->dir);
        newRoot->esq = (*a)->esq;
        newRoot->dir = (*a)->dir;
        *a = newRoot;
    }
}

int removeElem(ABin *a, int x){
    if(!a) return 1;
    if(x == (*a)->valor){
        removeRaiz(a);
        return 0;
    }    
    else if(x < (*a)->valor) removeElem(&(*a)->esq, x);
    else removeElem(&(*a)->dir, x);
}

void rodaEsquerda(ABin *a){
    ABin b = (*a)->dir;
    (*a)->dir = b->esq;
    b->esq = (*a);
    *a = b;
}

void rodaDireita(ABin *a){
    ABin b = (*a)->esq;
    (*a)->esq = b->dir;
    b->dir = *a;
    *a = b;
}

void promoveMenor(ABin *a){
    if(*a && (*a)->esq){
        promoveMenor(&((*a)->esq));
        rodaDireita(a);
    }
}

void promoveMaior(ABin *a){
    if(*a && (*a)->dir){
        promoveMaior(&((*a)->dir));
        rodaEsquerda(a);
    }
}

ABin removeMenor2(ABin *a){
    ABin r = NULL;
    promoveMenor(a);
    r = *a;
    *a = (*a)->dir;
    return r;
} 

int constroiEspinhaAux(ABin *a, ABin *ult){
    int r = 0;
    if(*a){
        r = constroiEspinhaAux(&((*a)->esq), ult);
        rodaDireita(a);
        r = r + 1 + constroiEspinhaAux(&((*a)->dir), ult);
    }
}

int constroiEspinha(ABin *a){
    ABin ult;
    return(constroiEspinhaAux(a, &ult));
}

ABin equilibraEspinha(ABin *a, int n){

}

void equilibra(ABin *a){
    int n = constroiEspinha(a);
    equilibraEspinha(a, n);
}