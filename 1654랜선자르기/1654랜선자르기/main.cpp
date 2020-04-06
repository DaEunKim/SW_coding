//
//  main.cpp
//  1654랜선자르기
//
//  Created by 김다은 on 06/03/2020.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

void binarySearch(int begin, int end, int mid){
    if(begin < mid){
        end = mid;
    }
    else{
        begin = mid;
    }
}

int main(int argc, const char * argv[]) {
    int K, N; // 이미 가지고 있는 랜선의 개수 K, 필요한 랜선의 개수 N
    cin >> K >> N;
    
    int arr[10001] = {0,};
    for(int i = 0;i<K;i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+K, greater<int>());
    for(int i = 0;i<K;i++){
        int mid = arr[i]/2;
        binarySearch(0, arr[i], mid);
    }
//    int saveN = N;
//    int cnt = 0;
//    while (cnt < N) {
//        cnt = arr[0]/saveN;
//        cout<< cnt<<endl;
//        for(int i = 1;i<K;i++){
//            cnt += arr[i]/cnt;
//            if(cnt >= N){
//                --saveN;
//            }
//        }
//    }
//    cout<< cnt<<endl;
}
