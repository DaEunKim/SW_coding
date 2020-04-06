//
//  main.cpp
//  kakao7
//
//  Created by 김다은 on 07/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
int visited[101][101] = {0, };

void bfs(vector<vector<int>> board){
    q.push(make_pair(0, 0));
    q.push(make_pair(0, 1));
    visited[0][0]=1;
    visited[0][1]=1;
    
    while (!q.empty())
    {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        for(int i = 0;i<4;i++)
        {
            int x = nx + dx[i];
            int y = ny + dy[i];
            if(x<0 || y<0 || x >= board.size() || y >= board.size())
                continue;
            if(!visited[x][y] && board[x][y]==0){
                visited[x][y] = visited[nx][ny] + 1;
                q.push(make_pair(x, y));
            }
        }
    }
    
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    bfs(board);
    answer = visited[board.size()-1][board.size()-1] - 1;
    return answer;
}
int main(int argc, const char * argv[]) {
    vector<vector<int>> v(5);

    v[0] = {0, 0, 0, 1, 1};
    v[1] = {0, 0, 0, 1, 0};
    v[2] = {0, 1, 1, 1, 1};
    v[3] = {0, 1, 0, 0, 1};
    v[4] = {0, 0, 0, 0, 0};

    printf("%d\n ",solution(v));
    return 0;
}
