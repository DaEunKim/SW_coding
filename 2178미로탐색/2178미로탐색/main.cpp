//
//  main.cpp
//  2178미로탐색
//
//  Created by 김다은 on 08/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int N, M;
int maze[101][101] = {0,};
int visited[101][101] = {0};
queue<pair<int, int>> q;

void shortestPath(int a, int b){
    q.push(make_pair(a, b));
    visited[a][b] = 1;
    
    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        for(int i = 0;i<4;i++){
            int x = nx + dx[i];
            int y = ny + dy[i];
            if(x<0 || y<0 || x>=N || y>=M){
                continue;
            }
            if(!visited[x][y] && maze[x][y]==1){
                visited[x][y] = visited[nx][ny] + 1;
                q.push(make_pair(x, y));
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            char tmp;
            cin >> tmp;
            maze[i][j] = tmp -'0';
        }
    }
    shortestPath(0, 0);
    cout<< visited[N-1][M-1]<<endl;
    
    return 0;
}

