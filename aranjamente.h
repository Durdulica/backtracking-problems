#ifndef ARANJAMENTE_H
#define ARANJAMENTE_H
#include  <iostream>
using namespace std;

//todo:algoritm de aranjamente

void afis(int v[10],int k){
    for(int i = 1 ; i <= k ; i++)
        cout << v[i] << " ";
    cout << endl;
}

bool valid(int v[10], int k){
    for(int i = 0 ; i < k; ++ i)
        if(v[k] == v[i])
            return false;
    return true;
}

bool solutie(int k, int p){
    return k == p;
}

void back(int v[10], int n,int p, int k){
    for(int i = 1 ; i <= n ; ++ i)
    {
        v[k] = i;
        if(valid(v,k))
            if(solutie(k,p))
                afis(v,k);
            else
                back(v,n,p,k + 1);
    }
}

void ex1() {
    int v[10] = {};
    int n = 4, p = 2, k = 1;
    back(v,n,p,k);
}
#endif //ARANJAMENTE_H
