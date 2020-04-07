//
//  main.cpp
//  1068트리
//
<<<<<<< HEAD
//  Created by 김다은 on 28/03/2020.
=======
//  Created by 김다은 on 2020/03/30.
>>>>>>> a44af2984420b7dcf3cdd5d89b08701fc040bc54
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
<<<<<<< HEAD
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
=======
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> graph[51];
int vis[51] = {0,};
int result = 0;

void bfs(int cur){
    vis[cur] = 1;
    queue<int> q;
    q.push(cur);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        int childCnt = 0; // 자식의 숫자를 계산할 변수
        for(int i = 0;i<graph[node].size();i++){
            int next = graph[node][i];
            if(!vis[next]){
                childCnt++;
                vis[next] = 1;
                q.push(next);
            }
        }
        // 자식이 없으면 단말 노드 계수를 1 증가 시킵니다.
        if(childCnt == 0){
            result++;
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> N;
    
    int rootNode = 0;
    for(int i = 0;i<N;i++){
        int tmp;
        cin >> tmp;
        if(tmp != -1){ // 인접 리스트를 사용해서 양방향 그래프로 트리를 만들어줍니다.
            graph[i].push_back(tmp);
            graph[tmp].push_back(i);
>>>>>>> a44af2984420b7dcf3cdd5d89b08701fc040bc54
        }
        else{
            rootNode = i;
        }
    }
<<<<<<< HEAD
    cin >> DelNode;
    // 지울 노드를 빼고 자식이 없는 노드를 카운트
    
    vis[DelNode] = 1;
    
=======
    int delNode; // 지울 노드 표시
    cin >> delNode;
    
    // 이 노드를 제외한 노드의 자식을 카운트 하는 로직
    vis[delNode] = 1;
    
   // 만약 지워진 노드가 루트 노드가 아니라면 탐색을 시작합니다.
>>>>>>> a44af2984420b7dcf3cdd5d89b08701fc040bc54
    if(!vis[rootNode]){
        bfs(rootNode);
    }
    
<<<<<<< HEAD
    cout<< result<<endl;
=======
    cout<<result<<endl;
>>>>>>> a44af2984420b7dcf3cdd5d89b08701fc040bc54
}
