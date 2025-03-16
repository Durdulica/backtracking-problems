#ifndef PRODUSCARTEZIAN_H
#define PRODUSCARTEZIAN_H
#include <iostream>
using namespace std;


bool valid(int k,int*s) {

    //conditii suplimentare

    return true;
}

void afisare(int*s) {
    cout << '(' << s[0] << ',' << s[1] << ") ";
}

bool solutie(int k) {
    return k == 1;
}
void back(int k,int*x,int*y,int*s, int m, int n) {

    int n_m;

    k==0?n_m=m:n_m=n;

    for(int i = 0; i <= n_m; i++) {

        k==0?s[k]=x[i]:s[k]=y[i];
        if(i == m) {
            return;
        }
        if(valid(k,s)) {
            if(solutie(k)) {
                afisare(s);
            }
            else {
                back(k + 1,x,y,s,m,n);
            }
        }
    }
}

void testare() {
    int x[10]{1,2,3}, m = 3;
    int y[10]{1,2,3}, n = 2;
    int s[2]{}, k = 0;
    back(k,x,y,s,m,n);
}
#endif //PRODUSCARTEZIAN_H
