#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Generates array of length n, full of random integers
void randomArrayOf012(int a[], int n){
    srand(time(NULL));
    for(int i=0; i<n; ++i){
        a[i] = rand()%3;
    }
}

void randomArrayOfNegatives(int a[], int n){
    int x;
    srand(time(NULL));
    
    for(int i=0; i<n; ++i){
        (rand()%2 == 0) ? x = -1 : x = 1;
        a[i] = x*(rand()%100);
    }
}

void randomArrayOfPositives(int a[], int n){
    srand(time(NULL));
    
    for(int i=0; i<n; ++i){
        a[i] = rand()%100;
    }
}

int printArray(int a[], int n, string desc = "Array"){
    cout<<desc<<" : ";
    for(int i=0; i<n; ++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}