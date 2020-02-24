//
//  main.cpp
//  11047동전0
//
//  Created by 김다은 on 2019/10/16.
//  Copyright © 2019 김다은. All rights reserved.


#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N, K;
    cin >> N >> K;
    int moneyUnit[10]={0,};
    for(int i = 0; i < N; i++){
        cin >> moneyUnit[i];
    }
    int cnt = 0;
    for(int i = 0;i<N;i++){
        int change = K / moneyUnit[N-i-1]; // 큰 단위부터 계산해야함, index(i)가 N을 포함하지 않아서 -1도 해줘야함
        K -= change * moneyUnit[N-i-1];
        cnt += change;
    }
    cout<< cnt <<endl;
}
