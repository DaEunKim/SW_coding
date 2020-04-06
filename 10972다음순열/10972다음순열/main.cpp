//
//  main.cpp
//  10972다음순열
//
//  Created by 김다은 on 25/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int inputArr[10001]={0,};

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

bool checkEqual(int *arr, int *input, int size){
    bool check = true;
    for(int i = 0;i<size;i++){
        if(arr[i]==input[i])
            check = true;
        else
            return check = false;
    }
   
    return check;
}
//
void perm(int *arr, int len, int N){
    if(len == N){
        
        if(checkEqual(arr, inputArr, N)){
            for(int i = 0;i<N;i++){
                cout<< arr[i] <<" ";
                
            }
            puts("");

        }
       
        
    }
    for(int i = len;i<N;i++){
        rotateRight(arr, len, i);
        perm(arr, len+1, N);
        rotateLeft(arr, len, i);
    }
    return;
}

int main(){
    int N;
    cin >> N;
    int arr[10001]={0,};
    for(int i = 0;i<N;i++){
        cin >> inputArr[i];
    }
    
    for(int i = 0;i<N;i++){
        arr[i] = i+1;
    }
    
    perm(arr, 0, N);
    
}
