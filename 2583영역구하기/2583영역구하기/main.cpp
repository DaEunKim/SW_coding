//
//  main.cpp
//  2583영역구하기_re
//
//  Created by 김다은 on 2018. 4. 9..
//  Copyright © 2018년 김다은. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int M,N,K;
int field[101][101]={0,};
int vis[101][101] = {0,};
int area = 0;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void dfs(int a, int b){
    vis[a][b] = 1;
    ++area;
    for(int i = 0;i<4;i++){
        int x = a + dx[i];
        int y = b + dy[i];
        
        if(x<0 || y<0 || x>=M || y>=N) continue;
        if(!vis[x][y] && field[x][y]==0){
            dfs(x, y);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> M >> N >> K;
    
    int left_x, left_y;
    int right_x, right_y;
    
    memset(field, 0, sizeof(field));
    for(int z = 0; z < K; z++){
        cin >> left_x >> left_y >> right_x >> right_y;
        
        for(int i = left_x; i < right_x; i++){
            for(int j = left_y; j < right_y; j++){
                field[j][i] = 1;
            }
        }
    }
    
    int cnt = 0;
    vector<int> v;
    for(int i = 0; i<M; i++){
        for(int j = 0; j<N; j++){
            if(!vis[i][j] && field[i][j]==0){
                cnt++;
                area = 0;
                dfs(i, j);
                v.push_back(area);
            }
        }
    }
    cout<< cnt<<endl;
    
    sort(v.begin(), v.end());
    for(auto i = v.begin();i!=v.end();i++){
        cout<< *i <<" ";
    }
    cout<<endl;
    
    
    
    return 0;
}


