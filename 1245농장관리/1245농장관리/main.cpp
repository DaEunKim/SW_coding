//
//  main.cpp
//  1245농장관리
//
//  Created by 김다은 on 2021/01/04.
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

void dfs(int start){
    check[start]= true;
    printf("%d ", start);
    int first = arr[start][0];
    for(int i=1; i < M; i++){
        int next = arr[start][i];
        if(first > next){
            
        }
        // 방문하지 않았다면
        if(check[next]==false){
            // 재귀함수를 호출한다.
            dfs(next);
        }
    }
}

void bfs(int a, int b){
//    cout<< a <<" "<<b<<endl;
    q.push(make_pair(a, b));
    visited[a][b] = 1;
    cnt++;
//    for(int i = 0;i<N;i++){
//        for(int j = 0;j<M;j++){
//            cout<< visited[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<< a<<" "<<b<<endl;

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
            
            if(!visited[x][y] && arr[a][b] >= arr[x][y] && arr[x][y]!=0 && arr[nx][ny] >= arr[x][y]){
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
    
    for(int i = 0;i<N;i++){
//        dfs(i);
        for(int j = 0;j<M;j++){
            if(!visited[i][j] && arr[i][j]!=0){
//                cout<< i << " "<<j<<endl;
                bfs(i, j);
            }
        }
    }
    cout<< cnt<<endl;
//    cout<< total<<endl;
}
