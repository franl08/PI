#include <stdlib.h>
#include <stdio.h>

// Ex. 1
float multInt1(int n, float m){
    float r = 0;
    for (int i = 0; i < n; i++) r += m;
    return r;
}

// Ex. 2
float multInt2(int n, float m){
    float res = 0; 
    for(; n > 0; m *= 2, n /= 2)
        if (n % 2) res += m;
    return res;
}

// Ex. 3
int mdc1 (int a, int b){
    int res, temp;
    res = 0;

    if (a < b){
        temp = a;
        a = b;
        b = temp;
    }

    for (int i = a; i > 0 && !res; i--)
        if (a % i == 0 && b % i == 0) res = i;

    return res;
}

// Ex. 4 
int mdc2(int a, int b){

    while (a != b){
        if (a > b) a -= b;
        else b -= a;
    }

    return (a == 0 ? b : a);
}

// Ex. 5
int mdc3(int a, int b){

    while (a != 0 && b != 0){
        if (a > b) a %= b;
        else if (b < a) b %= a;
        else return a;
    }

    if (a == 0) return b;
    else return a;
}

// Ex. 6
int fib1(int n){
    if (n <= 2) return 1;
    else return (fib1(n - 1) + fib1(n - 2));
}

// Ex. 7
int fib2(int n){
    int act, ant = 1, ant1 = 1;

    for (int i = 3; i <= n; i++){
        act = ant;
        ant += ant1;
        ant1 = act;
    }

    return ant;
}



int main(){

    return 0;
}

