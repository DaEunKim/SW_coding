//
//  main.cpp
//  11399ATM
//
//  Created by 김다은 on 2019/10/28.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    vector<int> time_getMoney;
    int tmp = 0;
    for(int i = 0;i<N;i++){
        cin >> tmp;
        time_getMoney.push_back(tmp);
    }
    
    sort(time_getMoney.begin(), time_getMoney.end());
    // 가장 작은것부터 정렬하면 최소값을 얻을 수 있음.
    int ans = 0;
    int count = 0;
    for(int i = 0;i<N;i++){
        count++;
        for(int j = 0;j<count;j++){
            ans += time_getMoney[j];
        }
    }
//    while (next_permutation(time_getMoney.begin(), time_getMoney.end())) {
//        int waitTime = 0;
//        int totalTime = 0;
//        for(int i = 0;i<N;i++){
//            waitTime += time_getMoney[i];
//            totalTime += waitTime;
//        }
//        ans = min(ans, totalTime);
//    }
    cout<< ans <<endl;
    
}
