#ifndef EXERCITII_H
#define EXERCITII_H
#include <iostream>
#include <string.h>
using namespace std;

//sa se genereze nr. nat. cu cif. din int. [1,7] de n cif. (n <= 5) in ord. cresc.

void tipar(int s[], int n) {
    for (int i = 0; i < n; i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}

bool solutie(int n, int k) {
    return k  == n - 1;
}

bool valid(int s[], int k) {
    for (int i = 0; i < k; i++) {
        if (s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

void back(int*s, int n, int k) {
    for (int i = 1; i <= 7; i++) {
        s[k] = i;
        if(valid(s, k)) {
            if(solutie(n,k)) {
                tipar(s, n);
            }
            else {
                back(s,n, k + 1);
            }
        }
    }
}

void ex1() {
    int s[7]{}, n = 3, k = 0;
    back(s,n,k);
}

//sa se genereze toate nr. cu cif. distincte impare, cu cif. in ord. str. cresc.

void back2(int s[],int imp[], int n, int k) {
    for (int i = 0; i < n; i++) {
        s[k] = imp[i];
        if(valid(s,k)) {
            if(solutie(n,k)) {
                tipar(s, n);
            }
            else {
                back2(s,imp,n,k + 1);
            }
        }
    }
}

void ex2() {
    int imp[10]{1,3,5,7,9}, n = 5;
    int s[10]{}, k = 0;
    back2(s, imp, n, k);
}

//sa se genereze toate nr. cu cif. distincte imp. Sa se afis. nr. sol.

void back3(int s[],int imp[], int n, int k, int& nrSol) {
    for (int i = 0; i < n; i++) {
        s[k] = imp[i];
        if(valid(s,k)) {
            if(solutie(n,k)) {
                tipar(s, n);
                nrSol++;
            }
            else {
                back3(s,imp,n,k + 1,nrSol);
            }
        }
    }
}

void ex3() {
    int imp[10]{1,3,5,7,9}, n = 5;
    int s[10]{}, k = 0, nrSol = 0;
    back3(s, imp, n, k, nrSol);
    cout << nrSol;
}

//sa se genereze nr. nat. de n cif. distincte (n <= 5) care au cif. alaturate de paritate dif. Sa se afis. nr. sol/

void back4(int*s, int n, int k, int&nrSol) {
    for (int i = 1; i < 10; i++) {
        s[k] = i;
        if(valid(s,k)) {
            if(solutie(n,k)) {
                tipar(s, n);
                nrSol++;
            }
            else {
                back4(s,n,k + 1,nrSol);
            }
        }
    }
}

void ex4() {
    int s[10]{}, n = 3, k = 0, nrSol = 0;
    back4(s,n,k,nrSol);
    cout << nrSol;
}

//sa se genereze nr. nat. de n cif. distincte (n <= 5) a caror suma este egala cu un S citit. Sa se afis. nr. sol.

int sumaVec(int*v, int n) {
    if(n < 0) {
        return 0;
    }
    return v[n] + sumaVec(v, n - 1);
}

void back5(int*s, int n, int k,int S, int&nrSol) {
    for (int i = 1; i < 10; i++) {
        s[k] = i;
        if(valid(s,k)) {
            if(solutie(n,k) && sumaVec(s,n - 1) == S) {
                tipar(s, n);
                nrSol++;
            }
            else {
                back5(s,n,k + 1,S, nrSol);
            }
        }
    }
}

void ex5() {
    int s[10]{}, n = 3, S = 8, k = 0, nrSol = 0;
    back5(s,n,k,S,nrSol);
    cout << nrSol;
}

//sa se genereze toate nr. de n cif. distincte si str. cresc. Sa se afis. nr. de sol. Daca n = 5 sa se afis. ct. nr. care incep cu 4

void back6(int*s, int n, int k, int&nrSol, int&nrSol4){
    for (int i = 1; i < 10; i++) {
        s[k] = i;
        if(valid(s,k)) {
            if(solutie(n,k)) {
                tipar(s, n);
                nrSol++;
                if(n == 5 && s[0] == 4) {
                    nrSol4++;
                }
            }
            else {
                back6(s,n,k + 1,nrSol,nrSol4);
            }
        }
    }
}

void ex6(){
    int s[10]{}, n = 5;
    int k = 0, nrSol = 0, nrSol4 = 0;
    back6(s,n,k,nrSol,nrSol4);
    cout << nrSol << " "<< nrSol4 << endl;
}

//sa se gen. toate sir. de n cif. binare(n <= 7) care au cel mult 2 cifre 0 alaturate. Sa se afis nr. sol. cif. 0 & nr. sol. total

void back7(int*s, int n, int k, int&nrSol, int&nrSol0) {
    for (int i = 0; i < 2; i++) {
        s[k] = i;
        if(solutie(n,k)) {
            tipar(s, n);
            nrSol++;
            if(s[0] == 0) {
                nrSol0++;
            }
        }
        else {
            back7(s,n,k + 1,nrSol,nrSol0);
        }
    }
}

void ex7(){
    int s[10]{}, n = 3, k = 0, nrSol = 0, nrSol0 = 0;
    back7(s,n,k,nrSol,nrSol0);
    cout << nrSol << " "<< nrSol0 << endl;
}

//se formeaza echipe de 3 elevi dintre {Alin, Bogdan, Calin, Dana, Elena, Flavia}, ordinea din echipa conteaza
//in cate echipe Alin si Boddan sunt coechipieri? Cate echipe sunt in total

bool xInVec(int v[], int dim, int x) {
    for (int i = 0; i < dim; i++) {
        if(v[i] == x) {
            return true;
        }
    }
    return false;
}

bool solutie8(int k, int p) {
    return k == p;
}

void back8(int s[], int n, int k, int p, int&nrSol, int&ctAlBo) {
    for(int i = 1; i <= n; i++) {
        s[k] = i;
        if(valid(s,k)) {
            if(solutie8(k,p)) {
                nrSol++;
                if(xInVec(s,n,1) && xInVec(s,k,2)) {
                    ctAlBo++;
                }
                break;
            }
            else {
                back8(s,n,k + 1,p,nrSol,ctAlBo);
            }
        }
    }
}

void ex8() {
    char v[100][100] ={"Alin","Bogdan","Calin","Dana","Elena","Flavia"};
    int s[100]{};
    int n = 6, p = 3, k = 0, nrSol = 0, ctAlBo = 0;
    back8(s,n,k,p,nrSol,ctAlBo);
    cout << nrSol << " "<< ctAlBo << endl;
}

//cate nr. de 3 cif. pot fi construite folosind doar cif. pare

bool valid9(int*s, int k) {
    if(s[0] == 0) {
        return false;
    }
    return true;
}

void back9(int*s,int*par, int n, int k, int&nrSol) {
    for(int i = 0; i < 5; i++) {
        s[k] = par[i];
        if(valid9(s,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
                nrSol++;
            }
            else {
                back9(s,par,n,k + 1,nrSol);
            }
        }
    }
}

void ex9() {
    int s[10]{},n = 3, k = 0, nrSol = 0;
    int par[5]{0,2,4,6,8};
    back9(s,par,n,k,nrSol);
    cout << nrSol << " ";
}

//sa se genereze nr. de n cif. (n <= 5) folosind doar cif. {3,5,7}. Cate sol. sunt? Ultimele 3 sol. generate

void back10(int*s,int*v, int n, int k, int&nrSol) {
    for(int i = 0; i < 3;i++) {
        s[k] = v[i];
        if(solutie(n,k)) {
            tipar(s,n);
            nrSol++;
        }
        else {
            back10(s,v,n,k + 1,nrSol);
        }
    }
}

void ex10() {
    int s[10]{},n = 5, k = 0, nrSol = 0;
    int v[10]{3,5,7};
    back10(s,v,n,k,nrSol);
    cout << nrSol << " ";
}

//se citeste un nr n >= 4. Sa se afis. perm. {1,2,...,n} unde dif. abs. a oricaror 2 elem. este c. p. egala cu 2

bool valid11(int*s, int k) {
    if(k > 0) {
        if(s[k] > s[k - 1]) {
            if(s[k] - s[k - 1] < 2) {
                return false;
            }
        }
        else {
            if(s[k - 1] - s[k] < 2) {
                return false;
            }
        }
    }
    for(int i = 0; i < k; i++) {
        if(s[k] == s[i]) {
            return false;
        }
    }
    return true;
}

void back11(int*s, int n, int k) {
    for(int i = 1; i <= n; i++) {
        s[k] = i;
        if(valid11(s,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back11(s,n,k + 1);
            }
        }
    }
}

void ex11() {
    int s[10]{},n = 4, k = 0;
    back11(s,n,k);
}

//sa se construiasca toate nr. de n cif. impare, n <= 20, unde oricare 2 cif. alaturate sunt consecutive in multimea cif. impare

bool valid12(int*s, int k) {
    if(k % 2 != 0) {
        if(s[k] != s[k - 1] + 2) {
            return false;
        }
    }
    return true;
}

void back12(int*s, int*imp, int n, int k) {
    for(int i = 0; i < n; i++) {
        s[k] = imp[i];
        if(valid12(s,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back12(s,imp,n,k + 1);
            }
        }
    }
}

void ex12() {
    int s[10]{},n = 4, k = 0;
    int imp[5]{1,3,5,7,9};
    back12(s,imp,n,k);
}

//se citeste un nr. n. Sa se afis. perm multimii {1,2,...n} in care oricare doua elem. alaturate nu sunt alaturate in multime

bool valid13(int*s, int k) {
    if(k > 0 && s[k] == s[k - 1] + 1) {
        return false;
    }
    if(k > 0 && s[k] + 1 == s[k - 1]) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[k] == s[i]) {
            return false;
        }
    }
    return true;
}

void back13(int*s, int n, int k) {
    for(int i = 1; i <= n; i++) {
        s[k] = i;
        if(valid13(s,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back13(s,n,k + 1);
            }
        }
    }
}

void ex13() {
    int s[10]{},n = 4, k = 0;
    back13(s,n,k);
}

//afis. toate perm. multimii {1,2,..n} cu proprietatea ca pe poz. imp. elem. raman neschimbate

bool valid14(int*s,int*folosit, int k) {
    if(k % 2 != 0 &&s[k] != folosit[k]) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[k] == s[i]) {
            return false;
        }
    }
    return true;
}

