//
//  main.cpp
//  1780종이의개수
//
//  Created by 김다은 on 2020/05/25.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int **arr;
int cnt0 = 0;
int cnt1 = 0;
int cntminus1 = 0;
void divide_and_conquer(int n, int x, int y){
    int cur = arr[x][y];
    bool flag = true;
    for(int i = x; i < x+n; i++){
        for(int j = y; j < y+n; j++){
            if(cur!= arr[i][j]){
                flag = false;
            }
        }
    }
    
    if(flag){
        if(cur==1){
            cnt1++;
        }
        if(cur==0){
            cnt0++;
        }
        if(cur == -1){
            cntminus1++;
        }
    }
    else{
        divide_and_conquer(n/3, x, y);
        divide_and_conquer(n/3, x, y + n/3);
        divide_and_conquer(n/3, x, y + n/3 + n/3);

        divide_and_conquer(n/3, x + n/3, y);
        divide_and_conquer(n/3, x + n/3, y + n/3);
        divide_and_conquer(n/3, x + n/3, y + n/3 + n/3);
        
        divide_and_conquer(n/3, x + n/3 + n/3, y);
        divide_and_conquer(n/3, x + n/3 + n/3, y + n/3);
        divide_and_conquer(n/3, x + n/3 + n/3, y + n/3 + n/3);
    }
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    arr = (int**)malloc(sizeof(int*)*N);
    for (int i = 0; i < N; i++)
        arr[i] = (int*)malloc(sizeof(int)*N);
    
    
    for(int i=0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    divide_and_conquer(N, 0, 0);
    
    cout<< cntminus1 <<endl;
    cout<< cnt0 <<endl;
    cout<< cnt1 <<endl;

}
