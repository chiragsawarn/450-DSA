#include <bits/stdc++.h>
#include "./chirag.h"
using namespace std;

void sort012(int a[], int n){
    int first_one = 0;
    int traveller_one = 0;
    int last_one = n-1;
    while(traveller_one != last_one){
        if(a[traveller_one] == 1){
            ++traveller_one;
        }
        else if(a[traveller_one] == 0){
            swap(a[traveller_one],a[first_one]);
            ++first_one;
            ++traveller_one;
        }
        else{
            swap(a[traveller_one],a[last_one]);
            --last_one;
        }
    }
}

int main(){
    int n = 10;
    int a[n];
    randomArrayOf012(a,n);
    printArray(a,n,"Unsorted");
    sort012(a,n);
    printArray(a,n,"Sorted  ");
    return 0;
}