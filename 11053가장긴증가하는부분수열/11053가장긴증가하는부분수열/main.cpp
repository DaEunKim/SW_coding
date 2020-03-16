//
//  main.cpp
//  11053가장긴증가하는부분수열
//
//  Created by 김다은 on 2020/02/24.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
//    6
//    10 20 10 30 20 50
    vector<int> v;
    int arr[1001] = {0,};
    for(int i = 0;i<N;i++){
        cin >> arr[i];
        
    }
    v.push_back(arr[0]);
   
    for(int i = 0;i<N;i++){
        auto lower = lower_bound(v.begin(), v.end(), arr[i]); // 주어진 값보다 작지 않은 첫번째 원소값 반환.
        // v에는 첫번째 원소인 10만 들어있고, arr[0]부터 비교 => 반환값 : 10
        // v.end()값과 다르므로 else로
        // arr[1]값은 20이고, v에는 여전히 10만 들어있음. 비교 => 반환값 : 20 (기준이 되는 arr[1]값이 v에 들어있는 값보다 크기 때문에 arr[1]값인 20 반환)
        if(lower == v.end()){
            v.push_back(arr[i]);
        }
        else{
            *lower = arr[i];
        }
    }
    cout<< v.size()<<endl;

}
