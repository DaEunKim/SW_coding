//
//  main.cpp
//  6549히스토그램에서가장큰직사각형
//
//  Created by 김다은 on 2020/05/15.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int width[100001];
int tree[100001];
int maxSum = 0;
int init(int start, int end, int node){
    if(start == end){
        return tree[node] = width[start];
    }
    int mid = (start+end) / 2;
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
    
}

int sum(int start, int end, int node, int left, int right){ // start 시작 인덱스, end 끝 인덱스, left right 구하고자 하는 고정 범위
    if(left > end || right < start){ // 범위 벗어나는 경우
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    int mid = (start+end) / 2;
    maxSum = max(maxSum, sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right));
    return maxSum;
}


int main(int argc, const char * argv[]) {
    while (1) {
        cin >> n;
        if(n==0)
            break;
        for(int i = 0;i<n;i++){
            cin >> width[i];
        }
        init(0, n-1, 1);
        int total = 0;
//        for(int i = 0;i<n;i++){
            total = max(total, sum(0, n-1, 1, 0, n));
//        }
        cout<< total<<endl;
    }
}
