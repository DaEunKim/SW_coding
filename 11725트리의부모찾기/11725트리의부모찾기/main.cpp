//
//  main.cpp
//  11725트리의부모찾기
//
//  Created by 김다은 on 2021/03/15.
//

#include <iostream>
#include <vector>
using namespace std;

int N;

vector<int> v[100001];
int parent_node[100001];
int vis[100001] = {0,};

void dfs(int cur){
    vis[cur] = 1;
    for(int i = 0;i<v[cur].size();i++){
        int next = v[cur][i];

        if(!vis[next]){
            parent_node[next] = cur;
            dfs(next);

        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 속도 향상 위해
    
    cin >> N;
    
    int v1, v2;
    for(int i = 0;i<N-1;i++){
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    
    dfs(1);

    for(int i = 2;i<=N;i++){
        cout<< parent_node[i]<<"\n";
    }
    
}
