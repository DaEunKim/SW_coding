//
//  main.cpp
//  7576토마토
//
//  Created by 김다은 on 09/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int M, N;
int arr[1001][1001] ={0,};

queue<pair<int, int>> q;
void Find(){
    
    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        for(int i = 0;i<4;i++){
            int x = nx + dx[i];
            int y = ny + dy[i];
            if(x<0 || y<0 || x>=N || y>= M)
                continue;
            if(arr[x][y] == 0){
                arr[x][y] = arr[nx][ny] + 1;
//                arr[x][y] = -1;
                q.push(make_pair(x, y));
//                visited[nx][ny] = 0;
//                cout<< x<<", "<<y<<endl;
            }
            
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> M >> N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(arr[i][j]==1){
                q.push(make_pair(i, j));
            }
        }
    }
    Find();
    bool flag = true;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(arr[i][j]==0)
                flag = false;
        }
    }
    
    
    int max_val = -1;
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(max_val < arr[i][j])
                max_val = arr[i][j];
        }
    }
    
    if(flag == true){
        //visited 출력
        cout<< max_val-1 <<endl;
    }
    else{
        cout<< -1 <<endl;
    }
    return 0;
}
