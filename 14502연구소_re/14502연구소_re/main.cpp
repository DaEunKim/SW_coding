//
//  main.cpp
//  14502연구소_re
//
//  Created by 김다은 on 2019/11/15.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[8][8] = {0,};
int visit[8][8] = {0,};
vector<pair<int, int>> virus;

void copy(int arr[8][8], int arr_copy[8][8]){
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++){
            arr_copy[i][j] = arr[i][j];
        }
    }
}

int checkArr(){
    int cnt = 0;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(arr[i][j] ==0)
                cnt++;
        }
    }
    return cnt;
}

void bfs(){
    queue<pair<int, int>> q;
    for(int i = 0;i<virus.size();i++){
        q.push(virus[i]);
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
            if(x<0 || y<0 || x>=N || y>=M)
                continue;
            if(arr[x][y]==0){
                arr[x][y] = 2;
                q.push(make_pair(x, y));
            }
        }
    }
}

int maxValue = 0;
void make_fence(int a, int b, int wall){
    arr[a][b] = 1;
    visit[a][b] = 1;
    if(wall==3){
        int tmp[8][8]={0,};
        copy(arr, tmp);
        bfs();
        int count = checkArr();
        copy(tmp, arr);
        
        maxValue = max(maxValue, count);
        arr[a][b] = 0;
        visit[a][b] = 0;
        return;
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(!visit[i][j] && arr[i][j]==0){
                make_fence(i, j, wall+1);
            }
        }
    }
    arr[a][b] = 0;
    visit[a][b] = 0;
}

int main(int argc, const char * argv[]) {
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin >> arr[i][j];
            if(arr[i][j]==2){
                virus.push_back(make_pair(i, j));
            }
        }
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(arr[i][j]==0){
                make_fence(i, j, 1);
            }
        }
    }
    cout<< maxValue<<endl;
}
