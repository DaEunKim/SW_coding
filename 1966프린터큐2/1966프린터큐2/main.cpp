//
//  main.cpp
//  1966프린터큐2
//
//  Created by 김다은 on 2020/08/05.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    int testCase;
    cin >> testCase;
    
    for(int i = 0;i<testCase;i++){
        int N, M;
        cin >> N >> M;
        int arr[101] = {0, };
        
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        while (!q.empty()) {
           q.pop();
       }
       
        for(int j = 0;j<N;j++){
            cin >> arr[j];
            q.push(make_pair(j, arr[j])); //  정렬 안된 배열을 큐에 push
            pq.push(arr[j]);
        }
        
        int cnt = 0;
        while (!q.empty()) {
            int saveIndex = q.front().first;
            int saveValue = q.front().second;
            q.pop();
            if(pq.top() == saveValue){
                pq.pop();
                cnt++;
                if(saveIndex == M){
                    cout<< cnt <<endl;
                    break;
                }
            }
            else{
                q.push(make_pair(saveIndex, saveValue));
                
            }
        }
    }
    
}
