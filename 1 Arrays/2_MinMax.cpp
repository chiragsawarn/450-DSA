#include <bits/stdc++.h>
#include "./chirag.h"
using namespace std;

pair<int,int> findMinMax(int a[], int r, int l=0){
    if(l == r){
        return {a[l],a[r]};
    }
    if(r-l == 1){
        return {min(a[l],a[r]),max(a[l],a[r])};
    }
    int mid = (l+r)/2;
    pair<int,int> p1 = findMinMax(a,mid,l);
    pair<int,int> p2 = findMinMax(a,r,mid+1);
    return {min(p1.first,p2.first),max(p1.second,p2.second)};
}

int main(){
    int n = 10;
    int a[n];
    randomArrayOfPositives(a,n);
    printArray(a,n);
    pair<int,int> p = findMinMax(a,n-1);
    
    cout<<"Minimum : "<<p.first<<endl;
    cout<<"Maximum : "<<p.second<<endl;

    return 0;
}