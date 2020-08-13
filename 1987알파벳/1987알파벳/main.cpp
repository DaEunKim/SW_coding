//
//  main.cpp
//  1987알파벳
//
//  Created by 김다은 on 2020/08/05.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int r, c;
char arr[22][22];
int result = 0;
int visited[26] = {0,}; // 알파벳 위치에 여부 체크
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void dfs(int a, int b, int count){
    result = max(result, count);
    for(int i = 0;i<4;i++){
        int x = a + dx[i];
        int y = b + dy[i];
        if(x<0 || y<0 || x>=r || y>=c)
            continue;
        if(!visited[arr[x][y]-'A']){
            visited[arr[x][y]-'A'] = 1;
            dfs(x, y, count+1);
            visited[arr[x][y]-'A'] = 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> r >> c;
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin >> arr[i][j];
        }
    }
    visited[arr[0][0]-'A'] = 1;
    dfs(0,0,1);
    
    cout<< result <<endl;
}
