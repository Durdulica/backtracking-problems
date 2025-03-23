#ifndef BSCKTRACKINGINPLAN_H
#define BSCKTRACKINGINPLAN_H
#include <iostream>
#include <fstream>
using namespace std;

//un labirint e codificat printr-o mat. L[n][m] si contine 0(perete) si 1(drum). Se citesc coordonatele unui om in mat.
//omul tb. sa gaseasca rute de iesire, urmand unul din drumuri.Conturul mat. are val. 1
//deplasare in 4 directii
int L[10][20], sol[10][20];
int n, m;
int x, y;

int dx[4] = { -1,  0, 1, 0 };//liniile
int dy[4] = {  0,  1, 0, -1 };//coloane

void citire() {
    ifstream fin("D:/info/c++/clion/backtracking/matrice");

    fin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fin >> L[i][j];

    do {
        cin >> x >> y;      //citeste pozitia pe care este parasutat omul, nu trebuie parasutat pe un perete
    } while (L[x][y] == 0);
}

void afisare() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void rec(int i, int j, int pas) {//pozitia curenta a omului si pasul curent
    //parcurge cele 4 directii  sus dreapta jos stange
    for (int k = 0; k < 4; k++) {
        int imax = i + dx[k];
        int jmax = j + dy[k];

        if (L[imax][jmax] == 1 && sol[imax][jmax] == 0) {
            sol[imax][jmax] = pas;

            if (imax == 0 || imax == n - 1 || jmax == 0 || jmax == m - 1) {
                afisare();
            }
            else {
                rec(imax, jmax, pas + 1);
            }

            sol[imax][jmax] = 0;
        }
    }
}

void ex1() {
    citire();
    sol[x][y] = 1;
    rec(x, y, 2);
}

//deplasare in 8 directii

int d2x[8] = { -1, 1, 0, 0, -1, 1, 1, -1};
int d2y[8] = {  0, 0, -1, 1, 1, 1, -1, -1};

void rec2(int i, int j, int pas) {
    int imax, jmax, k;
    for (k = 0; k < 8; k++) {
        imax = i + d2x[k];
        jmax = j + d2y[k];
        if(L[imax][jmax] == 1 && sol[imax][jmax] == 0) {
            sol[imax][jmax] = pas;

            if(imax == 0 || imax == n - 1 || jmax == 0 || jmax == m - 1) {
                afisare();
            }
            else {
                rec2(imax, jmax, pas + 1);
            }
            sol[imax][jmax] = 0;
        }
    }
}

void ex2() {
    citire();
    sol[x][y] = 1;
    rec2(x, y, 2);
}
#endif //BSCKTRACKINGINPLAN_H
