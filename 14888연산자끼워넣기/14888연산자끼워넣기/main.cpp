//
//  main.cpp
//  14888연산자끼워넣기
//
//  Created by 김다은 on 2020/08/13.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int num[12] = {0,};
int operate[4]={0,}; //+, -, x, ÷ 개수
int maxResult = -1000000001;
int minResult = 1000000001;

void dfs(int plus, int minus, int mul, int div, int cnt, int sum){
    if(cnt==N){
        maxResult = max(maxResult, sum);
        minResult = min(minResult, sum);

    }
    if(plus>0){
        dfs(plus-1, minus, mul, div, cnt+1, sum+num[cnt]);
    }
    if(minus>0){
        dfs(plus, minus-1, mul, div, cnt+1, sum-num[cnt]);
    }
    if(mul>0){
        dfs(plus, minus, mul-1, div, cnt+1, sum*num[cnt]);
    }
    if(div>0){
        dfs(plus, minus, mul, div-1, cnt+1, sum/num[cnt]);

    }

}


int main(int argc, const char * argv[]) {
    cin >> N;

    for(int i = 0;i<N;i++){
        cin >> num[i];
    }
    
    for(int i = 0;i<4;i++){
        cin >> operate[i];
    }
    dfs(operate[0], operate[1], operate[2], operate[3], 1, num[0]);
    cout<< maxResult<<endl;
    cout<< minResult <<endl;
    
}
