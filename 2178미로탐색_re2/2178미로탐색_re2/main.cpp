//
//  main.cpp
//  2178미로탐색_re2
//
//  Created by 김다은 on 2019/11/04.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int N, M;
queue<pair<int, int>> q;
int visited[101][101] = {0,};
int arr[101][101] = {0,};

void bfs(int a, int b){
    q.push(make_pair(a, b));
    visited[a][b] = 1;
    
    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        
        for(int i = 0;i<4;i++){
            int x = nx + dx[i];
            int y = ny + dy[i];
            if(x < 0 || y < 0 || x>=N || x>=M)
                continue;
            if(!visited[x][y] && arr[x][y]==1){
                visited[x][y] = visited[nx][ny] + 1;
                q.push(make_pair(x, y));
            }
        }

    }
    
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    string s;
    for(int i = 0;i<N;i++){
        cin >> s;
        for(int j = 0;j<M;j++){
            arr[i][j] = s.at(j) - '0';
            
        }
    }
    bfs(0, 0);
    cout<< visited[N-1][M-1] <<endl;
}
