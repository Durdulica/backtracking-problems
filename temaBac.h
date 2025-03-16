#ifndef TEMABAC_H
#define TEMABAC_H
#include <iostream>
#include <string.h>

using namespace std;

//sa se afis. toate perm. de n cif. in care nu exista pct. fixe

void tipar(int s[100],int dim) {
    for(int i=0; i<dim; i++) {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

bool valid(int s[100], int k) {
    if(s[k] == k + 1) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

bool solutie(int n, int k) {
    return k == n - 1;
}

void back(int s[100],int n,int k, int&nrSol) {
    for(int i = 1; i <= n; i++) {
        s[k] = i;
        if(valid(s,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
                nrSol++;
            }
            else {
                back(s,n,k + 1,nrSol);
            }
        }
    }
}

void ex1() {
    int s[]{}, n = 4, k = 0, nrSol = 0;
    back(s, n, k,nrSol);
    cout<<nrSol<<endl;
}

//sa se genereze toate submultimile cu 3 elem. ale multimii {5,6,7,8} in ordine. Care este antepenultima submultime

bool validComb(int*s, int k) {
    for(int i = 0; i < k; i++) {
        if(s[i] >= s[i + 1]) {
            return false;
        }
    }
    return true;
}

void back2(int*s,int p, int k) {
    for(int i = 5; i <= 8; i++) {
        s[k] = i;
        if(validComb(s,k)) {
            if(solutie(p,k)) {
                tipar(s,p);
            }
            else {
                back2(s,p,k + 1);
            }
        }
    }
}

void ex2() {
    int s[]{}, p = 3, k = 0;
    back2(s, p, k);
}

//sa se genereze toate submultimile multimii {1,2,3,4,5}. Cate submultimi contin elem. 2 si nu contin elem. 4?

bool xInVec(int v[], int dim, int x) {
    for (int i = 0; i < dim; i++) {
        if(v[i] == x) {
            return true;
        }
    }
    return false;
}

void back3(int*s, int p, int k, int&nrSol) {
    for(int i = 1; i <= 5; i++) {
        s[k] = i;
        if(validComb(s,k)) {
            if(solutie(p,k)) {
                cout << nrSol << " ";
                tipar(s,p);
                if(xInVec(s,k,2) && !xInVec(s,k,4)) {
                    nrSol++;
                }
            }
            else {
                back3(s,p,k + 1, nrSol);
            }
        }
    }
}

void ex3() {
    int s[]{}, p = 2, k = 0, nrSol = 0;
    for(int i = 2; i <= 5; i++) {
        back3(s, p, k, nrSol);
        p++;
    }

    cout << nrSol << endl;
}

//sa se genereze toate  sirurile de lungime 3 cu struct. voc-cons-voc formate din {a,b,c,d,e}

const char Vocale[12] = {"aeiouAEIOU"};

bool eVoc(char c) {
    for(int i  = 0; i < strlen(Vocale); i++) {
        if(c == Vocale[i]) {
            return true;
        }
    }
    return false;
}

bool validChar(char*s, int k) {
    if(k % 2 == 0 && !eVoc(s[k])) {
        return false;
    }
    if(k % 2 != 0 && eVoc(s[k])) {
        return false;
    }
    return true;
}

void back4(char*s, int p ,int k) {
    for(int i = 0; i < 5; i++) {
        s[k] = char(i + 'a');
        if(validChar(s,k)) {
            if(solutie(p,k)) {
                cout << s << endl;
            }
            else {
                back4(s,p,k + 1);
            }
        }
    }
}

void ex4() {
    char s[]{};
    int p = 3, k = 0;
    back4(s, p, k);
}

//se genereaza toate cadourile formate din 3 obiecte distincte din multimea {carte, tableta, joc, stilou, ceas, patine},
//a. i. sa nu se gaseasca in acelasi cadou tableta si joc sau carte si stilou

bool valid5(char s[10][20], int k) {
    for(int i = 0; i < k; i++) {
        if(strcmp(s[i],s[k]) == 0) {
            return false;
        }
    }
    return true;
}

bool xSiyInChar(char s[][20], char x[20], char y[20], int n) {
    int ct = 0;
    for(int i = 0; i < n; i++) {
        if(strcmp(s[i], x) == 0) {
            ct++;
        }
        if(strcmp(s[i], y) == 0) {
            ct++;
        }
    }
    if(ct == 2) {
        return true;
    }
    return false;
}

void tiparChar(char s[10][20], int n) {
    for(int i = 0; i <= n; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}

void transfer(char s[10][20], char v[10][20],int k, int i) {
    for(int j = 0; j <= strlen(v[i]); j++) {
        s[k][j] = v[i][j];
    }
}

void back5(char s[10][20], char v[10][20], int n, int p, int k) {
    if(k == p) {
        if(!xSiyInChar(s, v[1],v[2],k + 1) && !xSiyInChar(s, v[3],v[0],k + 1)) {
            cout << k << " ";
            tiparChar(s,k);
        }
        return;
    }
    for(int i = 0; i < n; i++) {
        transfer(s, v, k, i);
        if(valid5(s, k)) {
            back5(s,v,n,p,k + 1);
        }
    }
}

void ex5() {
    char v[][20]{"carte", "tableta", "joc", "stilou", "ceas", "patine"};
    char s[10][20]{};
    int  n = 6, p = 3, k = 0;
    back5(s,v,n,p,k);
}

//sa se genereze toate anagramele distincte ale cuv. {"memorie"} a. i. sa nu contina litere identice pe poz. alaturate si litera
//"o" sa apara dupa litera "m", nu neaparat consecutiv

void bubbleSortChar(char v[], int dim){
    bool sortat;
    do{
        sortat = true;
        for(int i = 0; i  < dim - 1; i++){
            if(v[i] > v[i + 1]){
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sortat = false;
            }
        }
    }while(sortat == false);
}

bool valid6(int s[],char v[], int k) {
    if(k > 0 && v[s[k]] == v[s[k - 1]]) {
        return false;
    }
    if(v[s[k]] == 'o' && xInVec(s,k,3) == 0 && xInVec(s,k,4) == 0) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

void tipar6(int s[], char v[], int n) {
    for(int i = 0; i < n; i++) {
        cout << v[s[i]];
    }
    cout << endl;
}

void back6(int s[], char v[], int n, int k) {
    for(int i = 0; i < n; i++) {
        s[k] = i;
        if(valid6(s,v,k)) {
            if(k == n - 1) {
                tipar6(s,v,n);
            }
            else {
                back6(s,v,n,k + 1);
            }
        }
    }
}

void ex6() {
    char v[10] = "memorie";
    int s[10]{};
    int n = 7, k = 0;
    bubbleSortChar(v,n);
    back6(s,v,n,k);
}

//se genereaza in ord. cresc. toate nr. nat de 4 cif. din multimea{3,7,2,0,5,8} a. i. cif. de pe poz alaturate sa aiba paritati dif.

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

bool valid7(int s[], int k) {
    if(k == 0 && s[k] == 0) {
        return false;
    }
    if(k > 0 && s[k] % 2 == s[k - 1] % 2){
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

void back7(int s[], int v[], int n, int p, int k) {
    for(int i = 0; i < n; i++) {
        s[k] = v[i];
        if(valid7(s,k)) {
            if(solutie(p,k)) {
                tipar(s,p);
            }
            else {
                back7(s,v,n,p,k + 1);
            }
        }
    }
}

void ex7() {
    int v[10]{3,7,2,0,5,8},s[10]{}, n = 6, p = 4, k = 0;
    bubbleSort(v,n);
    back7(s,v,n,p,k);
}

//se genereaza cu back multimi a caror suma este egala cu 9

bool valid8(int*s, int k) {
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

void back8(int* s, int suma, int k, int start) {
    if (suma == 0) {
        tipar(s, k);
        return;
    }

    for (int i = start; i <= suma; i++) {
        s[k] = i;
        if(valid8(s,k)) {
            back8(s, suma - i, k + 1, i);
        }
    }
}

void ex8() {
    int s[10]{}, suma = 9, k = 0;
    back8(s,suma,k,1);
}

//sa se genereze toate parolele formate din 5 char. dist. din multimea{'a','b','c','e','f','g','u'} si care au c. p. 2 voc. si 2 cons.

bool valid9(char*s,int n, int k) {
    int voc = 0, cons = 0;
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
        if(eVoc(s[i])) {
            voc++;
        }
        else {
            cons++;
        }
    }
    return voc >= 2 && cons >= 2;
}

void back9(char*s, char*v, int n, int k,bool folosit[]) {
    if(k == n) {
        if(valid9(s,n,k)) {
            cout << s << endl;
        }
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!folosit[i]) {
            folosit[i] = true;
            s[k] = v[i];
            back9(s,v,n,k + 1,folosit);
            folosit[i] = false;
        }
    }
}

void ex9() {
    char v[10]{'a','b','c','e','f','g','u'}, s[10]{};
    bool folosit[10]{false};
    int n = 5 , k = 0;
    back9(s,v,n,k,folosit);
}

//se genereaza cu metoda back nr. formate doar din cif. 0,1,2,3 care au suma cif. egala cu 4

bool valid10(int*s, int k) {
    if(k == 0 && s[k] == 0) {
        return false;
    }
    return true;
}

void back10(int*s, int suma, int k) {
    if(suma == 0) {
        tipar(s, k);
        return;
    }

    for(int i = 1; i <= suma; i++) {
        s[k] = i;
        if(valid10(s,k)) {
            back10(s, suma - i, k + 1);
        }
    }
}

void ex10() {
    int s[10]{}, suma = 4, k = 0;
    back10(s,suma,k);
}

//sa se genereze in ord. descresc.  toate nr. form. din 4 cif. pare  si care au prima cif. dif. de ultima.

bool solutie11(int*s,int n, int k) {
    if(k == n - 1 && s[0] != s[k - 1]) {
        return true;
    }
    return false;
}

void back11(int*s, int n, int k) {
    if(k == n) {
        if(s[0] != s[n - 1]) {
            tipar(s, n);
        }
        return;
    }
    if(k == 0) {
        for(int i = 8; i >= 2; i-=2) {
            s[k] = i;
            back11(s, n, k + 1);
        }
    }
    else {
        for(int i = 8; i >= 0; i-=2) {
            s[k] = i;
            back11(s, n, k + 1);
        }
    }
}

void ex11() {
    int s[10]{}, n = 4, k = 0;
    back11(s,n,k);
}

//sa se genereze toate posibilitatile de buchete formate din 5 flori dif. a. i. sa nu contina impreuna crin si trandafir
//{'lalea','narcisa','crin','crizantema','trandafir','garoafa','frezie'}

bool valid12(char s[][20], int k) {
    for(int i = 0; i < k; i++) {
        if(strcmp(s[i],s[k]) == 0) {
            return false;
        }
    }
    return true;
}

void back12(char s[][20], char v[][20], int n, int p, int k, int&nrSol) {
    if(k == p) {
        if(!xSiyInChar(s,v[2],v[4],k)) {
            tiparChar(s,k);
            nrSol++;
        }
        return;
    }
    for(int i = 0; i < n; i++) {
        transfer(s,v,k,i);
        if(valid12(s,k)) {
            back12(s, v, n,p,k + 1,nrSol);
        }
    }
}

void ex12() {
    char v[10][20]{"lalea","narcisa","crin","crizantema","trandafir","garoafa","frezie"};
    char s[10][20]{};
    int n = 7, p = 5, k = 0, nrSol = 0;
    back12(s,v,n,p,k, nrSol);
    cout << nrSol << endl;
}

//sa se genereze toate sirurile formate din 5 litere mici distincte a. i. primul si ultimul caracter sunt vocale.
//cate siruri incep cu litera a???

bool validChar13(char*s, int k) {
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

void back13(char*s, int n, int p, int k, int&nrSol) {
    if(k == p) {
        if(s[0] == 'a' && eVoc(s[k - 1])) {
            nrSol++;
            cout << s << endl;
        }
        return;
    }
    for(int i = 0; i < n; i++) {
        s[k] = char(i + 'a');
        if(validChar13(s,k)) {
            back13(s,n,p,k + 1,nrSol);
        }
    }
}

void ex13() {
    char s[10]{};
    int n = 26, p = 5, k = 0, nrSol = 0;
    back13(s,n,p,k, nrSol);
    cout << nrSol << endl;
}

//sa se genereze toate modalitatile de a scrie nr 10 ca o suma

void back14(int*s, int suma, int k) {
    if(suma == 0) {
        tipar(s, k);
        return;
    }
    for(int i = 2; i <= suma; i++) {
        s[k] = i;
        back14(s, suma - i, k + 1);
    }
}

void ex14() {
    int s[10]{}, suma = 10, k = 0;
    back14(s,suma,k);
}

//sa se genereze in ord. cresc. toate nr. nat. form. din 4 cif. dist. si nenule a. i. suma cif. sa fie un nr. par

int sumaVec(int*v, int n) {
    if(n < 0) {
        return 0;
    }
    return v[n] + sumaVec(v, n - 1);
}

bool valid15(int*s, int k) {
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }

    return true;
}

void back15(int*s, int n, int k, int suma) {
    if(k == n) {
        if(suma % 2 == 0) {
            tipar(s, k);
            s = {};
            suma = 0;
            return;
        }
    }

    for(int i = 1; i < 10; i++) {
        s[k] = i;
        if(valid15(s,k)) {
            back15(s, n, k + 1, suma + i);
        }
    }
}

void ex15() {
    int s[10]{}, suma = 0, n = 4, k = 0;
    back15(s,n,k,suma);
}

//sorin are de cultivat 4 tipuri de plante din 5:{"azalee","magnolie","liliac","margarete","anemone"}
//el doreste sa nu cultive magnolia langa liliac

bool valid16(char s[][20],char v[][20], int k) {
    for(int i = 0; i < k; i++) {
        if(strcmp(s[i],s[k]) == 0) {
            return false;
        }
    }
    return true;
}

void back16(char s[][20], char v[][20], int n, int p, int k) {
    if(k == p) {
        if(!xSiyInChar(s,v[1],v[2],k)) {
            tiparChar(s,k);
        }
        return;
    }
    for(int i = 0; i < n; i++) {
        transfer(s,v,k,i);
        if(valid16(s,v,k)) {
            back16(s,v,n,p,k + 1);
        }
    }
}

void ex16() {
    char v[10][20]{"azalee","magnolie","liliac","margarete","anemone"}, s[10][20]{};
    int n = 5, p = 4, k = 0;
    back16(s,v,n,p,k);
}

//avand la dispozitie suma egala cu 100lei si sirul de bancnote : {10lei, 20lei, 30 lei, 40lei}, sa se expr. suma in func. de banc.
void back17(int*s, int suma,int p, int k) {
    if(suma == 0) {
        tipar(s, k);
        s = {};
        return;
    }
    for(int i = 1; i <= suma; i++) {
        s[k] = i;
        back17(s, suma - i,p, k + 1);
    }
}

void ex17() {
    int s[10]{}, suma = 10,p = 4, k = 0;
    back17(s,suma,p,k);
}

//sa se genereze perm. multimii {A,B,C,D,E} a. i. voc. sunt precedate de cons.

bool valid18(char*s, int k) {
    if(!eVoc(s[k]) && eVoc(s[k - 1])) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

void back18(char*s, int n, int k) {
    for(int i = 0; i < n; i++) {
        s[k] = char(i + 'A');
        if(valid18(s,k)) {
            if(k == n - 1) {
                cout << s << endl;
            }
            else {
                back18(s,n,k + 1);
            }
        }
    }
}

void ex18() {
    char s[10]{};
    int n = 5, k = 0;
    back18(s,n,k);
}

///variante 2009

//sa se genereze toate cuvintele de 4 litere din multimea {a,b,c,d,e} a. i. sa nu fie 2 voc. alaturate
//V1:cate cuv. incep cu litera 'b' si se termina cu litera 'e'? ==>15
//V2:care este ultimul cuv. generat ==>eded
//V3:care este penultimul cuv. generat ==> edec
//V4:care este antepenultimul cuv. generat ==> edeb
bool valid19(char*s, int k) {
    if(k > 0 && eVoc(s[k - 1]) && eVoc(s[k])) {
        return false;
    }
    return true;
}

void back19(char*s, int n, int p , int k, int&nrSol) {
    for(int i = 0; i < n; i++) {
        s[k] = char(i + 'a');
        if(valid19(s,k)) {
            if(k == p - 1) {
                cout << s << endl;
                if(s[0] == 'b' && s[k] == 'e') {
                    nrSol++;
                }
            }
            else {
                back19(s,n,p,k + 1,nrSol);
            }
        }
    }
}

void ex19() {
    char s[10]{};
    int n = 5, p = 4, k = 0, nrSol = 0;
    back19(s,n,p,k,nrSol);
    cout << nrSol << endl;
}

//se genereaza nr. nat. cu 3 cif. dist. din multimea {1,2,3,4,5,6,7,8}, nr. cu cif. in ord. str. cresc.
//V5: cate dintre nr. generate au prima cif. 2 si ultima cif. 7 ==> 4

void back20(int*s, int n, int p, int k, int&nrSol) {
    for(int i = 1; i <= n; i++) {
        s[k] = i;
        if(validComb(s,k)) {
            if(k == p - 1) {
                tipar(s, p);
                if(s[0] == 2 && s[k] == 7) {
                    nrSol++;
                }
            }
            else {
                back20(s,n,p,k + 1,nrSol);
            }
        }
    }
}

void ex20() {
    int s[10]{}, n = 8, p = 3, k = 0, nrSol = 0;
    back20(s,n,p,k,nrSol);
    cout << nrSol << endl;
}

//sa se genereze nr. de 3 cif. cu toate cif. distincte. a. i. cif. aflate pe pozitii consec. sunt de paritate dif.
//V6: care este a 10-a sol. generata ==>  145

void back21(int*s, int n, int p, int k) {
    for(int i = 0; i <= n; i++) {
        s[k] = i;
        if(valid7(s,k)) {
            if(k == p - 1) {
                tipar(s, p);
            }
            else {
                back21(s,n,p,k + 1);
            }
        }
    }
}

void ex21() {
    int s[10]{}, n = 9, p = 3, k = 0;
    back21(s,n,p,k);
}

//sa se genereze toate nr. de 5 cif. a. i. cif. sa fie in ord. str. cresc.
//V7: Sa se afis. in ord. cresc. toate nr. cu cif. unitatilor = 6

bool valid22(int*s, int k) {
    if(k == 0 && s[k] == 0) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[i] >= s[k]) {
            return false;
        }
    }
    return true;
}

void back22(int*s, int n, int p, int k) {
    for(int i = 0; i <= n; i++) {
        s[k] = i;
        if(valid22(s,k)) {
            if(k == p - 1 && s[k] == 6) {
                tipar(s, p);
            }
            else {
                back22(s,n,p,k + 1);
            }
        }
    }
}

void ex22() {
    int s[10]{}, n =9, p = 5, k = 0;
    back22(s,n,p,k);
}

//sa se genereze nr. de 3 cif. cu cif. in ord. cresc., iar cif. aflate pe poz. consec. sunt de paritate dif.
//V8: care este al 8-a solutie generata ==> 167
bool valid23(int s[], int k) {
    if(k == 0 && s[k] == 0) {
        return false;
    }
    if(k > 0 && s[k] % 2 == s[k - 1] % 2){
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[i] >= s[k]) {
            return false;
        }
    }
    return true;
}

void back23(int*s, int n, int p, int k) {
    for(int i = 1; i <= n; i++) {
        s[k] = i;
        if(valid23(s,k)) {
            if(k == p - 1) {
                tipar(s, p);
            }
            else {
                back23(s,n,p,k + 1);
            }
        }
    }
}

void ex23() {
    int s[10]{}, n =9, p = 3, k = 0;
    back23(s,n,p,k);
}

//sa se genereze toate nr. de 3 cif. a. i. cif. sunt in ord. cresc., iar cif. aflate pe poz consec sunt de paritate dif.
//V9: sa se scrie toate nr. care au suma cif. egala cu 12

void back24(int*s, int n,int suma, int p, int k) {
    if(suma == 0 && k == p) {
        tipar(s, p);
        return;
    }
    for(int i = 1; i <= n; i++) {
        s[k] = i;
        if(valid23(s,k)) {
            back24(s,n,suma - i,p,k + 1);
        }
    }
}

void ex24() {
    int s[10]{}, n = 9, p = 3, k = 0, suma = 12;
    back24(s,n,suma,p,k);
}


//sa se genereze toate nr. de 5 cif., cif. fiind in ord. cresc.
//V10: sa se afis. solutiile care au prima cif. 5

void back25(int*s, int n, int p, int k) {
    for(int i = 1; i <= n; i++) {
        s[k] = i;
        if(validComb(s,k)) {
            if(k == p - 1 && s[0] == 5) {
                tipar(s, p);
            }
            else {
                back25(s,n,p,k + 1);
            }
        }
    }
}

void ex25() {
    int s[10]{}, n = 9, p = 5, k = 0;
    back25(s,n,p,k);
}

//sa se genereze toate sirurile de 5 cifre 0 si 1 a. i. nu exista mai mult de doua cifre. 0 pe poz. consec.
//V11: care este a 8-a solutie generata ==> 01100
bool valid26(int*s, int k) {
    if(k >= 2 && s[k] == 0 && s[k - 1] == 0 && s[k - 2] == 0) {
        return false;
    }
    return true;
}

void back26(int*s, int n, int k) {
    for(int i = 0; i <= 1; i++) {
        s[k] = i;
        if(valid26(s,k)) {
            if(k == n - 1) {
                tipar(s,n);
            }
            else {
                back26(s,n,k + 1);
            }
        }
    }
}

void ex26() {
    int s[10]{}, n = 5, k = 0;
    back26(s,n,k);
}

//sa se scrie 9 ca suma de nr. prime prin metoda backtracking

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

void back27(int*s, int suma,int k) {
    if(suma == 0) {
        tipar(s,k);
        return;
    }
    for(int i = 1; i <= suma; i++) {
        s[k] = i;
        if(isPrim(i)) {
            back27(s,suma - i,k + 1);
        }
    }
}

void ex27() {
    int s[10]{}, suma = 9, k = 0;
    back27(s,suma,k);
}


//
#endif //TEMABAC_H

