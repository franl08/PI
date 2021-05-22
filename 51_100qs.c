#include <stdio.h>
#include <stdlib.h>

typedef struct lligada{
    int valor;
    struct lligada *prox;
} *LInt;

// Questão 1.
int length(LInt l){
    int ans = 0;
    while(l){
        l = l->prox;
        ans++;
    }
    return ans;
}

// Questão 2.
void freeL(LInt l){
    while(l){
        LInt tmp = l;
        l = l->prox;
        free(tmp);
    }
}

// Questão 3.
void imprimeL(LInt l){
    while(l){
        printf("%d\n", l->valor);
        l = l->prox;
    }
}

// Questão 4
LInt reverseL(LInt l){
    LInt front, back = NULL;
    while(l){
        front = l->prox;
        l->prox = back;
        back = l;
        l = front;
    }
    return back;
}

// Questão 5
void insertOrd(LInt* l, int x){
    for(; *l && (*l)->valor < x; l = &(*l)->prox);
    LInt tmp = malloc(sizeof(struct lligada));
    tmp->valor = x;
    tmp->prox = *l;
    *l = tmp;
}

// Questão 6
int removeOneOrd(LInt* l, int x){
    int ans = 1;
    for(; *l && (*l)->valor < x; l = &(*l)->prox);
    if(*l && (*l)->valor == x){
        ans = 0;
        LInt tmp = *l;
        *l = (*l)->prox;
        free(tmp);
    }
    return ans;
}

// Questão 7
void merge(LInt *r, LInt a, LInt b){
    for(; a || b; r = &(*r)->prox){
        if((a && b && a->valor < b->valor) || !b){
            *r = a;
            a = a->prox;
        }
        else{
            *r = b;
            b = b->prox;
        }
    }
    *r = NULL;
}

// Questão 8
void splitQS(LInt l, int x, LInt *mx, LInt *Mx){
    for(; l; l = l->prox){
        if(l->valor < x){
            *mx = l;
            mx = &(*mx)->prox;
        }
        else{
            *Mx = l;
            Mx = &(*Mx)->prox;
        }
    }
    *mx = *Mx = NULL;
}

// Questão 9
LInt parteAmeio(LInt *l){
    int mid = length(*l)>>1;
    LInt head, *r = &head;
    for(; mid > 0; mid--, *l = (*l)->prox, r = &(*r)->prox)
        *r = *l;
    *r = NULL;
    return head;
}

// Questão 10
int removeAll(LInt* l, int x){
    int ans = 0;
    if(!(*l)) return 0;
    while(*l){
        if((*l)->valor == x){
            LInt tmp = *l;
            *l = (*l)->prox;
            free(tmp);
            ans++;
        }
        else l = &(*l)->prox;
    }

    return ans;
}

// Questão 11.
int removeDups(LInt *l){
    int count = 0;

    for(; *l; l = &(*l)->prox){
        LInt *curs = &(*l)->prox;
        while(*curs){
            if((*curs)->valor == (*l)->valor){
                LInt tmp = *curs;
                *curs = (*curs)->prox;
                free(tmp);
                count++;
            }
            else curs = &(*curs)->prox;
        }
    }

    return count;
}

// Questão 12.
int removeMaiorL(LInt* l){
    int max = (*l)->valor;
    LInt aux = *l;
    while(aux){
        if(aux->valor > max) max = aux->valor;
        aux = aux->prox;
    }
    for(; (*l)->valor != max; l = &(*l)->prox);
    LInt tmp = *l;
    *l = (*l)->prox;
    free(tmp);
    return max;
}

// Questão 13.
void init(LInt* l){
    for(; *l && (*l)->prox; l = &(*l)->prox);
    free(*l);
    *l = NULL;
}

// Questão 14.
void appendL(LInt* l, int x){
    for(; *l; l = &(*l)->prox);
    *l = malloc(sizeof(struct lligada));
    (*l)->valor = x;
    (*l)->prox = NULL;
}

// Questão 15.
void concatL(LInt* a, LInt b){
    for(; *a; a = &(*a)->prox);
    *a = b;
}

