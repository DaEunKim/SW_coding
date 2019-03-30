//
//  main.cpp
//  3187양치기꿍
//
//  Created by 김다은 on 30/03/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
int k_cnt =0, v_cnt=0, total_k_cnt=0, total_v_cnt=0;

void BFS(int a, int b, int r, int c, char arr[][251], int vis[][251]){
    q.push(make_pair(a, b));
    vis[a][b] = 1;
    
    if(arr[a][b]=='k') ++k_cnt;
    if(arr[a][b]=='v') ++v_cnt;
    
    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        for(int i = 0;i<4;i++){
            int x = xx+dx[i];
            int y = yy+dy[i];
            if(x<0 || y < 0 || x>=r || y >= c){
                continue;
            }
            if(arr[x][y] == 'k' && !vis[x][y]){
                ++k_cnt;
                vis[x][y] = 1;
                q.push(make_pair(x, y));
            }
            else if(arr[x][y] == 'v' && !vis[x][y]){
                ++v_cnt;
                vis[x][y] = 1;
                q.push(make_pair(x, y));
            }
            else if(arr[x][y] =='.' && !vis[x][y]){
                vis[x][y] = 1;
                q.push(make_pair(x, y));
            }
        }
    }
    if(k_cnt > v_cnt){
        total_k_cnt += k_cnt;
    }
    else{
        total_v_cnt += v_cnt;
    }
    
    k_cnt = 0;
    v_cnt = 0;
}

int main(int argc, const char * argv[]) {
    int r, c;
    cin >> r >> c;
    
    char arr[251][251] = {0,};
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> arr[i][j];
        }
    }
    
    int vis[251][251] ={0,};
    
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(!vis[i][j] && arr[i][j]!='#'){
                BFS(i, j, r, c, arr, vis);
            }
        }
    }
    
    cout<< total_k_cnt <<" "<<total_v_cnt<<endl;
    
    return 0;
}

