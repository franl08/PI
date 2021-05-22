#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    int valor;
    struct nodo *esq, *dir;
} * ABin;

ABin newABin(int r, ABin e, ABin d){
    ABin a = malloc(sizeof(struct nodo));
    if(a){
        a->valor = r;
        a->esq = e;
        a->dir = d;
    }
    return a;
}

int altura(ABin a){
    if(!a) return 0;
    int alEsq = 1 + altura(a->esq);
    int alDir = 1 + altura(a->dir);
    if(alEsq > alDir) return alEsq;
    else return alDir;
}

int nFolhas(ABin a){
    if(!a) return 0;
    if(!a->esq && !a->dir) return 1;
    return nFolhas(a->esq) + nFolhas(a->dir);
}

ABin maisEsquerda(ABin a){
    if(!a) return NULL;
    while(a->esq)
        a = a->esq;
    return a;
}

void imprimeNivel(ABin a, int l){
    if(!a) return NULL;
    if(l == 0) printf("%d\n", a->valor);
    else{
        imprimeNivel(a->esq, l - 1);
        imprimeNivel(a->dir, l - 1);
    }
}

int procuraE(ABin a, int x){
    if(!a) return 0;
    if(a->valor == x) return 1;
    return procuraE(a->esq, x) || procuraE(a->dir, x);
}

struct nodo *procura(ABin a, int x){
    while(a != NULL && a->valor != x){
        if(a->valor < x) a = a->dir;
        else a = a->esq; 
    }
    return a;
}

int nivel(ABin a, int x){
    int ac = 0;
    while(a != NULL && a->valor != x){
        if(a->valor < x) a = a->dir;
        else a = a->esq; 
        ac++;
    }
    if(a == NULL) return -1;
    return ac;
}

void imprimeAte(ABin a, int x){
    if(a){
        imprimeAte(a->esq, x);
        if(x >= a->valor){
            printf("%d |", a->valor);
            imprimeAte(a->dir, x);
        }
    }
}