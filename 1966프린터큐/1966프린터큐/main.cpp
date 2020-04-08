//
//  main.cpp
//  1966프린터큐
//
//  Created by 김다은 on 2020/04/06.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    int test_case;
    cin >> test_case;
    for(int z = 0;z<test_case;z++){
        int N, M;
        cin >> N >> M; // 문서 갯수, 위치 // 이 위치에 있던 값이 몇 번째에 출력되는지
        
        int critical[101] = {0,}; // 중요도
        queue<pair<int, int>> q;
        priority_queue<int> pq; // 우선 순위에 따라 출력되는 것을 확인하는 용도
        
        for(int i = 0;i<N;i++){
            cin >> critical[i];
            q.push(make_pair(i, critical[i])); // 0, 1/ 1, 2/ 2, 3/ 3, 4
            pq.push(critical[i]); // 4 3 2 1
        }
        
        int cnt = 0;
        while (!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            if(pq.top() == value){ // 1. 출력 값과 기존 값을 비교
                pq.pop();
                cnt++; // pq의 순서를 계산 (출력되는 순서) & 기존 값의 출력 순서
                if(index == M){ // 2. 기존 인덱스 (위치) 값이 찾으려는 위치와 같으면 찾은 것!
                    cout<< cnt<<endl;
                    break;
                }
            }
            else{
                q.push(make_pair(index, value));
            }
        }
        
    }
    
}
