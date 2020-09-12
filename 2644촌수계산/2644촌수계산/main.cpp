//
//  main.cpp
//  2644촌수계산
//
//  Created by 김다은 on 2020/07/22.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
queue<int> q;
int findParents, findChild;
int arr[101][101] = {0,};
int vis[101]= {0,};

void bfs(int findParents){
    q.push(findParents);
    
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        
        for(int i = 1;i<=n;i++){
            if (arr[a][i] == 1 && !vis[i]){
                q.push(i);
                vis[i] = vis[a] + 1;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> n; // 전체 사람의 수
    
    cin >> findParents >> findChild;
    
    int relationN;
    cin >> relationN;
    
    int parents, child;
    
    for(int i = 0;i<relationN;i++){
        cin >> parents >> child;
        arr[parents][child] = 1;
        arr[child][parents] = 1;

    }
    bfs(findParents);
    if(vis[findChild]!=0)
        cout<< vis[findChild] <<endl;
    else
        cout<<"-1"<<endl;
}
