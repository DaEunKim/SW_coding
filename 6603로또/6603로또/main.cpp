//
//  main.cpp
//  6603로또
//
//  Created by 김다은 on 2020/06/01.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int k;
int S[13] = {0, };
int vis[13] = {0, };


void dfs(int cur, int depth){
    if(depth==6){
        for(int i = 0;i<6;i++){
            cout<< vis[i]<<" ";
        }
        cout<<endl;
    }
    for(int i = cur;i<k;i++){
        vis[depth] = S[i];
        dfs(i+1, depth+1);
    }
    
}

int main(int argc, const char * argv[]) {
    while (1) {
        cin >> k;
        if(k==0){
            break;;
        }
        memset(S, 0, sizeof(S));
        for(int i = 0;i<k;i++){
            cin >> S[i];
        }
        dfs(0, 0);
        cout<<endl;
        
    }
}
