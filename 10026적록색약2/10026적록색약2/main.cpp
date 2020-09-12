//
//  main.cpp
//  10026적록색약2
//
//  Created by 김다은 on 2020/07/03.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n;
char arr[101][101];
int red_check[101][101] = {0,};
int blue_check[101][101] = {0,};
int green_check[101][101] = {0,};
queue<pair<int, int>> red;
queue<pair<int, int>> blue;
queue<pair<int, int>> green;

int r_cnt = 0;
int b_cnt = 0;
int g_cnt = 0;
bool color_weakness = true;

void bfs(int i, int j){
    
    if(arr[i][j]=='R'){
        r_cnt++;
        red.push(make_pair(i, j));
        red_check[i][j] = 1;
    }
    if(arr[i][j]=='B'){
        b_cnt++;
        blue.push(make_pair(i, j));
        blue_check[i][j] = 1;
    }
    if(arr[i][j]=='G'){
        g_cnt++;
        green.push(make_pair(i, j));
        green_check[i][j] = 1;
    }
    while (!red.empty()) {
        int a = red.front().first;
        int b = red.front().second;
        red.pop();
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        for(int i = 0;i<4;i++){
            int x = a+dx[i];
            int y = b+dy[i];
            if(x<0 || y<0 || x>=n || y>=n){
                continue;
            }
            if(!red_check[x][y] && arr[x][y]=='R'){
                red.push(make_pair(x, y));
                red_check[x][y] = 1;
            }
        }
    }
    while (!blue.empty()) {
        int a = blue.front().first;
        int b = blue.front().second;
        blue.pop();
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        for(int i = 0;i<4;i++){
            int x = a+dx[i];
            int y = b+dy[i];
            if(x<0 || y<0 || x>=n || y>=n){
                continue;
            }
            if(!blue_check[x][y] && arr[x][y]=='B'){
                blue.push(make_pair(x, y));
                blue_check[x][y] = 1;
            }
        }
    }
    
    while (!green.empty()) {
        int a = green.front().first;
        int b = green.front().second;
        green.pop();
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        for(int i = 0;i<4;i++){
            int x = a+dx[i];
            int y = b+dy[i];
            if(x<0 || y<0 || x>=n || y>=n){
                continue;
            }
            if(!green_check[x][y] && arr[x][y]=='G'){
                green.push(make_pair(x, y));
                green_check[x][y] = 1;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    cin >> n;
    char c;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> c;
            arr[i][j] = c;
        }
    }
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(!red_check[i][j] && !blue_check[i][j] && !green_check[i][j]){
                bfs(i, j);
            }
        }
    }

//  !color weakness
    cout<< r_cnt + b_cnt +g_cnt<<" ";
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(arr[i][j]=='G'){
                arr[i][j] = 'R';
            }
        }
    }
    memset(red_check, 0, sizeof(red_check));
    memset(blue_check, 0, sizeof(blue_check));
    memset(green_check, 0, sizeof(green_check));
    r_cnt = b_cnt = g_cnt = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(!red_check[i][j] && !blue_check[i][j] && !green_check[i][j]){
                bfs(i, j);
            }
        }
    }
    cout<< r_cnt + b_cnt + g_cnt<<endl;
}
