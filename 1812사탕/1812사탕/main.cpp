//
//  main.cpp
//  1812사탕
//
//  Created by 김다은 on 2019/10/23.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int check(int x, int *getCandy, int *candySum, int N, int i){
    if(candySum[N-1] - x == getCandy[i]){
        return getCandy[i];
    }
    return getCandy[i];
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    int candySum[999]={0,};
    for(int i = 0;i<N;i++){
        cin >> candySum[i];
    }
    
    int getCandy[999]={0,};
    int i = 0;
    for(int x =1;x<100000;x++){
        cout<< check(x, getCandy, candySum, N, i++) <<endl;
        
    }
}
