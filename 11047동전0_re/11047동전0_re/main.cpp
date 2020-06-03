//
//  main.cpp
//  11047동전0_re
//
//  Created by 김다은 on 2020/04/17.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int n, k;
int vis[11] = {0,};
int min_calc(int value, int *coin){
    vector<pair<int, int>> v;
    for(int i = 0;i<n;i++){
        v.push_back(make_pair(value-coin[i], coin[i]));
    }
    
    int res = v[0].first;
    for(int i = 0;i<v.size();i++){
        if(res> v[i].first && v[i].first > 0){
            res = v[i].first;
        }
    }
    return res;
    
}

int main(int argc, const char * argv[]) {
    
    cin >> n >> k; // k는 지불해야하는 금액
    
    int coin[11] ={0,}; // 동전의 종류
    
    for (int i = 0;i<n;i++){
        cin >> coin[i];
    }
    
    for(int i = 0;i<n;i++){
        vis[coin[i]] = 0;
    }
    while (1) {
        k = min_calc(k, coin);
        if(k < 0)
            break;
        else{
            vis[k] += 1;
        }
    }
    cout<< vis[n-1] <<endl;
}
