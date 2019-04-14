//
//  main.cpp
//  15686치킨배달
//
//  Created by 김다은 on 09/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 987654321

int N, M;
int arr[101][101]={0,};
int visited[101]={0,};
int result;
vector<pair<int, int>> house, chicken;

int distance(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void DFS(int cur, int seleted){
    
    //M개의 치킨집이 정해지면 조건 계산
    if(seleted == M){
        int total = 0;
        for(int i = 0;i<house.size();i++){
            int dist = INF;
            for(int j = 0;j<chicken.size();j++){
                if(visited[j]){
                    dist = min(dist, distance(house[i], chicken[j]));
                }
            }
            total += dist;
        }
        result = min(result, total);
        return;
    }
    
    if(cur == chicken.size())//2를 다 선택하면
        return;
    
    //프랜차이즈 선정
    //현재 치킨집을 사용할 경우
    visited[cur] = 1;
    DFS(cur+1, seleted+1);
    
    //프랜차이즈 선정 X(사용 X)
    visited[cur] = 0;
    DFS(cur+1, seleted);

}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin >> arr[i][j];
            if(arr[i][j]==1)
                house.push_back(make_pair(i, j));
            else if(arr[i][j]==2)
                chicken.push_back(make_pair(i, j));
        }
    }
    
    result = INF;
    DFS(0, 0);
    
    cout<< result <<endl;
    return 0;
}
