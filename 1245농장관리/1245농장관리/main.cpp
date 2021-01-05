//
//  main.cpp
//  1245농장관리
//
//  Created by 김다은 on 2020/12/10.
//

#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[101][101] = {0,};
int visited[101][101] = {0,};
bool check[101];
queue<pair<int, int>> q;

int cnt = 0;
int answer = 0;

bool isPeak = true;

// dfs 버전
void DFS(int nx, int ny){
    int dx[8] = {0,1,0,-1, 1, -1, 1, -1};
    int dy[8] = {1,0,-1,0, 1, -1, -1, 1};
    for(int i=0; i<8; i++){
        int x = nx + dx[i];
        int y = ny + dy[i];
        
        if(x<0 || y<0 || x>=N || y>=M)
            continue;
        // 인접 칸에 더 높은 봉우리가 있는가?
        if( arr[nx][ny] < arr[x][y] )
            isPeak = false;
        // 해당하는 산봉우리들을 탐색
        if(visited[x][y] || arr[nx][ny] != arr[x][y] )
            continue;
        visited[x][y] = 1;
        DFS(x,y);
        
    }
    return ;
    
}

// bfs 버전
void bfs(int a, int b){
    q.push(make_pair(a, b));
    visited[a][b] = 1;
    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        int dx[8] = {0,1,0,-1, 1, -1, 1, -1};
        int dy[8] = {1,0,-1,0, 1, -1, -1, 1};
        for(int i = 0;i<8;i++){
            int x = nx + dx[i];
            int y = ny + dy[i];
            if(x<0 || y<0 || x>=N || y>=M)
                continue;
            if( arr[nx][ny] < arr[x][y] )
                isPeak = false;
            if(!visited[x][y] && arr[x][y]!=0 && arr[nx][ny] == arr[x][y]){
                q.push(make_pair(x, y));
                visited[x][y] = 1;
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

    // bfs로 풀 경우
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(!visited[i][j] && arr[i][j]!=0){
                isPeak = true;
                bfs(i, j);
                if(isPeak){
                    cnt++;
                }
            }
        }
    }

    cout<< cnt<<endl;

    // dfs로 풀 경우
//    for(int i = 0;i<N;i++){
//        for(int j = 0;j<M;j++){
//            if(!visited[i][j]){
//                isPeak = true;
//                DFS(i, j);
//                if( isPeak )
//                    answer += 1;
//            }
//        }
//    }
//    cout <<answer<<endl;
}
