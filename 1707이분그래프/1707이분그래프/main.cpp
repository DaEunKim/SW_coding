//
//  main.cpp
//  1707이분그래프
//
//  Created by 김다은 on 2020/03/11.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int V, E;
vector<int> graph[20001];
vector<int> visited;

void dfs(int cur, int color){
    cout<< "vis : "<<" ";
    for(int i = 0;i<sizeof(visited)/sizeof(visited[0]);i++){
        cout<<visited[i]<<" ";
    }
    cout<<endl;
    
    cout<< "graph : "<<" ";
    for(int i = 0;i<graph[cur].size();i++){
        cout<<graph[cur][i]<<" ";
    }
    cout<<endl;
    
    
    for(int i = 0;i<graph[cur].size();i++){
        if(!visited[graph[cur][i]]){
            visited[graph[cur][i]] = color*-1;
            dfs(graph[cur][i], color*-1);
        }
    }
}

bool bipartite(){
    for(int i = 1;i<=V; i++){
        int color = visited[i];
        
        //연결된 요소와 같은 집합(color)을 갖는지 확인
        for(int j = 1;j < graph[i].size(); j++){
            if(color == visited[graph[i][j]])
                return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int K;
    cin >> K;

    for(int z = 0;z<K;z++){
        cin >> V >> E;
        
        for(int i = 0;i<E;i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        visited=vector<int> (V+1,0);

        for(int i = 1;i<=V;i++){
            if(graph[i].size() == 0)
                continue;
            if(!visited[i]){
                visited[i] = 1;
                dfs(i, 1);
            }
            
        }
        if(bipartite()){
            cout<< "YES" <<endl;
        }
        else{
            cout<< "NO" <<endl;
        }
        for(int i=1;i<=V;i++){
            graph[i].clear();
        }
    }
    
}
