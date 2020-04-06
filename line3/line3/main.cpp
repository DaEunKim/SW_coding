//
//  main.cpp
//  line3
//
//  Created by 김다은 on 2020/04/06.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> road_vector;
int visited[300001] = {0,};
int maxValue = 0;

int value = 0;
int area = 0;

void find_length(int cur){
    queue<int> q;
    q.push(cur);
    visited[cur] = 1;
    while (!q.empty()) {
        area++;
        int x = q.front();
        q.pop();
        for(int i = x; i<road_vector.size();i++){
            int next = road_vector[i];
            if(!visited[next] && road_vector[i]==1){
                q.push(next);
                visited[next] = 1;
            }
        }
        
    }

}

void repair_road(int cur, int repair_cnt, int n){
    visited[cur] = 1;
    road_vector[cur] = 1;
    unsigned long size = road_vector.size();
    if(repair_cnt==n){
        // int cnt = 0;
        for(int i = 0;i<size;i++){
            if(road_vector[i]==1){
                find_length(i);
//                cout<<area<<endl;
                // printf("%d\n", area);
            }
             maxValue = max(maxValue, area);
//            maxValue = value;
        }
        road_vector[cur] = 0;
        visited[cur] = 0;
        return;
    }
    
    for(int i = 0;i<size;i++){
        if(!visited[i] && road_vector[i]==0){
            repair_road(i, repair_cnt+1, n);
        }
    }
    visited[cur] = 0;
    road_vector[cur] = 0;
    
}

int solution(string road, int n) {
    int answer = -1;
    
    unsigned long size = road.size();
    for(unsigned long i = 0;i<size;i++){
        road_vector.push_back(road.at(i) -'0');
    }
    
    unsigned long v_size = road_vector.size();
    for(int i = 0;i<v_size;i++){
        if(road_vector[i] == 0){ // 손상
            repair_road(i, 1, n);
        }
    }
    answer = maxValue;
    return answer;
}

int main(int argc, const char * argv[]) {
    string road;
    int n;
    int result = 0;
    for(int i = 0;i<2;i++){
        cin >> road >> n;
        result = solution(road, n);
        
        cout<< result <<endl;

    }
    
    return 0;
}
//111011110011111011111100011111 2
//001100 5
