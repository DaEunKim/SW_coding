//
//  main.cpp
//  ST_problem5
//
//  Created by 김다은 on 10/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[100001][100001] = {0};
int visited[100001] = {0};

void dfs(int cur){
    cout<< cur<<" ";
    if(cur<0){
        cout<< "-1" <<endl;
    }
    visited[cur] = 1;
    for(int i = 1;i<=N;i++){
        if(!visited[i] && arr[cur][i]==1){
            visited[i] = 1;
            dfs(i);
        }
    }
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int z = 0;z<T;z++){
        cin >> N >> M;
        
        for(int i = 0;i<M;i++){
            int a, b;
            cin >> a>> b;
            arr[a][b] = arr[b][a] = 1;
        }
        dfs(N);
        
    }
    return 0;
}
