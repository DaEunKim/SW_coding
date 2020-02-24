//
//  main.cpp
//  1564팩토리얼5
//
//  Created by 김다은 on 2019/11/05.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    long long N;
    cin >> N;
    
    unsigned long long factorial = 1;
    for(long long i = N; i >=1; i--){
        factorial *= i;
       
    }
    while (factorial%10==0) {
        factorial/=10;
    }
    cout<< factorial<<endl;
    factorial%=100000000;
    string tmp = to_string(factorial);
    long long size = (long long)tmp.size() - 1 ;
    string ans;
    reverse(ans.begin(), ans.end());
    for(long long i = size;i>=0;i--){
       ans.push_back(tmp[i]);
    }
    
    string realAns;
    for(long long i = 0;i<5;i++)
        realAns.push_back(ans[i]);

    reverse(realAns.begin(), realAns.end());
    cout<< realAns<<endl;

}
