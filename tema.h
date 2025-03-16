#ifndef TEMA_H
#define TEMA_H
#include <iostream>
#include <string.h>
using namespace std;

//permutare pana la n

void tipar(int s[],int dim) {
    for(int i = 0; i < dim; i++) {
        cout << s[i] << " ";
    }
    cout<<endl;
}

bool valid(int s[100], int k) {
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

bool solutie(int n, int k) {
    if(k == n - 1)
        return true;
    return false;
}

void back(int s[100],int n,int k) {
    for(int i = 1; i <= n; i++) {
        s[k] = i;
        if(valid(s,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back(s,n,k + 1);
            }
        }
    }
}

void ex1() {
    int s[10]{}, n = 3;
    back(s,n,0);
}


//permutare de la a la b

void tipar2(int s[100],int a, int b) {
    for(int i = a; i <= b; i++) {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

bool valid2(int s[100], int a, int k) {
    for(int i = a; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

bool solutie2(int n, int k) {
    if(k == n)
        return true;
    return false;
}

void back2(int s[100],int a, int b, int k) {
    for(int i = a; i <= b; i++) {
        s[k] = i;
        if(valid2(s,a,k)) {
            if(solutie2(b,k)) {
                tipar2(s,a,b);
            }
            else {
                back2(s,a,b,k + 1);
            }
        }
    }
}

void ex2() {
    int s[10]{}, a = 4, b = 6;
    back2(s,a,b,a);
}

//permutare de la n la 1

void tipar3(int s[100], int n) {
    for(int i = n; i > 0; i--) {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

bool valid3(int s[100], int n, int k) {
    for(int i = n; i > k; i--) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

bool solutie3(int k) {
    if(k == 1)
        return true;
    return false;
}

void back3(int s[100],int n, int k) {
    for(int i = n; i > 0; i--) {
        s[k] = i;
        if(valid3(s,n,k)) {
            if(solutie3(k)) {
                tipar3(s,n);
            }
            else {
                back3(s,n,k - 1);
            }
        }
    }
}

void ex3() {
    int s[10]{}, n = 3;
    back3(s,n,n);
}

//se citesc n numere. Sa se afis. perm. nr.

void back4(int s[100],int v[10], int n, int k) {
    for(int i = 0; i < n; i++) {
        s[k] = v[i];
        if(valid(s,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back4(s,v,n,k + 1);
            }
        }
    }
}

void ex4() {
    int s[10]{}, n = 3;
    int v[10]{4,7,3};
    back4(s,v,n,0);
}

//se citesc n nr. distincte. Sa se afis. in ord. lexicografica sirurile cu proprietatea ca oricare 2 val. invecinate sunt prime intre ele

bool primeIntreEle(int a, int b) {
    for(int i = 2; i <= b && i <= a; i++) {
        if(a % i == 0 && b % i == 0) {
            return false;
        }
    }
    return true;
}

void back5(int s[10],int v[10], int n, int k) {
    for(int i = 0; i < n; i++) {
        s[k] = v[i];
        if(valid(s,k)) {
            if(primeIntreEle(s[k],s[k - 1])) {
                if(solutie(n,k)) {
                    tipar(s,n);
                }
                else {
                    back5(s,v,n,k + 1);
                }
            }
        }
    }
}

void bubbleSort(int v[], int dim){
    bool sortat;
    do{
        sortat = true;
        for(int i = 0;i  < dim - 1; i++){
            if(v[i] > v[i + 1]){
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sortat = false;
            }
        }
    }while(sortat == false);
}

void ex5() {
    int v[10]{8,6,7,9}, n = 4, s[10]{};
    bubbleSort(v,n);
    back5(s,v,n,0);
}

//sa citeste un nr. n. Sa se afis. toate perm. in care n se afla in mij. perm.

void back6(int s[100], int n, int k) {
    for(int i = 1; i <= n; i++) {
        s[k] = i;
        if(valid(s,k)) {
            if(solutie(n,k) && s[n % 2] == n) {
                tipar(s,n);
            }
            else {
                back6(s,n,k + 1);
            }
        }
    }
}

void ex6() {
    int s[10]{}, n = 3;
    back6(s,n,0);
}

//sa se afis. toate perm. in care elem. pare sunt lasate pe aceasi poz.

bool valid7(int s[100], int k) {
    if(s[k] != k + 1 && k % 2 != 0) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

void back7(int s[100], int n, int k) {
    for(int i = 1; i <= n; i++) {
        s[k] = i;
        if(valid7(s,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back7(s,n,k + 1);
            }
        }
    }
}

void ex7() {
    int s[10]{}, n = 5;
    back7(s,n,0);
}

//se citesc n nr. Sa se afis. toate perm. in care elem. prime sunt lasate pe aceasi poz.

bool isPrim(int nr) {
    if(nr < 2) {
        return false;
    }
    for(int d = 2; d <= nr / 2; d++) {
        if(nr % d == 0) {
            return false;
        }
    }
    return true;
}

bool valid8(int s[], int k, int folosit[]) {
    //todo:if folosit[k] prim si s[k]!=folosit k return false
    if(isPrim(folosit[k]) && s[k] != folosit[k]) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[k] == s[i]) {
            return false;
        }
    }
    return true;
}

void back8(int s[100],int v[100], int n, int k, int folosit[]) {
    for(int i = 0; i < n; i++) {
        s[k] = v[i];
        if(valid8(s,k,folosit)) {
            if(solutie(n, k)) {
                tipar(s,n);
            }
            else {
                back8(s,v,n,k + 1,folosit);
            }
        }
    }
}

void ex8() {
    int v[10]{9,7,1,2,8}, n = 5;
    int s[10]{}, folosit[10]{};
    for(int i = 0; i < n; i++) {
        if(isPrim(v[i])) {
            s[i] = v[i];
            folosit[i] = s[i];
        }
    }
    bubbleSort(v,n);
    back8(s,v,n,0,folosit);
}

//sa se afis toate perm. literelor unui cuv. in ord. alfabetica

void ordonareLitere(char sir[100]) {
    for(int i = 0; i < strlen(sir); i++) {
        for(int j = 0; j < strlen(sir); j++) {
            if((int)sir[i] < (int) sir[j]) {
                char aux = sir[i];
                sir[i] = sir[j];
                sir[j] = aux;
            }
        }
    }
}

void tiparChar(char s[100], int n) {
    for(int i = 0; i < n; i++) {
        cout << s[i];
    }
    cout << endl;
}

bool validChar(char s[100], int k) {
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

void back9(char s[100], char v[100], int n, int k) {
    for(int i = 0; i < n; i++) {
        s[k] = v[i];
        if(validChar(s,k)) {
            if(solutie(n,k)) {
                tiparChar(s,n);
            }
            else {
                back9(s,v,n,k + 1);
            }
        }
    }
}

void ex9() {
    char v[100]{"mare"};
    char s[100]{};
    int n = 4;
    ordonareLitere(v);
    back9(s,v,n,0);
}

//Se da un interval [a,b], a si b numere naturale. Determinati, in ord. lexicografica, submultimile multimii

bool valid10(int s[100], int a, int k) {
    for(int i = a; i < k; i++) {
        if(s[i] == s[k] || s[i] > s[k]) {
            return false;
        }
    }
    return true;
}

void back10(int s[100], int a, int b, int k) {
    for(int i = a; i <= b; i++) {
        s[k] = i;
        if(valid10(s,a,k)) {
                tipar2(s,a,k);
                back10(s,a,b,k + 1);
        }
    }
}

void ex10() {
    int a = 5, b = 8, s[100]{};
    back10(s,a,b,a);
}

//se da un cuv. format din max. 11 litere mici. Sa se genereze in ord. alfabetica toate perm. cuv. in care nu exista doua voc. sau cons. alaturate

const char Vocale[12] = {"aeiouAEIOU"};

bool eVoc(char c) {
    for(int i  = 0; i < strlen(Vocale); i++) {
        if(c == Vocale[i]) {
            return true;
        }
    }
    return false;
}

bool validChar11(char s[100], int k) {
    if(k != 0 && eVoc(s[k]) && eVoc(s[k - 1])) {
        return false;
    }
    if(k != 0 && !eVoc(s[k - 1]) && !eVoc(s[k])) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

void back11(char s[100], char v[100],int n, int k, int& ok) {
    for(int i = 0; i < n; i++) {
        s[k] = v[i];
        if(validChar11(s,k)) {
            if(solutie(n,k)) {
                ok = 1;
                tiparChar(s,n);
            }
            else {
                back11(s,v,n,k + 1, ok);
            }
        }
    }
}

void ex11() {
    char v[100]{"abc"}, s[100]{};
    int n = 3, ok = 0;
    back11(s,v,n,0,ok);
    if(ok == 0) {
        cout << "IMPOSSIBLE" << endl;
    }
}

//se da un cuv. format din max. 11 litere mici. Sa se genereze in ord. alfabetica toate perm. cuv. in care cuv. incepe si se termina cu o voc.

bool solutieChar12(char s[100], int n, int k) {
    if(k == n - 1 && eVoc(s[0]) && eVoc(s[k])) {
        return true;
    }
    return false;
}

void back12(char s[100], char v[100], int n, int k) {
    for(int i = 0; i < n; i++) {
        s[k] = v[i];
        if(validChar(s,k)) {
            if(solutieChar12(s,n,k)) {
                tiparChar(s,n);
            }
            else {
                back12(s,v,n,k + 1);
            }
        }
    }
}

void ex12() {
    char s[100]{}, v[100] = "alin";
    int n  = 4;
    back12(s,v,n,0);
}

//se citeste un cuv s. Sa se genereze toate perm. cuv. in care voc. sunt pct. fixe

bool solutie13(int n, int k) {
    return n - 1 == k;
}

bool valid13(char s[], int k, char pozVoc[]) {
    if(eVoc(pozVoc[k]) && s[k] != pozVoc[k]) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

void back13(char s[100], char v[100], char pozVoc[100], int n, int k) {
    for(int i = 0; i < n; i++) {
        s[k] = v[i];
        if(valid13(s,k,pozVoc)) {
            if(solutie13(n,k)) {
                tiparChar(s,n);
            }
            else {
                back13(s,v,pozVoc,n,k + 1);
            }
        }
    }
}

void ex13() {
    char v[100]{"dorel"}, s[100]{}, pozVoc[100];
    int n = 5;
    for(int i = 0; i < n; i++) {
        if(eVoc(v[i])) {
            s[i] = v[i];
            pozVoc[i] = s[i];
        }
    }
    tiparChar(s,n);
    ordonareLitere(v);
    back13(s,v,pozVoc,n,0);
}

//sa citeste un nr. Sa se afis. in ord. cresc. nr. care se obtin prim perm. cif. lui n

void cifInVec(int v[100], int& dim, int n) {
    while(n != 0) {
        v[dim++] = n % 10;
        n /= 10;
    }
}

void back14(int s[100], int v[100], int n, int k) {
    for(int i = 0; i < n; i++) {
        s[k] = v[i];
        if(valid(s,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back14(s,v,n,k + 1);
            }
        }
    }
}

void ex14() {
    int n = 483;
    int v[100], dim = 0, s[100];
    cifInVec(v, dim, n);
    bubbleSort(v, dim);
    back14(s,v,dim,0);
}

//sa citesc n cif. Sa se afis. in ord. lexicografica. nr. care se obtin. prin perm. in care elem. min. are o poz. fixa

void minimVec(int v[100], int n, int& minim, int& indmin) {
    for(int i = 0; i < n; i++) {
        if(v[i] < minim) {
            minim = v[i];
            indmin = i;
        }
    }
}

bool valid15(int s[100], int k, int minim, int indmin) {
    if(k == indmin && s[k] != minim) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[k] == s[i]) {
            return false;
        }
    }
    return true;
}

void back15(int s[100], int v[100], int n, int k, int minim, int indmin) {
    for(int i = 0; i < n; i++) {
        s[k] = v[i];
        if(valid15(s,k, minim, indmin)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back15(s,v,n,k + 1, minim, indmin);
            }
        }
    }
}

void ex15() {
    int v[100]{3,1,5,2}, s[100], n = 4;
    int minim = INT_MAX, indmin = -1;
    minimVec(v, n, minim, indmin);
    bubbleSort(v, n);
    back15(s,v,n,0,minim,indmin);
}

//se da un nr. x si n. Sa se afis. toate perm. in ord. lexicografica in care dif. dintre 2 nr. alaturate este cel mult k

bool valid16(int s[100], int k, int x) {
    if(k != 0) {
        int val = s[k] - s[k - 1];
        if(s[k] - s[k - 1] < 0) {
            val = -(s[k] - s[k - 1]);
        }
        if(val > x) {
            return false;
        }
    }
    for(int i = 0; i < k; i++) {
        if(s[k] == s[i]) {
            return false;
        }
    }
    return true;
}

void back16(int s[100], int n,int x, int k) {
    for(int i = 1; i <= n; i++) {
        s[k] = i;
        if(valid16(s,k,x)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back16(s,n,x,k + 1);
            }
        }
    }
}

void ex16(){
    int s[100]{}, n = 4, x = 2;
    back16(s,n,x,0);
}

// sa dau n nr. Sa se afis. perm. in ord. lexicografica in care min. si max. sunt au poz. fixe

void maximVec(int v[100], int n, int& maxim, int& indmax) {
    for(int i = 0; i < n; i++) {
        if(v[i] > maxim) {
            maxim = v[i];
            indmax = i;
        }
    }
}

bool valid17(int s[100], int k, int maxim, int indmax, int minim, int indmin) {
    if(k == indmax && s[k] != maxim) {
        return false;
    }
    if(k == indmin && s[k] != minim) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[k] == s[i]) {
            return false;
        }
    }
    return true;
}

void back17(int s[100], int v[100], int n, int k, int maxim, int indmax, int minim, int indmin) {
    for(int i = 0; i < n; i++) {
        s[k] = v[i];
        if(valid17(s,k,maxim,indmax,minim,indmin)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back17(s,v,n,k+1,maxim,indmax,minim,indmin);
            }
        }
    }
}

void ex17() {
    int v[100]{8,2,7,9,4,5},s[100]{}, n = 6;
    int minim = INT_MAX, indmin = -1;
    int maxim = INT_MIN, indmax = -1;
    maximVec(v, n, maxim, indmax);
    minimVec(v, n, minim, indmin);
    back17(s,v,n,0,maxim, indmax, minim, indmin);
}

//se dau n nr. Sa se afis. perm. in care nu exista 2 elem. prime alaturate

bool valid18(int s[100], int k) {
    if(k > 0 && isPrim(s[k]) && isPrim(s[k - 1])) {
        return false;
    }
    return true;
}

bool solutie18(int n, int k) {
    return k == n;
}

void back18(int s[], int v[], int n,bool folosit[], int k) {
    if(solutie18(n,k)) {
        tipar(s,n);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!folosit[i]) {
            s[k] = v[i];
            if(valid18(s,k)) {
                folosit[i] = true;
                back18(s,v,n,folosit,k + 1);
                folosit[i] = false;
            }
        }
    }
}

void ex18() {
    int v[100]{1,2,3,4}, n = 3, s[100]{};
    bool folosit[100]{false};

    bubbleSort(v,n);

    back18(s,v,n,folosit,0);
}

//Se citeste un nr. si o perm. a multimii [1,2,...,nr]. Sa se afis. toate perm. care nu contin elem. alaturate care au fost alaturate si
//in perm. data

int pozXInVec(int v[100], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(v[i] == x) {
            return i;
        }
    }
}

bool valid19(int s[], int k,int n, int aux[]) {
    int x = pozXInVec(aux,n, s[k]);
    if(k > 0 && s[k-1] == aux[x - 1] || s[k - 1] == aux[x + 1]) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

void back19(int s[], int v[], int n, int k, int aux[]) {
    for(int i = 0; i < n; i++) {
        s[k] = v[i];
        if(valid19(s,k,n,aux)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back19(s,v,n,k + 1,aux);
            }
        }
    }
}

void ex19() {
    int v[10]{4,3,2,1}, n = 4;
    int s[10]{}, aux[10]{};
    for(int i = 0; i < n; i++) {
        aux[i] = v[i];
    }
    bubbleSort(v,n);
    back19(s,v,n,0,aux);
}

//Se citesc n nr. Sa se afis. toate perm. in ord. lexico. in care nu exista 2 elem. prime alaturate

bool valid20(int s[], int k) {
    if(k > 0 && isPrim(s[k]) && isPrim(s[k - 1])) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

void back20(int s[], int v[], int n, int k) {
    for(int i = 0; i < n; i++) {
        s[k] = v[i];
        if(valid20(s,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back20(s,v,n,k + 1);
            }
        }
    }
}

void ex20() {
    int v[10]{9,7,1,2,3}, n = 5;
    int s[100]{};
    bubbleSort(v,n);
    back20(s,v,n,0);
}

#endif //TEMA_H
