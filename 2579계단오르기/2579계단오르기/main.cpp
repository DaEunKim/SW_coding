//
//  main.cpp
//  2579계단오르기
//
//  Created by 김다은 on 01/10/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int visited[10001] = {0,};
void checkStair(int *stairs, int N){
    for(int i = 1;i<=N;i++){
        if(i == 1){
            visited[i] = stairs[i];
        }
        if(i == 2){
            visited[i] = stairs[1] + stairs[2];
        }
       
        visited[i] = max(visited[i-3] + stairs[i-1], visited[i-2]) + stairs[i];
    }
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    int stairs[10001] = {0,};
    
    for(int i = 1;i<=N;i++){
        cin >> stairs[i];
    }
    checkStair(stairs, N);
    cout<< visited[N] <<endl;
    
}
