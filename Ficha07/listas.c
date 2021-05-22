#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    char* palavra;
    int ocorr;
    struct celula *prox;
} *Palavras;

void libertaLista(Palavras p){
    while(p){
        char* tmpStr = p->palavra;
        Palavras n = p;
        p = p->prox;
        free(tmpStr);
        free(n);
    }
}

int quantasP(Palavras l){
    int ans = 0;
    while(l){
        ans++;
        l = l->prox;
    }
    return ans;
}

void listaPal(Palavras l){
    while(l){
        printf("%s | %d\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}

char* ultima(Palavras l){
    char* ans;
    while(l){
        ans = l->palavra;
        l = l->prox;
    }
    return ans;
}

Palavras acrescentaInicio(Palavras l, char *p){
    Palavras tmp = malloc(sizeof(struct celula));
    tmp->ocorr = 1;
    tmp->palavra = strdup(p);
    tmp->prox = l;
    return tmp;
}

Palavras acrescentaFim(Palavras l, char *p){
    Palavras ans = l;
    Palavras tmp = malloc(sizeof(struct celula));
    tmp->ocorr = 1;
    tmp->palavra = strdup(p);
    tmp->prox = NULL;
    if(!l) ans = tmp;
    else{
        while(l->prox) l = l->prox;
        l->prox = tmp;
    }
    return ans;
}

Palavras acrescenta(Palavras l, char* p){
    Palavras ans = l;
    if(!l){
        Palavras tmp = malloc(sizeof(struct celula));
        tmp->ocorr = 1;
        tmp->palavra = strdup(p);
        tmp->prox = NULL;
    }
    else{
        int flag = 0;
        while(l && !flag){
            if(!strcmp(l->palavra, p)){
                flag++;
                l->ocorr++;
            }    
            else l = l->prox;
        }
        if(!flag) ans = acrescentaInicio(ans, p);
    }
    return ans;
}

struct celula * maisFreq (Palavras l){
    struct celula * ans = NULL;
    int max = 0;
    while(l){
        if(l->ocorr > max){
            max = l->ocorr;
            ans = l;
        }
        l = l->prox;
    }
    return ans;
}