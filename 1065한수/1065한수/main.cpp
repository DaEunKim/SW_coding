//
//  main.cpp
//  1065한수
//
//  Created by 김다은 on 04/04/2020.
//  Copyright © 2020 김다은. All rights reserved.
//

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main(int argc, const char * argv[]) {
//    int N;
//    cin >> N;
//    vector<vector<int>> v;
//}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> vis;
int visited[300001] = {0,};
int maxValue = 0;
void repair_road(int cur, int repair_cnt, int n){
//    vis[cur] = 1;
    visited[cur] = 1;
    v[cur] = 1; //  0인 자리가 들어왓으니 1로 바꿔놓고
    
    if(repair_cnt==n){
        int cnt = 0;
        unsigned long size = v.size();
        for(unsigned long i = 0;i<size;i++){
            if(v[i]==1){
                cnt++;
            }
        }
        maxValue = max(maxValue, cnt);
        v[cur] = 0;
        visited[cur] = 0;
//        vis[cur] = 0;
        return;
    }
    unsigned long size = v.size();
//    unsigned long vis_size = vis.size();
    for(int i = 0;i<size;i++){
        if(v[i]==0){
            repair_road(i, repair_cnt+1, n);
        }
    }
    v[cur] = 0;
//    vis[cur] = 0;
    
}

int solution(string road, int n) {
    int answer = -1;
    
    unsigned long size = road.size();
    for(unsigned long i = 0;i<size;i++){
        v.push_back(road.at(i) -'0');
    }
    unsigned long v_size = v.size();
    for(int i = 0;i<v_size;i++){
        if(v[i] == 0){ // 손상
            repair_road(i, 1, n);
            // printf("%d ", i);
        }
    }
    answer = maxValue;
    return answer;
}

int main(){
    string road = "111011110011111011111100011111";
    int result = solution(road, 3);
    cout<< result<<endl;
    
}