void back14(int*s, int*folosit, int n, int k) {
    for(int i = 1; i <= n; i++) {
        s[k] = i;
        if(valid14(s,folosit,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back14(s,folosit,n,k + 1);
            }
        }
    }
}

void ex14() {
    int s[10]{},n = 6, k = 0;
    int folosit[10]{};

    for(int i = 0; i < n; i++) {
        if(i % 2 != 0) {
            s[i] = i + 1;
            folosit[i] = i + 1;
        }
    }

    back14(s,folosit,n,k);
}

//generati toate nr de n cif. care sa resp. proprietatile: cif. sa fie in ord. cresc. si sa nu fie 2 cif. alaturate de aceeasi paritate

bool valid15(int*s, int k) {
    if(k > 0 && s[k] % 2 == s[k - 1] % 2) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[i] >= s[k]) {
            return false;
        }
    }
    return true;
}

void back15(int*s, int n, int k, int&nrSol) {
    for(int i = 1; i <= n; i++) {
        s[k] = i;
        if(valid15(s,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
                nrSol++;
            }
            else {
                back15(s,n,k + 1,nrSol);
            }
        }
    }
}

void ex15() {
    int s[10]{},n = 6, k = 0, nrSol = 0;
    back15(s,n,k,nrSol);
    if(nrSol == 0) {
        cout << "imposibil";
    }
}

