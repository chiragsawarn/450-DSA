#include <bits/stdc++.h>
#include "./chirag.h"
using namespace std;

void rotateRight(int a[], int n){
    int temp = a[n-1];
    for(int i=n-2; i>-1; --i){
        a[i+1] = a[i];
    }
    a[0] = temp;
}

void rotateLeft(int a[], int n){
    int temp = a[0];
    for(int i=1; i<n; ++i){
        a[i-1] = a[i];
    }
    a[n-1] = temp;
}

int main(){
    int a[] = {1,2,3,4};
    int n = sizeof(a)/sizeof(int);
    printArray(a,n);
    // rotateRight(a,n);
    rotateLeft(a,n);
    printArray(a,n,"Rotated");

    return 0;
}