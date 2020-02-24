//
//  main.cpp
//  16236아기상어
//
//  Created by 김다은 on 06/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int N;
queue<pair<int, int>> q;
queue<pair<int, int>> onlyFish;
int arr[21][21]= {0,};
int visited[21][21]= {0,};
int moveTime = 0;
int sizeOfShark = 2;
int eatCount = 0;
int M = 0;

//void oneFish(int a, int b){
//    onlyFish.push(make_pair(a, b));
//    while (!onlyFish.empty()) {
//        int nx = onlyFish.front().first;
//        int ny = onlyFish.front().second;
//        onlyFish.pop();
//        int dx[4] = {1, 0, -1, 0};
//        int dy[4] = {0, 1, 0, -1};
//        for(int i = 0;i<4;i++){
//            int x = nx + dx[i];
//            int y = ny + dy[i];
//            if(x<0 || y<0 || x>N || y>N)
//                continue;
//            if(arr[x][y]==0){
//
//            }
//        }
//
//    }
//}


void bfs(int a, int b){
    q.push(make_pair(a, b));
    visited[a][b] = 1;
//    if(M==1){
//
//    }
//    else if(M>1){
//
//    }
    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        moveTime++;
        q.pop();
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        for(int i = 0;i<4;i++){
            int x = nx + dx[i];
            int y = ny + dy[i];
            if(x<0 || y<0 || x>N || y>N)
                continue;
            if(!visited[x][y] && arr[x][y]==0){
                visited[x][y] = 1;
//                q.push(make_pair(x, y));
                moveTime++;
            }
            else if(!visited[x][y] && arr[x][y]==sizeOfShark){
//                q.push(make_pair(x, y));
//                arr[x][y] = 0;
                visited[x][y] = 1;
                moveTime++;
            }
            else if(!visited[x][y] && arr[x][y] < sizeOfShark){
                eatCount++;
                q.push(make_pair(x, y));
                visited[x][y] = 1;
                if(eatCount==sizeOfShark){
                    sizeOfShark++;
                }
            }
        }

    }
    
}

int main(int argc, const char * argv[]) {
    
    cin >> N;
    
    for(int i = 0;i<N;i++){
        for(int j =0;j<N;j++){
            cin >> arr[i][j];
            
        }
    }
    for(int i = 0;i<N;i++){
        for(int j =0;j<N;j++){
            if(arr[i][j]>=1 && arr[i][j]<=6){
                M++;
            }
            
        }
    }
//    cout<< M <<endl;
//    if(M==1){
//
//    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(arr[i][j]==9){
                
                bfs(i, j);
            }
        }
    }
    cout<< moveTime<<endl;
    
}
