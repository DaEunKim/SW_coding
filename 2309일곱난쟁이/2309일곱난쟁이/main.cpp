//
//  main.cpp
//  2309일곱난쟁이
//
//  Created by 김다은 on 2020/07/02.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    vector<int> v;
    for(int i = 0;i<9;i++){
        cin >> n;
        v.push_back(n);
    }
    vector<int> checker;
    int k = 7;
    for(int i = 0;i<k;i++){
        checker.push_back(1);
    }
    for(unsigned long long i = 0;i<v.size()-k;i++){
        checker.push_back(0);
    }
    
    sort(checker.begin(), checker.end());
    sort(v.begin(), v.end());
    do{
        int sum = 0;

        for(unsigned long long i=0; i<checker.size(); i++){
            if(checker[i]==1){
                sum+=v[i];
            }
        }
        if(sum==100){
            for(unsigned long long i=0; i<checker.size(); i++){
                if(checker[i]==1){
                    cout << v[i] << "\n";
                }
            }
            break;
        }

    }while(next_permutation(v.begin(),v.end()));

}
