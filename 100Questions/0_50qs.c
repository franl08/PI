#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
        ac += n % 2;
    }
}

// Question 5.
int trailingZ(unsigned int n){
    if (n == 0) return 32;
    int ac = 0;
    for (; n > 0; n >>= 1) ac += !(n % 2);
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
    for (i = 0; s1[i] && s2[i]; i++);
    return s1[i] - s2[i];
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

// Question 11.
void mystrrev(char s[]){
    int i, j;
    for (i = 0; s[i]; i++);
    i--;

    for (j = 0; s[0]; j++){
        char temp = s[j];
        s[i] = temp;
        s[j] = s[i];
    }
}

// Question 12.
int isVogal(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
         || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void strnoV(char s[]){
    int i;
    
    for (i = 0; s[i]; i++)
        if (isVogal(s[i])){
            for (int j = i; s[j]; j++)
                s[j] = s[j + 1];
            i--;
        }
}

// Question 13.
void truncW (char t[], int n){
    int i, j, count = 0;

    for (i = 0; t[i]; i++){
        if (t[i] != ' ') count++;
        else count = 0;

        if (count > n){
            for (j = i; t[j]; j++) t[j] = t[j + 1];
            i--;
        }
    }
}

// Question 14.
char charMaisfreq (char s[]){
    int freq = 0, count = 1;
    char res = '\0';

    for (int i = 0; s[i]; i++, count = 1){
        for (int j = i + 1; s[j]; j++)
            if (s[i] == s[j]) count++;
        
        if (count > freq){
            res = s[i];
            freq = count;
        }
    }

    return res;
}

// Question 15.
int iguaisConsecutivos(char s[]){
    char prev = s[0];
    int maior = 0, streak = 1, i, j;
    for (i = 1; s[i]; i = ++j, streak = 1){
        for (j = i; s[j] == s[j + 1]; j++, streak++);
        if (streak > maior) maior = streak;
    }
    return maior;
}

// Question 16.
int aux(char s[], int j, int n){
    int i, ans = 0;
    for (i = j; i < n && !ans; i++)
        ans = s[i] == s[n];
    return ans;
}

int difConsecutivos(char s[]){
    int i, j, count, flag;
    int max = 0;

    for (i = 0; s[i]; i++, count = 0, flag = 0){
        for (j = i; s[j] && flag; j++){
            if (!aux(s, i, j)) count++;
            else flag = 0;
        }
        if (count > max) max = count;
    }

    return max;
}

// Question 17.
int maiorPrefixo (char s1[], char s2[]){
    int i;

    for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++)

    return i;
}

// Question 18.
int maiorSufixo (char s1[], char s2[]){
    int l1, l2, res = 0;

    for (l1 = 0; s1[l1]; l1++);
    for (l2 = 0; s2[l2]; l2++);
    l1--;
    l2--;

    for (; l1 >= 0 && l2 >= 0 && s1[l1] == s2[l2]; l1--, l2--, res++);

    return res;
}

// Question 19.
int sufPref (char s1[], char s2[]){
    int i, j;

    for (i = j = 0; s1[i]; i++){
        if (s2[j] && s2[j] == s1[i]) j++;
        else j = 0;
    }

    return j;
}

// Question 20.
int contaPal(char s[]){
    int i, inWord = 0, count = 0;

    for (i = 0; s[i]; i++){
        if (inWord && (s[i] == ' ' || s[i] == '\n')){
            inWord = 0;
        }
        else if (!inWord && s[i] != ' ' && s[i] != '\n'){
            inWord = 1;
            count++;
        }
    }

    return count;
}

// Question 21.
int contaVogais(char s[]){
    int i, res = 0;

    for (i = 0; s[i]; i++){
        if (isVogal(s[i])) res++;
    }

    return res;
}

// Question 22.
int contida(char a[], char b[]){
    int i, j, found = 1;

    for (i = 0; a[i] && found; i++){
        found = 0;
        for (j = 0; b[j] && !found; j++){
            if (a[i] == b[j]) found = 1;
        }
    }

    return found;
}

// Question 23.
int palindroma(char s[]){
    int i, end, res = 1;

    for (end = 0; s[end]; end++);
    end--;

    for (i = 0; i < end && res; i++, end--){
        res = s[i] == s[end];
    }

    return res;
}

// Question 24.
int remRep(char x[]){
    int i, j;

    for (i = 0; x[i]; i++){
        if (x[i] == x[i + 1]){
            for (j = i + 1; x[i] == x[j]; j++){
                x[j] = x[j + 1];
            }
            i--;
        }
    }

    return i;
}

// Question 25.
int limpaEspacos(char t[]){
    int i, j;

    for (i = 0; t[i]; i++){
        if (t[i] == ' ' && t[i + 1] == ' '){
            for (j = i + 1; t[j]; j++){
                t[j] = t[j + 1];
            }
            i--;
        }
    }

    return i;
}

// Question 26.
void insere(int v[], int N, int x){
    int i;

    for (i = 0; i < N && v[i] < x; i++);
    for (; N > i; N--) v[N] = v[N - 1];

    v[i] = x;
}

// Question 27.
void merge (int r[], int a[], int b[], int na, int nb){
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

// Question 28.
int crescente(int a[], int i, int j){
    int ans = 1;
    for (; i < j && ans; i++)
        ans = a[i] <= a[i + 1];
    return ans;
}

// Question 29.
int retiraNeg(int v[], int N){
    int i, j;

    for (i = 0; i < N; i++){
        if (v[i] < 0){
            for (j = i; j < N; j++){
                v[j] = v[j + 1];
            }
            i--;
            N--;
        }
    }

    return i;
}

// Question 30.
int menosFreq(int v[], int N){
    int count = 1, min = N, cur = v[0], i, j;

    for (i = 0; i < N; i = j, count = 1){
        for (j = i + 1; v[j] == v[i] && j < N; j++, count++);
        if (count < min){
            min = count;
            cur = v[i];
        }
    }

    return cur;
}

// Question 31.
int maisFreq(int v[], int N){
    int count = 1, max = 1, cur = v[0], i, j;

    for (i = 0; i < N; i = j, count = 1){
        for (j = i + 1; v[j] == v[i] && j < N; j++, count++);
            if (count > max){
                max = count;
                cur = v[i];
            }
    }

    return cur;
} 

// Question 32.
int maxCresc(int v[], int N){
    int count = 1, max = 0, i, j;
    for (i = 0; i < N; i++, count = 1){
        for (j = i + 1; j < N && v[j] >= v[j - 1]; j++, count++);
        if (count > max) max = count;
    }
    return max;
}

// Question 33.
int elimRep(int v[], int N){
    int i, j, l;
    for (i = 0; i < N; i++)
        for (j = i + 1; j < N; j++)
            if (v[i] == v[j]){
                for (l = j; l < N; l++)
                    v[l] = v[l + 1];
                N--;
                j--;
            }
    return i;
}

// Question 34.
int elimRepOrd(int v[], int N){
    int i, j, l;
    for (i = 0; i < N; i++)
        for (j = i + 1; j < N && v[i] == v[j]; j++){
            for (l = j; l < N; l++)
                v[l] = v[l + 1];
            N--;
            j--;
        }
    return i;
}

// Question 35.
int comunsOrd(int a[], int na, int b[], int nb){
    int i = 0, j = 0, ans = 0;

    while (i < na && j < nb){
        if (a[i] == b[j]){
            ans++;
            i++;
            j++;
        }
        else if (a[i] > b[j]) j++;
        else i++;
    }

    return ans;
}

// Question 36.
int comuns(int a[], int na, int b[], int nb){
    int i, j, ans = 0;

    for (i = 0; i < na; i++){
        for (j = 0; j < nb && a[i] != b[j]; j++);
        if (j != nb) ans++;
    }

    return ans;
}

// Question 37.
int minInd(int v[], int N){
    int min = v[0], index = 0, i;

    for (i = 0; i < N; i++){
        if (v[i] < min){
            min = v[i];
            index = i;
        }
    }
    
    return index;
}

// Question 38.
void somasAc(int v[], int Ac[], int N){
    int i, sum = 0;

    for (i = 0; i < N; i++){
        sum += v[i];
        Ac[i] = sum;
    }
}

// Question 39.
int triSup (int N, float m [N][N]){
    int i, j, tri = 1;
    for (i = 0; i < N && tri; i++)
        for (j = 0; j < i && tri; j++)
            if (m[i][j] != 0) tri = 0;
    return tri;
}

// Question 40.
void transposta(int N, float m [N][N]){
    int i, j;
        for (i = 0; i < N; i++)
            for (j = 0; j < i; j++){
                float tmp = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = tmp;
            }
}

// Question 41.
void addTo(int N, int M, int a[N][M], int b[N][M]){
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            a[i][j] += b[i][j];
}

// Question 42.
int unionSet(int N, int v1[N], int v2[N], int r[N]){
    int i;
    for (i = 0; i < N; i++)
        r[i] = v1[i] || v2[i];
    return i;
}

// Question 43.
int intersectSet(int N, int v1[N], int v2[N], int r[N]){
    int i;
    for (i = 0; i < N; i++)
        r[i] = v1[i] && v2[i];
    return i;
}

// Question 44.
int intersectMSet(int N, int v1[N], int v2[N], int r[N]){
    int i;
    for (i = 0; i < N; i++){
        if (v1[i] < v2[i]) r[i] = v1[i];
        else r[i] = v2[i];
    }
    return i;
}

// Question 45.
int unionMSet(int N, int v1[N], int v2[N], int r[N]){
    int i;
    for (i = 0; i < N; i++)
        r[i] = v1[i] > v2[i] ? v1[i] : v2[i];
    return i;
}

// Question 46.
int cardinalMSet(int N, int v[N]){
    int i, tot = 0;
    for (i = 0; i < N; i++) tot += v[i];
    return tot;
}

// Question 47.
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao{
    int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i;
    for (i = 0; i < N; i++){
        switch(mov[i]){
            case Norte:
                inicial.y++;
                break;
            case Oeste:
                inicial.x--;
                break;
            case Este:
                inicial.x++;
                break;
            case Sul:
                inicial.y--;
                break;
            default:
                break;
        }
    }
    return inicial;
}

// Question 48.
int equals(Posicao a, Posicao b){
    return a.x == b.x && a.y == b.y;
}

int caminho(Posicao inicial, Posicao final, Movimento mov[], int N){
    int i, r = -1;

    for (i = 0; i < N && !equals(inicial, final); i++){
        if (inicial.y > final.y){
            mov[i] = Sul;
            inicial.y--;
        }
        else if (inicial.y < final.y){
            mov[i] = Norte;
            inicial.y++;
        }
        else if (inicial.x < final.x){
            mov[i] = Este;
            inicial.x++;
        }
        else{
            mov[i] = Oeste;
            inicial.x--;
        }
    }

    if (iguais(inicial, final)) r = i;

    return r;
}

// Question 49.
int maiscentral(Posicao pos[], int N){
    int dist, min, i, r = 0;
    dist = min = pow(pos[0].x, 2) + pow(pos[0].y, 2);

    for (i = 1; i < N; i++){
        dist = pow(pos[i].x, 2) + pow(pos[i].y, 2);
        if (dist < min){
            min = dist;
            r = i;
        }
    }
    return r;
}

// Question 50.
int vizinhos(Posicao p, Posicao pos[], int N){
    int ac = 0, i, dist;

    for (i = 0; i < N; i++){
        dist = pow((pos[i].x - p.x), 2) + pow((pos[i].y - p.y), 2);
        if (dist < 2 && !equals(p, pos[i])){
            ac++;
        }
    }

    return ac;
}