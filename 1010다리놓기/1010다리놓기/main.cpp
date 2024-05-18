//
//  main.cpp
//  1010다리놓기
//
//  Created by 김다은 on 2020/09/14.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int dp(int n, int m){ // mCn
    if(n==1)
        return m;
    if(m==n)
        return 1;
    if(m==n+1)
        return m;
    return dp(n-1, m-1) + dp(n, m-1);
    
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int z = 0;z<T;z++){
        int N = 0;
        int M = 0;
        cin >> N >> M; // 서쪽, 동쪽
        cout<< dp(N, M)<<endl;;
    }
}
