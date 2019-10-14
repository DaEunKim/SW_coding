//
//  main.cpp
//  9095_123더하기
//
//  Created by 김다은 on 2019/10/14.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int dp(int n, int cnt){
    if(n == 0){
        cnt++;
        return cnt;
    }
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(n > 2){
        return dp(n-1, cnt) + dp(n-2, cnt) + dp(n-3, cnt);
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    int testCase[11] = {0,};
    for(int i = 0; i < T; i++){
        cin >> testCase[i];
        int cnt = 0;
        cout<< dp(testCase[i], cnt) <<endl;
    }
}

