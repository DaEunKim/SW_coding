//
//  main.cpp
//  8958OX퀴즈
//
//  Created by 김다은 on 2019/10/14.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int testCase;
    cin >> testCase;
    string s;
    for(int z = 0;z<testCase;z++){
        cin >> s;
        int size = (int)s.size();
        
        char arr[81];
        for(int i = 0;i<size;i++){
            arr[i] = s.at(i);
        }
        
        int score = 0;
        int cnt = 0;
        for(int i = 0;i<size;i++){
            if(arr[i]=='O'){
                ++cnt;
                score = score + cnt;
            }
            else{
                cnt = 0;
            }
            
        }
        cout<< score <<endl;
    }
}
