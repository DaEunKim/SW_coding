//
//  main.cpp
//  1003피보나치함수
//
//  Created by 김다은 on 08/08/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;


int dp[41] ={1,};

int fibonacci(int n) {
    if(n<=0){
        dp[0] = 0;
        return 0;
    }
    if(n==1){
        dp[1] = 1;
        return 1;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    return dp[n] = fibonacci(n-1) + fibonacci(n-2);
    
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int z = 0;z<T;z++){
        int N;
        cin >> N;
        if(N==0){
            printf("%d %d\n", 1, 0);
        }
        else if(N==1){
            printf("%d %d\n", 0, 1);
        }
        else{
            fibonacci(N);
            printf("%d %d\n", dp[N-1], dp[N]);
        }
    }
}
