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

int home_x = 0, home_y =0;
int rock_x = 0, rock_y = 0;
vector<pair<int, int>> store;
bool flag = true;
int vis[101];

void dfs(int a, int b){
    // 50으로 나누면 연산자체가 몫만 남기에 나눗셈 연산을 제외
    int num = abs(rock_x -a) + abs(rock_y - b); // 주어진 문제가 맨해튼 거리.. 두 좌표 사이의 거리는 x 좌표의 차이 + y 좌표의 차이 이다. (맨해튼 거리)
    if(flag == 1 || num <= 1000){ // 초기 flag는 0이기때문에 flag == 1 조건은 초기에 부합하지 않음.
        flag = 1;
        return;
    }
    
    for(int i = 0;i<store.size();i++){// store까지의 거리 중 1000보다 작거나 같은 store 채택
        if(vis[i] == 1) // 방문한 곳은 지나가기
            continue;
        num = abs(store[i].first - a) + abs(store[i].second - b);
        
        if(num > 1000){ // 1000보다 큰 거리는 패스
            continue;
        }
        else{ // 1000보다 작거나 같은 지점은 다음 지점 검사.
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
