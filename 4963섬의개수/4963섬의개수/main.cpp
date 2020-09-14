//
//  main.cpp
//  4963섬의개수
//
//  Created by 김다은 on 2020/09/14.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[51][51]= {0,};
int vis[51][51] = {0,};
int w, h;
int cnt = 0;
queue<pair<int, int>> q;

void bfs(int a, int b){
    q.push(make_pair(a, b));
    cnt++;
    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        
        int dx[8] = {1,0,-1,0, 1, -1, 1, -1};
        int dy[8] = {0,1,0,-1, -1, -1, 1, 1};
        
        for(int i = 0;i<8;i++){
            int x = nx + dx[i];
            int y = ny + dy[i];
            if(x<0 || y<0 || x>=h || y>=w)
                continue;
            if(!vis[x][y] && arr[x][y] == 1){
                vis[x][y] = 1;
                q.push(make_pair(x, y));
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    while (1) {
        cin >> w>>h;
        if(w==0 && h==0){
            break;
        }
        cnt = 0;
        memset(arr, 0, sizeof(arr));
        memset(vis, 0, sizeof(vis));
        for(int i = 0;i<h;i++){
            for(int j = 0;j<w;j++){
                cin >> arr[i][j];
            }
        }
        for(int i = 0;i<h;i++){
            for(int j = 0;j<w;j++){
                if(!vis[i][j] && arr[i][j]==1){
                    bfs(i, j);
                    vis[i][j] = 1;
                }
            }
        }
        cout<< cnt<<endl;

    }
}
