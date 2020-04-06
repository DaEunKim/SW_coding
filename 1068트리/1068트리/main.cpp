//
//  main.cpp
//  1068트리
//
//  Created by 김다은 on 28/03/2020.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N; // 노드의 개수
int DelNode;
int result = 0;
int vis[51] = {0,};
vector<int> node[51];

void bfs(int cur){
    queue<int> q;
    q.push(cur);
    vis[cur] = 1;
    
    while (!q.empty()) {
        int nx = q.front();
        q.pop();
        
        int childCnt = 0;
        long size = node[nx].size();
        for(long i = 0;i<size;i++){
            int next = node[nx][i];
            if(!vis[next]){
                vis[next] = 1;
                q.push(next);
                childCnt++; // 자식 노드를 카운트
            }
        }
        if(childCnt == 0){ // 자식 노드 없는 애
            result++;
        }
        
    }
    
}
int main(int argc, const char * argv[]) {
    cin >> N;
    
    
    int tmp = 0;
    
    int rootNode = 0;
    for(int i = 0;i<N;i++){
        cin >> tmp;
        if(tmp != -1){
            node[tmp].push_back(i); // 1 0/ 2 0 /3 1 /4 1
            node[i].push_back(tmp); // 0 1/ 0 2/ 1 3/ 1 4
        }
        else{
            rootNode = i;
        }
    }
    cin >> DelNode;
    // 지울 노드를 빼고 자식이 없는 노드를 카운트
    
    vis[DelNode] = 1;
    
    if(!vis[rootNode]){
        bfs(rootNode);
    }
    
    cout<< result<<endl;
}