// se dau n camile numerotate de la 1 la n. Aranjati camilele a. i. sa generati toate posibilitatiile de camile de paritati
//diferite pe pozitii consecutive

bool valid16(int*s, int k) {
    if(k > 0 && s[k] % 2 == s[k - 1] % 2) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

void back16(int*s, int n, int k) {
    for(int i = 1; i <= n; i++) {
        s[k] = i;
        if(valid16(s,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back16(s,n,k + 1);
            }
        }
    }
}

void ex16() {
    int s[10]{},n = 4, k = 0;
    back16(s,n,k);
}

//afis. toate nr. nat de 3 cif. care au toate cif. pare si in ord. cresc.

void tipar2(int*s, int n) {
    for(int i = 0; i < n; i++) {
        cout << s[i];
    }
    cout << endl;
}

bool valid17(int*s, int k) {
    for(int i = 0; i < k; i++) {
        if(s[i] > s[k]) {
            return false;
        }
    }
    return true;
}

void back17(int*s, int n, int k) {
    for(int i = 2; i < 10; i+=2) {
        s[k] = i;
        if(valid17(s,k)) {
            if(solutie(n,k)) {
                tipar2(s,n);
            }
            else {
                back17(s,n,k + 1);
            }
        }
    }
}

void ex17() {
    int s[10]{},n = 3, k = 0;
    back17(s,n,k);
}

//afis. nr. de n cif. a. i. cif. sunt in ord. cresc. si nu exista 2 cif. alaturate pare sau impare

bool valid18(int*s, int k) {
    if(k > 0 && s[k] % 2 == s[k - 1] % 2) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[i] >= s[k]) {
            return false;
        }
    }
    return true;
}

