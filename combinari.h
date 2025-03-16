#ifndef COMBINARI_H
#define COMBINARI_H
#include <iostream>
using namespace std;

//todo: algoritm de combinari

void afis(int v[10],int k){
    for(int i = 1 ; i <= k ; i++)
        cout << v[i] << " ";
    cout << endl;
}

bool valid(int s[10], int k){
    for(int i = 0 ; i < k; i++)
         if(s[i]>=s[i+1]) {
             return false;
         }
    return true;
}

bool solutie(int k, int p){
    return k == p;
}

void back(int s[10], int n,int p, int k){
    for(int i = 1 ; i <= n ; i++){
        s[k] = i;
        if(valid(s,k))
            if(solutie(k,p))
                afis(s,k);
            else
                back(s,n,p,k + 1);
    }
}

void testare() {
    int s[10]{}, n = 3, p = 2, k = 1;
    back(s, n, p, k);
}

#endif //COMBINARI_H