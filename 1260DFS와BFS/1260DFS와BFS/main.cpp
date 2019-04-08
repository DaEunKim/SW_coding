//
//  main.cpp
//  1260DFS와BFS
//
//  Created by 김다은 on 08/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int N, M, V;
int arr[1001][1001]={0,};
int vis_DFS[10001] ={0};
int vis_BFS[10001]={0};

void DFS(int cur){
    vis_DFS[cur] = 1;
    cout<< cur <<" ";
    for(int i = 1;i<=N;i++){
        if(!vis_DFS[i] && arr[cur][i]==1){
            DFS(i);
        }
    }
}

void BFS(int cur){
    queue<int> q;
    q.push(cur);
    vis_BFS[cur] = 1;
    
    while (!q.empty()) {
        int a = q.front();
        cout<< a <<" ";
        q.pop();
        for(int i = 1;i<=N;i++){
            if(!vis_BFS[i] && arr[a][i]==1){
                vis_BFS[i] = 1;
                q.push(i);
            }
            
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> N >> M >> V;
    
    for(int i = 0;i<M;i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }
    DFS(V);
    puts("");
    BFS(V);
    return 0;
}
