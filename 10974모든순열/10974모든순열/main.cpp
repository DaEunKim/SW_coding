//
//  main.cpp
//  10974모든순열
//
//  Created by 김다은 on 24/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

void rotateRight(int *arr, int a, int b){
    int end = arr[b];
    for(int i = b;i>a;i--){
        arr[i] = arr[i-1];
    }
    arr[a] = end;
}
void rotateLeft(int *arr, int a, int b){
    int start = arr[a];
    for(int i = a; i < b; i++){
        arr[i] = arr[i+1];
    }
    arr[b] = start;
}

void perm(int *arr, int n, int size){
    if(n==size){
        for(int i = 0;i<size;i++){
            cout<< arr[i] <<" ";
        }
        puts("");
        return;
    }
    for(int i = n; i < size; i++){
//        swap(arr[i], arr[n-1]);
        rotateRight(arr, n, i);
        perm(arr, n+1, size);
        rotateLeft(arr, n, i);
//        swap(arr[i], arr[n-1]);
    }
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    int arr[9]= {0,};
    for(int i = 0;i<N;i++){
        arr[i] = i+1;
    }
    perm(arr, 0, N);
}
