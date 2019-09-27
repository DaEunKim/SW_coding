//
//  main.cpp
//  11726_2xn타일링
//
//  Created by 김다은 on 12/08/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int dp[1001] = {0,};

int tile(int n){
    if(n==1){
        dp[1] =1;
        return 1;
    }
    if(n==2){
        dp[2] =2;
        return 2;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    return dp[n] = (tile(n-1) + tile(n-2))%10007;
    
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    tile(n);
    cout<< dp[n] <<endl;
}