void back18(int*s, int n, int k) {
    for(int i = 1; i < 10; i++) {
        s[k] = i;
        if(valid18(s,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back18(s,n,k + 1);
            }
        }
    }
}

void ex18() {
    int s[10]{},n = 3, k = 0;
    back18(s,n,k);
}

//generati sirurile de n cif. binare care au cel mult 2 cif. 0 alaturate

bool valid19(int*s, int k) {
    if(k > 1 && s[k] == 0 && s[k - 1] == 0 && s[k - 2] == 0) {
        return false;
    }
    return true;
}

void back19(int*s, int n, int k) {
    for(int i = 0; i < 2; i++) {
        s[k] = i;
        if(valid19(s,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back19(s,n,k + 1);
            }
        }
    }
}

void ex19() {
    int s[10]{},n = 4, k = 0;
    back19(s,n,k);
}

//se citeste un nr. nat. n. Afis toate nr. formate din n cif. in care oricare 2 cif. alaturate au paritate dif.

bool valid20(int*s, int k) {
    if(k == 0 && s[k] == 0) {
        return false;
    }
    if(k > 0 && s[k] % 2 == s[k - 1] % 2) {
        return false;
    }
    return true;
}

void back20(int*s, int n, int k) {
    for(int i = 0; i < 10; i++) {
        s[k] = i;
        if(valid20(s,k)) {
            if(solutie(n,k)) {
                tipar2(s,n);
            }
            else {
                back20(s,n,k + 1);
            }
        }
    }
}

void ex20() {
    int s[10]{},n = 4, k = 0;
    back20(s,n,k);
}

//sa se genereze toate nr. nat. cu cif. distincte ale caror suma este egala cu S dat
//dintre sol. de la I pct. sa se afis. sol. cu prod. cif. max.

int prodVec(int*v, int n) {
    if(n < 0) {
        return 1;
    }
    return v[n] * prodVec(v, n - 1);
}

