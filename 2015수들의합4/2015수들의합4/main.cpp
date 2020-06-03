//
//  main.cpp
//  2015수들의합4
//
//  Created by 김다은 on 2020/04/10.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long N, K;
vector<int> v;
int flag[10001]={0,};

int cnt = 0;

void powerset(unsigned long long n,int depth){
    if(n==depth){
        int i;
//        printf("{");
        int sum = 0;
        for(i=0;i<n;i++){
            if(!v.empty() && flag[i]==1){
                sum += v[i];
//                printf("%d ",v[i]);
            }
        }
        if(sum == K){
            cnt++;
        }
//        printf("}\n");
        return;
    }
    flag[depth]=1;
    powerset(n,depth+1);
    flag[depth]=0;
    powerset(n,depth+1);
}


int main(int argc, const char * argv[]) {
    
    cin >> N >> K;
    
    
    for(int i = 0;i<N;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
//    sort(v.begin(), v.end());
    powerset(N, 0);
    cout<< cnt<<endl;
    
}
