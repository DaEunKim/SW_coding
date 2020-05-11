//
//  main.cpp
//  9205맥주마시면서걸어가기
//
//  Created by 김다은 on 20/04/2020.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

double dist(int dep_x, int dep_y, int arr_x, int arr_y){
    return sqrt((dep_x - arr_x)*(dep_x - arr_x) + (dep_y - arr_y)*(dep_y - arr_y));
}
int home_x = 0, home_y =0;
int rock_x = 0, rock_y = 0;
vector<pair<int, int>> store;
bool flag = true;
int vis[101];

void dfs(int a, int b){
    // 50으로 나누면 연산자체가 몫만 남기에 나눗셈 연산을 제외
    int num = abs(rock_x -a) + abs(rock_y - b);// dist(rock_x, rock_y, a, b);
    
    if(flag == 1 || num <= 1000){
        flag = 1;
        return;
    }
    
    for(int i = 0;i<store.size();i++){
        if(vis[i] == 1)
            continue;
        num = abs(store[i].first - a) + abs(store[i].second - b); // dist(store[i].first, store[i].second, a, b);
        
        if(num > 1000){
            continue;
        }
        else{
            vis[i] = 1;
            dfs(store[i].first, store[i].second);
        }
        
    }
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    for(int z = 0;z<t;z++){
        int n;
        cin >> n;
        cin >> home_x >> home_y;
        
        int store_x, store_y;
        store.clear();
        memset(vis, 0, sizeof(vis));
        for(int i = 0;i<n;i++){
            cin >> store_x >> store_y;
            store.push_back(make_pair(store_x, store_y));
        }
        cin >> rock_x >> rock_y;
        flag = 0;
        dfs(home_x, home_y);
        
        if(flag){
            cout<<"happy"<<endl;
        }
        else{
            cout<<"sad"<<endl;
        }
    }
}
