//
//  main.cpp
//  14889스타트와링크
//
//  Created by 김다은 on 14/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[21][21] = {0};
bool visited[21] = {0,};
int result = 987654321;

// cur번 선수를 스타트 팀으로 뽑는다, cnt : 뽑은 명수
void dfs(int cnt, int cur){
    if(cnt == N/2){ //팀을 고른 후, 조건에 맞춰서 계산
        vector<int> start_team, link_team;
        for(int i = 0;i<N;i++){
            if(visited[i])
                start_team.push_back(i);// 뽑은 선수들은 스타트팀으로
            else
                link_team.push_back(i);
        }
        
        int sum_start = 0; int sum_link = 0;//*초기화 꼭
        for(int i = 0;i<start_team.size();i++){
            for(int j = i+1;j<start_team.size();j++){
                sum_start += arr[start_team[i]][start_team[j]] + arr[start_team[j]][start_team[i]];
                sum_link += arr[link_team[i]][link_team[j]] + arr[link_team[j]][link_team[i]];
            }
        }
        result = min(result, abs(sum_start - sum_link));
        return;
    }
    
    //visited로 팀 고르기 //완전탐색
    for(int i = cur+1;i<N;i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(cnt+1, i);
            visited[i] = 0; //백트래킹
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin>> arr[i][j];
        }
    }
    dfs(0, 0);
    cout<< result <<endl;
    return 0;
}
