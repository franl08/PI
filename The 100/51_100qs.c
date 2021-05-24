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

// Questão 31
void inOrder(ABin a, LInt* l){
    if(a){
        inOrder(a->esq, l);
        while(*l)
            l = &(*l)->prox;
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        inOrder(a->dir, &(*l)->prox);    
    }
    else *l = NULL;
}

// Questão 32.
void preOrder(ABin a, LInt* l){
    if(a){
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        preOrder(a->esq, &(*l)->prox);
        while(*l)
            l = &(*l)->prox;
        preOrder(a->dir, l);    
    }
    else *l = NULL;
}

// Questão 33.
void posOrder(ABin a, LInt *l){
    if(a){
        posOrder(a->esq, l);
        while(*l)
            l = &(*l)->prox;
        posOrder(a->dir, l);
        while(*l)
            l = &(*l)->prox;
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;    
    }
    else *l = NULL;
}

// Questão 34.
int depth(ABin a, int x){
    int dLeft, dRight;
    if(a){
        if(a->valor == x) return 1;
        dLeft = 1 + depth(a->esq, x);
        dRight = 1 + depth(a->dir, x);
    }
    else return -1;
    
    if(dLeft == -1 && dRight == -1) return -1;
    else if(dLeft == -1 | (dLeft != -1 && dRight != -1 && dRight < dLeft)) return dRight;
    return dLeft;
}

// Questão 35.
int freeAB(ABin a){
    int ac = 0;
    while(a){
        ac += 1 + freeAB(a->esq) + freeAB(a->dir);
        free(a);
    }
    return ac;
}

// Questão 36.
int pruneAB(ABin *a, int l){
    int ac = 0;

    if(*a && l == 0){
        ac += 1 + pruneAB(&(*a)->esq, 0) + pruneAB(&(*a)->dir, 0);
        free(*a);
        *a = NULL
    }
    else if(*a) ac += pruneAB(&(*a)->esq, l - 1) + pruneAB(&(*a)->dir, l - 1);
    return ac;
}

// Questão 37.
int iguaisAB(ABin a, ABin b){
    int ans = 1;

    if((!a && b) || (!b && a)) ans = 0;

    else if(a && b)
        ans = a->valor == b->valor && iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);

    return ans;    
}

// Questão 38.
LInt concat(LInt *a, LInt b){
    LInt init = (*a) ? *a : b;
    for(; *a; a = &(*a)->prox);
    *a = b;
    return init;
}
LInt nivelL(ABin a, int n){
    if(!a || n < 1) return NULL;
    if(n == 1){
        LInt new = malloc(sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = NULL;
        return new;
    }
    LInt listE = nivelL(a->esq, n - 1);
    return concat(&listE, nivelL(a->dir, n - 1));
}

// Questão 39.
int nivelV(ABin a, int n, int v[]){
    if(!a || n < 1) return 0;

    if(n == 1){
        *v = a->valor;
        return 1;
    }

    else{
        int left = nivelV(a->esq, n - 1, v);
        int right = nivelV(a->dir, n - 1, v + left);
        return left + right;
    }
}

// Questão 40.
int dumpABin(ABin a, int v[], int N){
    if(!a || N < 1) return 0;
    
    int esq = dumpABin(a->esq, v, N);
    
    if(esq < N){
        *(v + esq) = a->valor;
        return esq + dumpABin(a->dir, v + esq + 1, N - esq - 1) + 1;
    }

    else return N;
}

// Questão 41.
ABin somasAcA(ABin a){
    if(!a) return NULL;

    ABin new = malloc(sizeof(struct nodo));
    new->esq = somasAcA(a->esq);
    new->dir = somasAcA(a->dir);
    new->valor = a->valor + (new->esq ? new->esq->valor : 0) + (new->dir ? new->dir->valor : 0);

    return new;
}

// Questão 42.
int contaFolhas(ABin a){
    int ac = 0;
    if(!a) return 0;

    return(!(a->esq) && !(a->dir)) + contaFolhas(a->esq) + contaFolhas(a->dir);
}

// Questão 43.
ABin cloneMirror(ABin a){
    ABin new = NULL;
    if(a){
        new = malloc(sizeof(struct nodo));
        new->valor = a->valor;
        new->esq = cloneMirror(a->dir);
        new->dir = cloneMirror(a->esq);
    }
    return new;
}

// Questão 44.
int addOrd(ABin *a, int x){
    int found = 0;

    while(*a && !found){
        if(x < (*a)->valor) a = &(*a)->esq;
        else if(x > (*a)->valor) a = &(*a)->dir;
        else found = 1;
    }
    if(!found){
        *a = malloc(sizeof(struct nodo);
        (*a)->valor = x;
        (*a)->esq = (*a)->dir = NULL;
    }

    return found;
}

// Questão 45.
int lookupAB(ABin a, int x){
    int ans = 0;

    while(a && !ans){
        if(x < a->valor) a = a->esq;
        else if (x > a->valor) a = a->dir;
        else ans = 1;
    }

    return ans;
}

// Questão 46.
int depthOrd(ABin a, int x){
    int pos = 0, found = 0;

    while(a && !found){
        pos++;
        if(x < a->valor) a = a->esq;
        else if(x > a->valor) a = a ->dir;
        else found = 1;
    }

    return(found ? pos : -1);
}

// Questão 47.
int maiorAB(ABin a){
    while(a->dir){
        a = a->dir;
    }
    return (a->dir ? a->dir->valor : a->valor);
}

// Questão 48.
void removeMaiorA(ABin *a){
    while(*a && (*a)->dir)
        a = &(*a)->dir;
    ABin tmp = (*a)->esq;
    free(*a);
    *a = tmp;
}

// Questão 49.
int quantosMaiores(ABin a, int x){
    if(!a) return 0;
    if(a->valor <= x) return quantosMaiores(a->dir, x);
    else return 1 + quantosMaiores(a->esq, x) + quantosMaiores(a->dir, x);
}

// Questão 50.
void listToBTree(LInt l, ABin *a){
    if(!l) *a = NULL;
    else{
        int mid = length(l)>>1;
        LInt *c = &l;
        for(; mid > 0; mid--, c = &(*c)->prox);
        *a = malloc(sizeof(struct nodo));
        (*a)->valor = (*c)->valor;
        (*a)->esq = (*a)->dir = NULL;
        LInt next = (*c)->prox;
        *c = NULL;
        listToBTree(l, &(*a)->esq);
        listToBTree(next, &((*a)->dir));
    }
}

// Questão 51.
int maior(ABin a, int x){
    return(!a || (a && a->valor && maior(a->esq, x) && maior(a->dir, x)));
}

int menor(ABin a, int x){
    return(!a || (a && a->valor && menor(a->dir, x) && menor(a->esq, x)));
}

int deProcura(ABin a){
    if(a){
        int ans = menor(a->esq, a->valor) && maior(a->dir, a->valor);
        return ans && deProcura(a->esq) && deProcura(a->dir);
    }
    return 1;
}