//
//  main.cpp
//  12761돌다리
//
//  Created by 김다은 on 06/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

bool vis[100001] = {0};

void BFS(int N, int M, int A, int B, int cnt){
    queue<pair<int, int>> q;
    q.push(make_pair(N, cnt));
    vis[N] = 1;
    int dx[8]={1, -1, A, B, -A, -B, A, B}; //[+1, -1, +A, +B, -A, -B, *A, *B]
    while (!q.empty()) {
        int a = q.front().first;
        int time = q.front().second;
        q.pop();
        if(a==M){
            cout<< time <<endl;
            return;
        }
        int next = 0;
        for(int i = 0;i<8;i++){
            if(i>=6){
                next = a * dx[i];
            }
            else{
                next = a + dx[i];
            }
            if(next >=0 && next <= 100000){
                if(!vis[next]){
                    q.push(make_pair(next, time+1));
                    vis[next] = 1;
                }
            }
        }
        
    }
}

int main(int argc, const char * argv[]) {
    int A, B, N, M;
    cin >> A>>B>>N>>M;
    
    int cnt = 0;
    BFS(N, M, A, B, cnt);

    return 0;
}
