//
//  main.cpp
//  2667단지번호붙이기
//
//  Created by 김다은 on 22/08/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

char arr[25][25];
queue<pair<int, int>> q;
int areaCount = 0;
int areaSize = 0;
int visited[25][25] = {0,};

void BFS(int a, int b, int N){
    visited[a][b]=1;
    
    while (!q.empty()) {
        q.pop();
        
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        
        for(int i = 0;i<4;i++){
            int x = a + dx[i];
            int y = b + dy[i];
            if(x<0 || y<0 || x>=N || y>=N)
                continue;
            if(!visited[x][y] && arr[x][y]=='1'){
                q.push(make_pair(x, y));
                visited[x][y] += 1;
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
            if(!visited[i][j] && arr[i][j]=='1'){
                areaCount++;
                q.push(make_pair(i, j));
                BFS(i, j , N);
            }
        }
    }
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cout<< visited[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<< areaCount <<endl;
    cout<< areaSize <<endl;
    
}