bool valid21(int*s,int k) {
    if(k == 0 && s[k] == 0) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

void back21(int*s, int n, int k, int suma, int&maxim) {
    for(int i = 0; i < 10; i++) {
        s[k] = i;
        if(valid21(s,k)) {
            if(solutie(n,k) && sumaVec(s,n - 1) == suma) {
                tipar2(s,n);
                if(prodVec(s, n - 1) >= maxim) {
                    maxim = prodVec(s, n - 1);
                }
            }
            else {
                back21(s,n,k + 1,suma,maxim);
            }
        }
    }
}

void ex21() {
    int s[10]{},n = 4, k = 0;
    int suma = 10, maxim = INT_MIN;
    back21(s,n,k,suma, maxim);
    cout << maxim << endl;
}


//se citesc 2 nr. m si n. Sa se afis. toate cuv. care sunt formate din m litere folosind primele n litere mari din alfabet

bool validChar(char*s, int k) {
    for(int i = 0; i < k; i++) {
        if(s[i] >= s[k]) {
            return false;
        }
    }
    return true;
}

void back22(char*s, int n, int m, int k) {
    for(int i = 0; i < n; i++) {
        s[k] = char(i + 'A');
        if(validChar(s,k)) {
            if(solutie(m,k)) {
                cout << s << endl;
            }
            else {
                back22(s,n,m,k + 1);
            }
        }
    }
}

void ex22() {
    char s[10]{};
    int n = 5, m = 3, k = 0;
    back22(s,n,m,k);
}

//se citeste un nr. nat. n. Afis. in ord. lexicografica toate cuv. care sunt formate din n litere mari, care au literele ord. alfa.
//si in care nr. de voc. > nr. de cons.

const char Vocale[12] = {"aeiouAEIOU"};

bool eVoc(char c) {
    for(int i  = 0; i < strlen(Vocale); i++) {
        if(c == Vocale[i]) {
            return true;
        }
    }
    return false;
}

int nrVoc(char*s, int n) {
    if(n < 0) {
        return 0;
    }
    if(eVoc(s[n])) {
        return 1 + nrVoc(s,n - 1);
    }
    return nrVoc(s,n - 1);
}

int nrCons(char*s, int n) {
    if(n < 0) {
        return 0;
    }
    if(eVoc(s[n])) {
        return nrCons(s,n - 1);
    }
    return 1 + nrCons(s,n - 1);
}

void back23(char*s, int n, int k, int&nrSol) {
    for(int i = 0; i < 26; i++) {
        s[k] = char(i + 'A');
        if(validChar(s,k)) {
            if(solutie(n,k) && nrVoc(s, n - 1) > nrCons(s, n - 1)) {
                cout << s << endl;
                nrSol++;
            }
            else {
                back23(s,n,k + 1,nrSol);
            }
        }
    }
}

void ex23() {
    char s[10]{};
    int n = 3, k = 0, nrSol = 0;
    back23(s,n,k,nrSol);
    cout << nrSol << endl;
}

//se citeste un nr. n. Afis. in ord. cresc. toate nr. care sunt formate din n cif. si care au mai multe cif. pare decat cif. impare

int nrPar(int*s, int n) {
    if(n < 0) {
        return 0;
    }
    if(s[n] % 2 == 0) {
        return nrPar(s,n - 1) + 1;
    }
    return nrPar(s,n - 1);
}

int nrImpar(int*s, int n) {
    if(n < 0) {
        return 0;
    }
    if(s[n] % 2 == 0) {
        return nrImpar(s,n - 1);
    }
    return nrImpar(s,n - 1) + 1;
}

bool valid24(int*s, int k) {
    if(k == 0 && s[k] == 0) {
        return false;
    }
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

void back24(int*s, int n, int k) {
    for(int i = 0; i < 10; i++) {
        s[k] = i;
        if(valid24(s,k)) {
            if(solutie(n,k) && nrPar(s, n - 1) > nrImpar(s, n - 1)) {
                tipar2(s,n);
            }
            else {
                back24(s,n,k + 1);
            }
        }
    }
}

void ex24() {
    int s[10]{}, n = 3, k = 0;
    back24(s,n,k);
}

//se citesc 2 litere mici a si b si un nr. nat. n.
//Afis cuv. care sunt formate din n litere mici din alfabet care sunt cuprinse intre litera a si litera b + ord. alfabetic

void back25(char*s, int n, char a, char b, int k) {
    for(int i = a; i <= b; i++) {
        s[k] = char(i);
        if(validChar(s,k)) {
            if(solutie(n,k)) {
                cout << s << endl;
            }
            else {
                back25(s,n,a,b,k + 1);
            }
        }
    }
}

void ex25() {
    char s[10]{}, a = 'd', b = 'h';
    int n = 3, k = 0;
    back25(s,n,a,b,k);
}

//se citesc 2 nr. nat. m si n. Afis. cuv. care sunt formate din m. litere distincte folosind primele n litere mari din alfabet

bool validChar2(char*s, int k) {
    for(int i = 0; i < k; i++) {
        if(s[i] == s[k]) {
            return false;
        }
    }
    return true;
}

void back26(char*s, int n, int m, int k) {
    for(int i = 0; i < n; i++) {
        s[k] = char(i + 'A');
        if(validChar2(s,k)) {
            if(solutie(m,k)) {
                cout << s << endl;
            }
            else {
                back26(s,n,m,k + 1);
            }
        }
    }
}

void ex26() {
    char s[10]{};
    int m = 3, n = 4, k = 0;
    back26(s,n,m,k);
}

//se citesc 2 nr. nat. a, b si n. Sa se afis. sirurile cu n elem. dist. din multimea {a, a + 1, ... , b}

void back27(int*s, int n, int a, int b, int k) {
    for(int i = a; i <= b; i++) {
        s[k] = i;
        if(valid(s,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back27(s,n,a,b,k + 1);
            }
        }
    }
}

void ex27() {
    int s[10]{}, a = 4, b = 6, n = 2, k = 0;
    back27(s,n,a,b,k);
}

#endif //EXERCITII_H
