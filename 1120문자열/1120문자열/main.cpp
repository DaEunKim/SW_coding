//
//  main.cpp
//  1120문자열
//
//  Created by 김다은 on 2020/05/25.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int minVal = 999;
void compare(string shortString, string longString){
    char shortArr[51];
    char longArr[51];
    int shortSize = (int)shortString.size();
    int longSize = (int)longString.size();
    for(int i = 0;i<shortSize;i++){
        shortArr[i] = shortString.at(i);
    }
    for(int i = 0;i<longSize;i++){
        longArr[i] = longString.at(i);
    }
    
    int gap = longSize - shortSize + 1;
    for(int i = 0;i<gap;i++){
        int cnt = 0;
        for(int j = 0;j<shortSize; j++){
            if(shortArr[j] != longArr[j+i]){
                cnt++;
            }
        }
        minVal = min(cnt, minVal);
    }
}

void stringSize(string A, string B){
    if(A.size() < B.size()){
        compare(A, B);
    }
    else{
        compare(B, A);
    }
}

int main(int argc, const char * argv[]) {
    string A, B;
    cin >> A >> B;
    stringSize(A, B);
    cout<<minVal<<endl;
}
