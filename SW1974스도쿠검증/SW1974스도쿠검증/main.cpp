//
//  main.cpp
//  SW1974스도쿠검증
//
//  Created by 김다은 on 12/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[9][9] = {0};
int visited[9] = {0};

bool Find_horizon(int cur){
    memset(visited, 0, sizeof(visited));
    for(int i = 0;i<9;i++){
        visited[arr[cur][i]] = 1;
    }
    
    for(int i =1;i<=9;i++){
        if(visited[i]==0)
            return false;
    }
    return true;
}

bool Find_vertical(int cur){
    memset(visited, 0, sizeof(visited));
    for(int i = 0;i<9;i++){
        visited[arr[i][cur]] = 1;
    }
    
    for(int i =1;i<=9;i++){
        if(visited[i]==0)
            return false;
    }
    return true;
}

bool threeBythree(int a, int b){
    queue<pair<int, int>> q;
    memset(visited, 0, sizeof(visited));
    q.push(make_pair(a, b));

    while (!q.empty()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        
        int dx[] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
        int dy[] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
        for(int i= 0;i<9;i++){
            int x = nx + dx[i];
            int y = ny + dy[i];
            
            if(x<0 || y<0 || x>=9 || y>=9)
                continue;
            if(!visited[arr[x][y]]){
                visited[arr[x][y]] = 1;
            }
        }
    }
    
    for(int i =1;i<=9;i++){
        if(visited[i]==0)
            return false;
    }
    return true;
    
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int z = 0;z<T;z++){
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                cin >> arr[i][j];
            }
        }
        
        bool answer = true;
        for(int i = 0;i<9;i++){
            if(!Find_horizon(i) || !Find_vertical(i)){
                answer = false;
                break;
            }
            else{
                if(!threeBythree(0, 0) || !threeBythree(0, 3) || !threeBythree(0, 6) ||
                   !threeBythree(3, 0) || !threeBythree(3, 3) || !threeBythree(3, 6) ||
                   !threeBythree(6, 0) || !threeBythree(6, 3) || !threeBythree(6, 6)){
                    answer = false;
                    break;
                }
            }
        }
        
        
        
        cout<<"#"<<z+1<<" "<<answer<<endl;
    }
    return 0;
}