// Questão 16.
LInt cloneL(LInt a){
    LInt head, *r = &head;
    for(; a; a = a->prox, r = &(*r)->prox){
        *r = malloc(sizeof(struct lligada));
        (*r)->valor = a->valor;
    }
    *r = NULL;
    return head;
}

// Questão 17.
LInt cloneRev(LInt l){
    LInt head = NULL, back = NULL;

    for(; l; l = l->prox){
        head = malloc(sizeof(struct lligada));
        head->valor = l->valor;
        head->prox = back;
        back = head;
    }

    return back;
}
/*

OU

LInt cloneRev(LInt l){
    LInt reversed = reverseL(l);
    return cloneL(reversed);
}
*/

// Questão 18.
int maximo(LInt l){
    int max = l->valor;
    while(l){
        if(l->valor > max) max = l->valor;
        l = l->prox;
    }
    return max;
}

// Questão 19.
int take(int n, LInt *l){
    int ac = 0;
    for(; *l && ac < n; l = &(*l)->prox, ac++);
    while(*l){
        LInt tmp = *l;
        *l = (*l)->prox;
        free(tmp);
    }
    return ac;
}

// Questão 20.
int drop(int n, LInt *l){
    int ac = 0;
    for(; *l && ac < n; ac++){
        LInt tmp = *l;
        *l = (*l)->prox;
        free(tmp);
    }
    return ac;
}

// Questão 21.
LInt Nforward(LInt l, int N){
    for(int i = 0; i < N; i++){
        l = l->prox;
    }
    return l;
}

// Questão 22.
int listToArray(LInt l, int v[], int N){
    int i;
    for(i = 0; l && i < N; i++, l = l->prox)
        v[i] = l->valor;
    return i;
}

// Questão 23.
LInt arrayToList(int v[], int N){
    LInt head, *r = &head;
    for(int i = 0; i < N; i++){
        *r = malloc(sizeof(struct lligada));
        (*r)->valor = v[i];
        r = &(*r)->prox;
    }
    *r = NULL;
    return head;
}

// Questão 24.
LInt somasAcL(LInt l){
    LInt head, *r = &head;
    int ac = 0;
    for(; l; l = l->prox, r = &(*r)->prox){
        ac += l->valor;
        *r = malloc(sizeof(struct lligada));
        (*r)->valor = ac;
    }
    *r = NULL;
    return head;
}

// Questão 25.
void remReps(LInt l){
    for(; l; l = l->prox){
        LInt *aux = &(l->prox);
        while(*aux && (*aux)->valor == l->valor){
            LInt tmp = *aux;
            *aux = (*aux)->prox;
            free(tmp);
        }
    }
}

// Questão 26.
LInt rotateL(LInt l){
    LInt head = l;
    if(l && l->prox){
        LInt init = l;
        l = head = l->prox;
        for(; l && l->prox; l = l->prox);
        l->prox = init;
        init->prox = NULL;
    }
}

// Questão 27.
LInt parte(LInt l){
    LInt head, *r = &head, *aux = &l;
    int j;
    for(j = 1; *aux; j++){
        if(!(j % 2)){
            *r = *aux;
            *aux = (*aux)->prox;
            r = &(*r)->prox;
        }
        else aux = &(*aux)->prox;
    }
    *r = NULL;
    return head;
}

typedef struct nodo{
    int valor;
    struct nodo *esq, *dir;
} *ABin;

// Questão 28.
int altura(ABin a){
    if(!a) return 0;
    int esqAlt = 1 + altura(a->esq);
    int dirAlt = 1 + altura(a->dir);
    return (esqAlt > dirAlt ? esqAlt : dirAlt);
}

// Questão 29.
ABin cloneAB(ABin a){
    if(!a) return NULL;
    ABin new;
    new = malloc(sizeof(struct nodo));
    new->valor = a->valor;
    new->esq = cloneAB(a->esq);
    new->dir = cloneAB(a->dir);

    return new;  
}

// Questão 30.
ABin mirror(ABin *a){
    if(*a){
        ABin tmp = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = tmp;
        mirror(&(*a)->dir);
        mirror(&(*a)->esq);
    }
}