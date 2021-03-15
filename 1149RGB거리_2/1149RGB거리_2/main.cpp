//
//  main.cpp
//  1149RGB거리_2
//
//  Created by 김다은 on 2021/02/15.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    int arr[1001][1001] = {0,};
    int dp[1001][1001] = {0,};
    
    cin >> N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<3;j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1;i<=N;i++){
        
        dp[i][0] = arr[i-1][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = arr[i-1][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = arr[i-1][2] + min(dp[i-1][0], dp[i-1][1]);
    }
    
    int result = 0;
    result = min(min(dp[N][0], dp[N][1]), dp[N][2]);
    cout<< result<<endl;
    

}
