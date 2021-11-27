#include <bits/stdc++.h>
#include "./chirag.h"
using namespace std;

int findKthMin(int a[], int n, int k){
    priority_queue<int> q1;

    for(int i=0; i<k; ++i)
        q1.push(a[i]);
    
    for(int i=k; i<n; ++i){
        if(a[i]<q1.top()){
            q1.push(a[i]);
            q1.pop();
        }
    }

    return q1.top();
}

int findKthMax(int a[], int n, int k){
    priority_queue<int,vector<int>,greater<int>> q1;
    
    for(int i=0; i<k; ++i)
        q1.push(a[i]);
    
    for(int i=k; i<n; ++i){
        if(a[i]>q1.top()){
            q1.push(a[i]);
            q1.pop();
        }
    }

    return q1.top();
}

int main(){
    int n = 10;
    int a[n];
    int k = 3;
    randomArrayOfPositives(a,n);

    cout<<k<<"-rd Minimum is "<<findKthMin(a,n,k)<<endl;
    cout<<k<<"-rd Maximum is "<<findKthMax(a,n,k)<<endl;

    sort(a,a+n);
    printArray(a,n,"Sorted  ");
    return 0;
}