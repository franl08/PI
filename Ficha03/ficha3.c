#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/*
    1. 
        1ª it: 1 1 4
        2ª it: 2 2 6
        3ª it: 3 3 8
        4ª it: 4 4 10
        5ª it: 5 5 12
    2. 
        13
*/

// Exercise 1.
void swapM(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Exercise 2.
void swap(int v[], int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// Exercise 3.
int sum (int v[], int N){
    int res = 0;
    for (int i = 0; i < N; i++) res += v[i];
    return res;
}

// Exercise 3.
void reverseArr1 (int v[], int N){
    int i = 0;
    int size = N - 1;
    while (i < size){
        swap (v, i++, size--);
    }
}

void reverseArr2 (int v[], int N){
    int i = 0;
    int size = N - 1;
    int *t1 = v, *t2 = v + size; 
    while (i++ < size--){
        swapM (t1++, t2--);
    }
}

// Exercise 4.
int maximum (int v[], int N, int *m){
    if (N < 0) return -1;
    *m = INT_MIN;
    for (int i = 0; i < N; i++){
        if (v[i] > *m) *m = v[i];
    }
    return 0;
}

// Exercise 5.
void square(int s[], int N){
    for (int i = 0; i < N; i++){
        s[i] = ((i+1) * (i+1));
    }
}

// Exercise 6.
// a)
void pascal(int v[], int N){
    if (N == 1) v[0] = 1;
    else{
        int prev[N - 1];
        pascal (prev, N - 1);
        v[0] = 1;
        v[N - 1] = 1;
        for (int i = 1; i < N -1; i++) v[i] = prev[i] + prev[i - 1];
    }
}

// b)
void pascal2(int v[], int N){
    for (int i = 1; i <= N; i++){
        pascal(v, i);
        for (int j = 0; j < i; j++) printf ("%d ", v[j]);
        printf ("\n");
    }
}


int main(){
    
    return 0;
}