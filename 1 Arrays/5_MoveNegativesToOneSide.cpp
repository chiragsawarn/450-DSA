#include <bits/stdc++.h>
#include "./chirag.h"
using namespace std;

void moveNegativesToOneSide(int a[], int n){
    int first_positive = 0, positive_traveller = 0;
    while(positive_traveller != n){
        if(a[positive_traveller] < 0){
            swap(a[positive_traveller],a[first_positive]);
            ++positive_traveller;
            ++first_positive;
        }
        else
            ++positive_traveller;
    }
}

int main(){
    int n = 10;
    int a[n];
    randomArrayOfNegatives(a,n);
    printArray(a,n,"Original");
    moveNegativesToOneSide(a,n);
    printArray(a,n,"Moved   ");
    return 0;
}