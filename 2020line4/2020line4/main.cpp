//
//  main.cpp
//  2020line4
//
//  Created by 김다은 on 2020/09/13.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
queue<pair<int, int>> q;
int vis[300][300] = {0,};
int timeCnt = 0;

void bfs(int a, int b, vector<vector<int>> maze, long size){
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
            
            if(x<0 || y<0 || x>=size || y>=size)
                continue;;
            if(!vis[x][y] && maze[x][y]==0){
                vis[x][y] = vis[nx][ny] + 1;
                timeCnt++;
                q.push(make_pair(x, y));
            }
        }
        
        
    }
}
int solution(vector<vector<int>> maze) {
    int answer = 0;
    long long size = maze.size();
    for(int i = 0;i<size;i++){
        for(int j = 0;j<size;j++){
            if(!vis[i][j] && maze[i][j] == 0){
                bfs(i, j, maze, size);
            }
        }
    }
    for(int i = 0;i<size;i++){
        for(int j= 0;j<size;j++){
            cout<< vis[i][j]<<" ";
        }
        cout<<endl;
    }
    if(timeCnt != vis[size-1][size-1]){
        answer = timeCnt + (timeCnt - vis[size-1][size-1])+1;
    }
    else{
        answer = timeCnt;
    }
    return answer;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> maze;
    vector<int> v;
    v = {0, 1, 0, 0, 0, 0};
    maze.push_back(v);
    v = {0, 1, 0, 1, 1, 0};
    maze.push_back(v);
    v = {0, 1, 0, 0, 1, 0};
    maze.push_back(v);
    v = {0, 1, 1, 1, 1, 0};
    maze.push_back(v);
    v = {0, 1, 0, 0, 0, 0};
    maze.push_back(v);
    v = {0, 0, 0, 1, 1, 0};
    maze.push_back(v);
    cout<< solution(maze)<<endl;
}
