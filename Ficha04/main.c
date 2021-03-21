#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// PARTE 1 - FUNçÔES SOBRE STRINGS
// Ex. 1.
int isVogal(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
         || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int contaVogais(char *s){
    int counter = 0, i;
    for (i = 0; s[i]; i++) counter += isVogal(s[i]);
    return counter;
}

// Ex. 2.
int retiraVogaisRep1(char *s){
    int size, j, k, count = 0;
    for (size = 0; s[size]; size++);
    char * ans = malloc(sizeof(char) * size + 1);
    for (j = 0, k = 0; s[j]; j++){
        if (isVogal(s[j]) && s[j] == s[j + 1]) count++;
        else ans[k++] = s[j];
    }
    for (j = 0; ans[j]; j++) s[j] = ans[j];
    s[j] ='\0'; 
    free(ans);
    return count;
}

int retiraVogaisRep2(char *s){
    int i, j, counter = 0;

    for (i = 0; s[i]; i++){
        if (isVogal(s[i]) && s[i] == s[i + 1]){
            for (j = i + 1; s[j]; j++)
                s[j] = s[j + 1];
            i--;
            counter++;
        }
    }
    return counter;
}


// Ex. 3.
int duplicaVogais1(char *s){
    int i, j, k, counter = 0, size;
    for (size = 0; s[size]; size++);
    char ans[100];
    for (i = 0, k = 0; s[i]; i++){
        ans[k++] = s[i];
        if (isVogal(s[i])){
            ans[k++] = s[i];
            counter++;
        }
    }
    for (k = 0; ans[k]; k++) s[k] = ans[k];
    s[k] = '\0';
    return counter;
}

int duplicaVogais2(char *s){
    int i, j, counter = 0, size;
    for (size = 0; s[size]; size++);
    for (i = 0; s[i]; i++)
        if (isVogal(s[i])){
            for (j = size + counter; j > i; j--){
                s[j] = s[j - 1];
            }
            counter++;
            i++;
        }
    return counter;
}


// PARTE 2 - ARRAYS ORDENADOS
// Ex. 1.
int ordenado(int v[], int N){
    int ans = 1, i;
    for (i = 1; i < N && ans; i++)
        if (v[i] < v[i - 1]) ans = 0;
    return ans;
}

// Ex. 2.
void merge (int a[], int na, int b[], int nb, int r[]){
    int i, j, k;

    for (i = 0, j = 0, k = 0; a[i] && b[j] && i < na && j < nb; k++){
        if (a[i] < b[j]) r[k] = a[i++];
        else r[k] = b[j++];
    }

    if (a[i]){
        for (; i < na; i++, k++) r[k] = a[i];
    }

    if (b[j]){
        for (; j < nb; j++, k++) r[k] = b[j];
    }
}

// Ex. 3.
void swap(int v[], int a, int b){
    int tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
}


int partition1(int v[], int N, int x){
    int i, counter, j;
    int ans[N];
    for (i = 0, counter = 0, j = 1; i < N; i++){
        if (v[i] <= x) ans[counter++] = v[i];
        else{
            ans[N - j] = v[i];
            j++;
        }
    }
    for (i = 0; i < N; i++) v[i] = ans[i];
    return counter;
}

int partition2(int v[], int N, int x){
    int i, counter = 0;
    for (i = 0; i < N; i++){
        if (v[i] > x){
            swap(v, i--,--N); // look, an emoji 
        }
        else counter++;
    }
    return counter;
}

int main(){

    return 0;
}