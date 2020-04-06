//
//  main.cpp
//  5719거의최단경로
//
//  Created by 김다은 on 2020/03/17.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N, M;
    cin >> N >> M; // 장소의 수, 도로의 수
    if(N == 0 && M == 0)
        return 0;
    
    int S, D;
    cin >> S >> D; // 시작점, 도착점
    for(int i = 0;i<M;i++){
        int U[1001] = {0,};
        int V[1001] = {0,};
        int P[1001] = {0,};
        cin >> U[i] >> V[i] >> P[i]; // 도로의 정보 U에서 V로 가는 도로의 길이가 P
        
    }
    
}
