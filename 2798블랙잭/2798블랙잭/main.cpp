//
//  main.cpp
//  2798블랙잭
//
//  Created by 김다은 on 2019/10/15.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M; // 카드 개수, 카드 숫자의 합
int k = 3;
vector<int> v;
int sum = 0;
int ans = 0;

void combination(int start, vector<int> v, int *arr){
    if(v.size() == k){
        for(int i = 0; i < v.size(); i++){
            sum += v[i];
        }
        if(sum<=M)
            ans = max(ans, sum);
        sum = 0;
        
        return;
    }
    for(int i = start+1; i < N; i++){
        v.push_back(arr[i]);
        combination(i, v, arr);
        v.pop_back();
    }
    return;
}


int main(int argc, const char * argv[]) {
    cin >> N >> M;
    int cardNum[300000];
    vector<int> v;
    for(int i = 0;i<N;i++){
        cin >> cardNum[i];
    }
    combination(-1, v, cardNum);
    cout<< ans <<endl;
}
