//
//  main.cpp
//  1697숨바꼭질
//
//  Created by 김다은 on 08/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int N, K;
int visited[100001] = {0};

void shortestTime(int cur, int time){
    queue<pair<int, int>> q;
    q.push(make_pair(cur, time));
    visited[cur] = 1;
    
    
    while (!q.empty()) {
        int a = q.front().first;
        int t = q.front().second;
        q.pop();
        
        if(a==K){
            cout<< t <<endl;
            break;
        }
        
        int dx[3] = {1, -1, 2};
        for(int i = 0;i<3;i++){
            int x =0;
            if(i==2) x = a * dx[i];
            else x = a + dx[i];
            
            if(x<0 || x>100000)
                continue;
            
            if(!visited[x]){
                visited[x] = 1;
                q.push(make_pair(x, t+1));
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> K;
    
    shortestTime(N, 0);
    
    return 0;
}
