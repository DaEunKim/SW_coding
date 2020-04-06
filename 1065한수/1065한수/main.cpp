//
//  main.cpp
//  1065한수
//
//  Created by 김다은 on 2020/04/06.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

bool hansoo(int num){
    if(num < 100)
        return true;
    
    int inHundred = num / 100;
    int inTen = (num % 100) / 10;
    int inOne = (num % 100) % 10;
    if(inHundred - inTen == inTen - inOne)
        return true;
    return false;
    
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    int cnt = 0;
    for(int i = 1;i<=N;i++){
        if(hansoo(i)){
            cnt++;
        }
    }
    cout<< cnt<<endl;
}
