#include <stdio.h>
#include <stdlib.h>

// Question 1.
void biggestNum (){
    int res, i;
    printf("Please, insert a number to start. If you don't want to start, insert 0.\n");
    scanf("%d", &res);
    if (res != 0){
        while(1){
            printf("Please insert a number. If you want to end, insert 0.\n");
            scanf("%d", &i);
            if (i == 0) break;
            else if (i > res) res = i;
        }
    }
    printf("Biggest number inserted: %d\n", res);
}


// Question 2.
void average(){
    int sum = 0, index = 0, act;
    float result;
    printf("Please, insert a number to start. If you don't want to start, insert 0.\n");
    scanf("%d", &act);
    index++;
    sum += act;
    if (act != 0){
        while(1){
            printf("Please insert a number. If you want to end, insert 0.\n");
            scanf("%d", &act);
            if (act == 0) break;
            sum += act;
            index++;
        }
    }
    if (index != 0){
        result = sum / index;
        printf("The average of the inserted numbers is: %f", result);
    }
}


// Question 3.
void secondBiggest(){
    int biggest, secBiggest, act;
    printf("Please insert a number to start. If you don't want to start, insert 0.\n");
    scanf("%d", &act);
    if(act != 0){
        biggest = act;
        printf("Please insert a number. If you want to end, insert 0.\n");
        scanf("%d", &act);
        if (act != 0){
            if (biggest >= act) secBiggest = act;
            else{
                secBiggest = biggest;
                biggest = act;
            }
            while(1){
                printf("Please insert a number. If you want to end, insert 0.\n");
                scanf("%d", &act);
                if (act == 0) break;
                if (biggest >= act) secBiggest = act;
                else{
                secBiggest = biggest;
                biggest = act;
                }
            }
        }
        else{
            printf("You only inserted one number.\n");
            return;
        }
    }
    else return;
    printf("The second biggest number inserted is: %d\n", secBiggest);
}

// Question 4.
void bitsOne(unsigned int n){
    int ac = 0;
    for(; n > 0; n >>= 1){
        count += n % 2;
    }
}

// Question 5.
int trailingZ(unsigned int n){
    if (n == 0) return 32;
    int ac = 0;
    for (; n > 0; n >>= 1) count += !(n % 2);
}

// Question 6.
int qDig(unsigned int n){
    int i;
    for (i = 0; n > 0; i++, n /= 10);
    return i;
}

// Question 7.
char *mystrcat(char s1[], char s2[]){
    int i, j;
    for (int i = 0; s1[i] != '\0'; i++);
    for (int j = 0; s2[j] != '\0'; j++, i++) s1[i] = s2[j];
    s1[i] = '\0';
    return s1;
}

// Question 8.
char *mystrcpy(char s1[], char s2[]){
    int i;
    for (int i = 0; s1[i] != '\0'; i++) s2[i] = s1[i];
    s2[i] = '\0';
    return s2;
}

// Question 9.
int mystrcmp (char s1[], char s2[]){
    int i;
    for (i = 0; s1[i] != '\0'; i++){
        if (s2[i] == '\0' || s2[i] < s1[i]) return 1;
        else if (s1[i] < s2[i]) return -1;
    }
    if(s2[i] != '\0') return -1;
    else return 0;
}

// Question 10.
char *mystrstr (char s1[], char s2[]){
    char * ret = NULL;
    int i, j, k;

    if (!(*s2)) ret = s1;

    for (i = 0; s1[i] && !ret; i++){
        for (j = 0, k = i; s1[k] == s2[j] && s2[j]; k++, j++);
        if(!s2[j]) ret = s1 + i;
    }

    return ret;
}
/*
int main(){

    return 0;
}
*/