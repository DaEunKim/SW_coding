//
//  main.cpp
//  1012유기농배추
//
//  Created by 김다은 on 2020/06/01.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int M, N, K; // 가로길이 M(1 ≤ M ≤ 50)과 세로길이 N(1 ≤ N ≤ 50), 배추가 심어져 있는 위치의 개수 K
int arr[51][51] = {0,};
int vis[51][51] = {0,};
int cnt = 0;
queue<pair<int, int>> q;

void bfs(int x, int y){
    q.push(make_pair(x, y));
    cnt++;
    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for(int i = 0;i<4;i++){
            int nx = a + dx[i];
            int ny = b + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if(!vis[nx][ny] && arr[nx][ny]==1){
                vis[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
        
    }
}



int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int z = 0;z<T;z++){
        cin >> M >> N >> K;
        int x=0, y=0;
        memset(arr, 0, sizeof(arr));
        memset(vis, 0, sizeof(vis));

        for(int i = 0;i<K;i++){
            cin >> x >> y;
            arr[y][x] = 1;
        }
        
        for(int i = 0;i<N;i++){ // 세로(y)
            for(int j = 0;j<M;j++){ // 가로 (x)
                if(!vis[i][j] && arr[i][j]==1){
                    vis[i][j] = 1;
                    bfs(i, j);
                }
            }
        }
        cout<< cnt<<endl;
        cnt = 0;
    }
}
