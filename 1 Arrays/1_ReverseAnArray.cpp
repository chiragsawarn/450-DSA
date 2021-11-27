#include <iostream>
#include "./chirag.h"
using namespace std;

void reverseArray(int a[], int n){
    int mid = n/2;
    for(int i=0; i<mid; ++i){
        swap(a[i],a[n-i-1]);
    }
}

int main(){
    int n = 10;
    int a[n];
    randomArrayOf012(a,n);
    printArray(a,n,"Normal  ");
    reverseArray(a,n);
    printArray(a,n,"Reversed");
    return 0;
}