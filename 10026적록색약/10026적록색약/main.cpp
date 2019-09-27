//
//  main.cpp
//  10026적록색약
//
//  Created by 김다은 on 12/08/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<int, int>> q;
char arr[101][101];
int visited[101][101] = {0,};
int cnt1 = 0;
int cnt2 = 0;


void BFS(int N, char c){
    
    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        
        visited[nx][ny] = 1;
        q.pop();
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for(int i = 0;i<4;i++){
            int x = nx + dx[i];
            int y = ny + dy[i];
            if(x<0 || y<0 || x> N || y>N)
                continue;
            if(!visited[x][y] && arr[x][y]==c){
                visited[x][y] = 1;
                q.push(make_pair(x,y));
            }
           
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin >> arr[i][j];

        }
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(!visited[i][j]){
                q.push(make_pair(i, j));
                BFS(N, arr[i][j]);
                cnt1++;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(arr[i][j]=='R'){
                arr[i][j] = 'G';
            }
        }
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(!visited[i][j]){
                q.push(make_pair(i, j));
                BFS(N, arr[i][j]);
                cnt2++;
            }
        }
    }

    cout<< cnt1<<" "<<cnt2<<endl;
    
    
}
