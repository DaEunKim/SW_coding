//
//  main.cpp
//  ST_problem4
//
//  Created by 김다은 on 10/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

void BFS(int cur){
    queue<int> q;
    q.push(cur);
    vis_BFS[cur] = 1;
    
    while (!q.empty()) {
        int a = q.front();
        cout<< a <<" ";
        q.pop();
        for(int i = 1;i<=N;i++){
            if(!vis_BFS[i] && arr[a][i]==1){
                vis_BFS[i] = 1;
                q.push(i);
            }
            
        }
        
    }
    
}

int vis[1001] = {0,};
int N, K;//별의 수 , 여행을 할 수 있는 최대 기간
int t[10001] = {0};
int w[1000001] = {0};

void bfs(int a, int b){
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    
    while (!q.empty()) {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();
        
        for(int i = 0;i<N;i++){
            if(!vis[i]){
                q.push(make_pair(cur, time));
            }
        }
        
        
    }
}
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int z = 0;z<T;z++){
        
        cin >> N >> K;
        
        
        
        for(int i = 0;i<2*N;i++){
            cin >> t[i] >> w[i];
        }

        for(int i = 0;i<2*N;i++){
            bfs(t[i], w[i]);
        }
        
    }
    return 0;
}
