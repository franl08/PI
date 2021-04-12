#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    int numero;
    char nome[100];
    int miniT[6];
    float teste;
} Aluno;

int nota (Aluno a){
    int sumMini = 0, i;
    float final;

    for (i = 0; i < 6; i++) sumMini += a.miniT[i];

    if (sumMini < 4.8 || a.teste < 8) return 0;

    final = (sumMini / 2) + (a.teste * 0.7);
    if (final < 9.5) return 0;

    return final;
}

// Deve ser melhorada para algum algoritmo decente que use o facto de t estar ordenado
int procuraNum(int num, Aluno t[], int N){
    int found = -1;
    for (int i = 0; i < N && found == -1; i++){
        if (t[i].numero == num) found = i; 
    }
    return found;
}

void swap(int x, int y, Aluno t[]){
    Aluno temp = t[x];
    t[x] = t[y];
    t[y] = temp;
}

void ordenaPorNum(Aluno t[], int N){
    int i, j;
    for (i = 0; i < N - 1; i++)
        for (j = 0; j < N - i - 1; j++)
            if (t[j].numero > t[j + 1].numero){
                swap(j, j + 1, t);
            }
}

void criaIndPorNum(Aluno t[], int N, int ind[]){
    Aluno *aux = malloc(sizeof(struct aluno) * N);

    for (int i = 0; i < N; i++){
        aux[i].numero = t[i].numero;
        strcpy(aux[i].nome, t[i].nome);
        for (int j = 0; j < 6; j++){
            aux[i].miniT[j] = t[i].miniT[j];
        }
        aux[i].teste = t[i].teste;
    }

    for (int i = 0; i < N; i++){
        ind[i] = 10;
    }

    ordenaPorNum(aux, N);

    for (int k = 0; k < N; k++)
        ind[procuraNum(aux[k].numero, t, N)] = k;
}

void imprimeTurma(int ind[], Aluno t[], int N){
    int j, i;
    for (i = 0; i < N; i++){
        for (j = 0; ind[j] != i; j++);
        printf("Nome: %s (nº%d) | Teste: %f | Minitestes: ", t[j].nome, t[j].numero, t[j].teste);
        for (int k = 0; k < 6; k++) printf("%d ", t[j].miniT[k]);
        printf("\n");
    }
}

int procuraNumInd(int num, int ind[], Aluno t[], int N){
    return procuraNum(num, t, N);
}

void ordenaPorNome(Aluno t[], int N){
    int i, j;
    for (i = 0; i < N - 1; i++)
        for (j = 0; j < N - i - 1; j++)
            if (strcmp(t[j].nome, t[j + 1].nome) > 0){
                swap(j, j + 1, t);
            }
}

void criaIndPorNome(Aluno t[], int N, int ind[]){
    Aluno *aux = malloc(sizeof(struct aluno) * N);

    for (int i = 0; i < N; i++){
        aux[i].numero = t[i].numero;
        strcpy(aux[i].nome, t[i].nome);
        for (int j = 0; j < 6; j++){
            aux[i].miniT[j] = t[i].miniT[j];
        }
        aux[i].teste = t[i].teste;
    }

    for (int i = 0; i < N; i++){
        ind[i] = 10;
    }

    ordenaPorNome(aux, N);

    for (int k = 0; k < N; k++)
        ind[procuraNum(aux[k].numero, t, N)] = k;
}

int main(){

    return 0;
}