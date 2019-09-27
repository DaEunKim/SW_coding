//
//  main.cpp
//  1463_1로만들기
//
//  Created by 김다은 on 06/08/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;


int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    int dp[1000001] = {0, };
    
    for(int i = 2;i<=N;i++){
        dp[i] = dp[i-1] +1;
        if(i%2==0){
            dp[i] = min(dp[i], dp[i/2]+1);
        }
        if(i%3==0){
            dp[i] = min(dp[i], dp[i/3]+1);
        }

    }
    cout<< dp[N] <<endl;
    
    
}
