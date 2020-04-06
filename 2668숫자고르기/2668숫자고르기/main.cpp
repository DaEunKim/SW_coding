//
//  main.cpp
//  2668숫자고르기
//
//  Created by 김다은 on 06/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int map[101] = {0};
int vis[101] = {0};
int cycle[101] = {0};
int N;
int cnt = 0;

//bool DFS(int cur){
//    if(vis[cur])
//        return true;
//    vis[cur] = 1;
//
//    for(int i = 1;i<=N;i++){
//        if(map[cur] == i){
//            cnt++;
//            cycle[cur] = 1;
//            DFS(i);
//
//        }
//    }
//    return false;
//}

bool dfs(int cur, int node){//사이클을 이루면 true

    if(vis[node])
        return false;
    vis[node] = 1;

    if(cur == node || dfs(cur, map[node])){//사이클인지 검사하고, 아니면 dfs
        cnt++;
        cycle[node] = 1;

        return true;
    }

    return false;
}

int main(int argc, const char * argv[]) {
    cin >> N;
    
    for(int i = 1;i<=N;i++){
        cin >> map[i];
    }
    
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            vis[j] = cycle[j];
        }
        dfs(i, map[i]);
        
//        DFS(i);
    }
    
    
    cout<< cnt<<endl;
    for(int i = 1;i<=N;i++){
        if(cycle[i]!=0)
            cout<< i <<endl;
    }
    return 0;
}
