//
//  main.cpp
//  2178미로탐색_2
//
//  Created by 김다은 on 2020/03/26.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int vis[101][101] = {0,};
int arr[101][101] = {0,};
queue<pair<int, int>> q;

void bfs(int a, int b){
    q.push(make_pair(a, b));
    vis[a][b] = 1;
    
    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        for(int i = 0;i<4;i++){
            int x = nx + dx[i];
            int y = ny + dy[i];
            
            if(x<0 || y<0 || x>=N || y>=M)
                continue;;
            if(!vis[x][y] && arr[x][y]==1){
                vis[x][y] = vis[nx][ny] + 1;
                q.push(make_pair(x, y));
            }
        }
        
        
    }
}
int main(int argc, const char * argv[]) {
    cin >> N >>M;
    string s;
    for(int i = 0;i<N;i++){
        cin >> s;
        for(int j = 0;j<M;j++){
            arr[i][j] = (int)(s.at(j) -'0');
        }
    }
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(!vis[i][j] && arr[i][j] == 1){
                bfs(i, j);
            }
        }
    }
    cout<< vis[N-1][M-1] <<endl;
}
