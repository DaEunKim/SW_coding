//
//  main.cpp
//  SW1227미로2
//
//  Created by 김다은 on 02/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool flag = 0;
int arr[101][101] = {0,};
int vis[101][101] = {0,};

void bfs(int a, int b){
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    vis[a][b] = 1;
    
    while (!q.empty()) {
        int aa = q.front().first;
        int bb = q.front().second;
        q.pop();
        
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        for(int i = 0;i<4;i++){
            int x = aa + dx[i];
            int y = bb + dy[i];
            
            if(x<0|| y<0 || x>=100 || y>=100)
                continue;
            if(arr[x][y] == 3){
                flag = 1;
                return;
            }
            if(arr[x][y]==0 && !vis[x][y]){
                vis[x][y] = 1;
                flag = 0;
                q.push(make_pair(x, y));
            }
            
        }
    }
    
}

int main(int argc, const char * argv[]) {
    while (1) {
        int n;
        cin >> n;
        string tmp;
        memset(vis, 0, sizeof(vis));
        for(int i = 0;i<100;i++){
            cin >> tmp;
            for(int j = 0;j<100;j++){
                arr[i][j] = tmp.at(j)-'0';
                if(arr[i][j]==1)
                    vis[i][j] = 1;
            }
        }
        
        for(int i = 0;i<100;i++){
            for(int j = 0;j<100;j++){
                if(arr[i][j]==2){
                    bfs(i, j);
                }
            }
        }
        if(flag == 1)
            cout<< "#"<<n<<" "<< 1 <<endl;
        else
            cout<< "#"<<n<<" "<< 0 <<endl;
        
        if(n==10)
            break;
    }
    return 0;
}

