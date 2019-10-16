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
vector<int> v;
int sum = 0;

int calc(vector<int> v){
    int sum = 0;
    for(int i = 0;i<3;i++){
        
        sum += v[i];
    }
    return sum;
}

void combination(int cardNum[], int arr[], int index, int n, int r, int target) {
    if (r == 0) {
        for(int i = 0;i<index;i++){
            v.push_back(cardNum[arr[i]]);
        }
        if(sum<M){
            while(next_permutation(v.begin(), v.end()) ){
                sum = max(sum, calc(v));
            }
            
        }
    }
    else if (target == n)
        return;
    else {
        arr[index] = target;
        combination(cardNum, arr, index + 1, n, r - 1, target + 1);
        combination(cardNum, arr, index, n, r, target + 1);
    }
}


int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    int cardNum[300000];
    
    for(int i = 0;i<N;i++){
        cin >> cardNum[i];
    }
    
    int arr[300000] = {0,};
    combination(cardNum, arr, 0, N, 3, 0);

    cout<< sum <<endl;
    
}
