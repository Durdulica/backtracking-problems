#ifndef TEORIE_H
#define TEORIE_H
#include <iostream>
using namespace std;

///todo: algoritm de permutari

void tipar(int s[100],int dim) {
    for(int i=0; i<dim; i++) {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

bool valid(int s[100], int n, int k) {
    if(k == 0 && s[k] % 2 == 0)
        return false;
    if(k == n - 1 && s[k] % 2 != 0)
        return false;
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
        if(valid(s,n,k)) {
            if(solutie(n,k)) {
                tipar(s,n);
            }
            else {
                back(s,n,k + 1);
            }
        }
    }
}


#endif //TEORIE_H
