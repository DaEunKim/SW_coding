//
//  main.cpp
//  6549히스토그램에서가장큰직사각형
//
//  Created by 김다은 on 2020/05/15.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int width[100001];

// 세그먼트 트리 형성
void init(vector<int> &tree, int node, int start, int end) {
    if(start == end) tree[node] = start;
    else{
        init(tree, node * 2, start, (start + end) / 2);
        init(tree, node * 2 + 1, (start + end) / 2 + 1, end);
        if(width[tree[node * 2]] <= width[tree[node * 2 + 1]])tree[node] = tree[node * 2];
        else tree[node] = tree[node * 2 + 1];
    }
    return;
}
//start와 end를 좁혀가면서 query를 하는 것이 핵심.
int query(vector<int> &tree, int node, int start, int end, int i, int j) {
    if(i > end || j < start) return -1;
    if(i <= start && end <= j) return tree[node];
    int m1 = query(tree, 2*node, start, (start+end)/2, i, j);
    int m2 = query(tree, 2*node+1, (start+end)/2+1, end, i, j);
    if (m1 == -1) return m2;
    else if (m2 == -1) return m1;
    else {
        if (width[m1] <= width[m2]) return m1;
        else return m2;
    }
}
long long maxValue(vector<int> &tree, int start, int end) {
    int minIdx = query(tree, 1, 0, n-1, start, end);
    long long area = (long long)(end-start+1)*(long long)width[minIdx];
    if (start <= minIdx-1) {
        area = max(area, maxValue(tree, start, minIdx-1));
    }
    if (minIdx+1 <= end) {
        area = max(area, maxValue(tree, minIdx + 1, end));
    }
    return area;
    
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        cin >> n;
        if(n==0)
            break;
        for(int i = 0;i<n;i++){
            cin >> width[i];
        }
        int h = (int)(ceil(log2(n))+1e-9);
        int tree_size = (1 << (h+1));
        vector<int> tree(tree_size);
        
        init(tree, 1, 0, n-1);
        cout<< maxValue(tree, 0, n-1)<<"\n";
    }
}
//7 2 1 4 5 1 3 3
//4 1000 1000 1000 1000
//0
