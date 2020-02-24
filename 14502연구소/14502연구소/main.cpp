//
//  main.cpp
//  14502연구소
//
//  Created by 김다은 on 26/08/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int arr[8][8] = {0,};
int cpyArr[8][8] = {0,};
int afterWall[8][8] = {0,};
queue<pair<int, int>> q;


int maxCnt = 0;


void bfs(){
    memcpy(afterWall, cpyArr, sizeof(cpyArr));
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(afterWall[i][j]==2){
                q.push(make_pair(i, j));
            }
        }
    }
    
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
            
            if(afterWall[x][y]==0){
                afterWall[x][y]=2;
                q.push(make_pair(x, y));
            }
        }
    }
    
    int cnt = 0;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(afterWall[i][j]==0){
                cnt++;
            }
        }
        
    }
    maxCnt = max(maxCnt, cnt);
    
    
}


void makeWall(int depth){
    if(depth==3){
        bfs();
        return;
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(cpyArr[i][j]==0){
                cpyArr[i][j] = 1;
                makeWall(depth+1);
                cpyArr[i][j] = 0;
                
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin >> arr[i][j];
        }
    }
    
   
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(arr[i][j]==0){
                memcpy(cpyArr, arr, sizeof(arr));
                
                cpyArr[i][j] = 1;
                
                
                makeWall(1);
                
                cpyArr[i][j] = 0;
            }
        }
    }
    

   
    cout<< maxCnt <<endl;
}
