//
//  main.cpp
//  1654랜선자르기
//
<<<<<<< HEAD
//  Created by 김다은 on 06/03/2020.
=======
//  Created by 김다은 on 2020/03/09.
>>>>>>> a44af2984420b7dcf3cdd5d89b08701fc040bc54
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
<<<<<<< HEAD
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
=======
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

>>>>>>> a44af2984420b7dcf3cdd5d89b08701fc040bc54
}
