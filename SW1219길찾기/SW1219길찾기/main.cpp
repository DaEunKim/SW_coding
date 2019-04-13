//
//  main.cpp
//  SW1219길찾기
//
//  Created by 김다은 on 13/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int arr[101][101] = {-1,};
int visited[101] = {0,};
int total_num;
int answer = 0;

void dfs(int cur){
    visited[cur] = 1;
    
    if(cur == 99){
        answer = 1;
        return;
    }
    for(int i = 0;i<101;i++){
        if(!visited[i] && arr[cur][i]==1){
            dfs(i);
        }
    }
}

int main(int argc, const char * argv[]) {
    while (1) {
        int T;
        cin >> T >> total_num;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        answer = 0;
        for(int i = 0;i<total_num;i++){
            int a, b;
            cin >> a>> b;
            arr[a][b] = 1;
        }
        
        
        dfs(0);
        cout<< "#"<<T<<" "<<answer<<endl;
        
        if(T==10)
            break;
        
    }
    return 0;
}
