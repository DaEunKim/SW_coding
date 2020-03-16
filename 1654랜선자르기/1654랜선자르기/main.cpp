//
//  main.cpp
//  1654랜선자르기
//
//  Created by 김다은 on 2020/03/09.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    long long K, N;
    cin >> K >> N;
    
    long long arr[10001] ={0,};
    long long maxVal = 0;
    for(int i = 0;i<K;i++){
        cin >> arr[i];
        maxVal = max(maxVal, arr[i]);
    }
    long long left = 1;
    long long right = maxVal;
    long long result = 0;
    
    while (left<=right) {
        long long mid = (left + right) / 2;
        long long cnt = 0;
        for(int i = 0;i<K;i++){
            cnt += arr[i] / mid;
        }
        if(cnt >= N){
            left = mid + 1;
            result = mid;
        }
        else if(cnt < N){
            right = mid - 1;
        }
    }
    
    cout<< result <<endl;

}
