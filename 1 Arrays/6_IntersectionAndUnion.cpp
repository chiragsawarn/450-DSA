// Find the union and intersection of two sorted arrays
#include <bits/stdc++.h>
#include "./chirag.h"
using namespace std;

void printSet(unordered_set<int> &s, string desc){
    cout<<desc<<" : ";
    for(auto val:s){
        cout<<val<<" ";
    }
    cout<<endl;
}

void findIntersection(int a1[], int n1, int a2[], int n2){
    unordered_set<int> s;
    unordered_set<int> ans;
    for(int i=0; i<n1; ++i){
        s.insert(a1[i]);
    }
    for(int i=0; i<n2; ++i){
        if(s.find(a2[i]) != s.end()){
            ans.insert(a2[i]);
        }
    }

    printSet(ans,"Intersection");
}

void findUnion(int a1[], int n1, int a2[], int n2){
    unordered_set<int> s;
    for(int i=0; i<n1; ++i){
        s.insert(a1[i]);
    }
    for(int i=0; i<n2; ++i){
        s.insert(a2[i]);
    }
    printSet(s,"Union");
}

int main(){
    int n1 = 4;
    int n2 = 7;
    int a1[n1];
    int a2[n2];

    randomArrayOfPositives(a1,n1);
    sort(a1,a1+n1);
    printArray(a1,n1,"Array 1");

    randomArrayOfPositives(a2,n2);
    sort(a2,a2+n2);
    printArray(a2,n2,"Array 2");

    findUnion(a1,n1,a2,n2);
    findIntersection(a1,n1,a2,n2);

    return 0;
}