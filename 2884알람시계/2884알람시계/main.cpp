//
//  main.cpp
//  2884알람시계
//
//  Created by 김다은 on 18/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int H, M;
    cin >> H >> M;
    
    int ans_H, ans_M;
    
    if(M < 45){
        
        ans_H = H-1;
        ans_M = M+60-45;
    }
    else {
        ans_H = H;
        ans_M = M-45;
    }
    if(ans_H <= 0){
        ans_H = 24 + ans_H;
    }
    
    cout<< ans_H << " "<< ans_M<<endl;
}
