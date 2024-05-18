//
//  main.cpp
//  1697숨바꼭질_re
//
//  Created by 김다은 on 2021/02/28.
//

#include <iostream>
#include <queue>
using namespace std;

int vis[100001] = {0,};

int bfs(int n, int k){
    int sec = 0;
    queue<int> q;
    q.push(n);
    
    while (1) {
        unsigned long size = q.size();
        for(int i = 0;i<size;i++){
            n = q.front();
            q.pop();
            if(n==k){
                return sec;
            }
            if(n > 0 && !vis[n-1]){
                vis[n-1] = 1;
                q.push(n-1);
            }
            if(n < 100000 && !vis[n+1]){
                vis[n+1] = 1;
                q.push(n+1);
            }
            if(2*n <= 100000 && !vis[2*n]){
                vis[2*n] = 1;
                q.push(2*n);
            }

        }
        sec++;
    }
    
}
int main(int argc, const char * argv[]) {
    int N, K;
    cin >> N >> K;
    
    cout<< bfs(N, K)<<endl;
    
    return 0;
    
}
