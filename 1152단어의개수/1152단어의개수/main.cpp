//
//  main.cpp
//  1152단어의개수
//
//  Created by 김다은 on 2020/08/31.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    getline(cin, s);

    unsigned long long size = s.size();
    int cnt = 1;
    
    
    for(int i = 0;i<size;i++){
        if(s.at(i)==' '){
            cnt++;
        }
    }
    if(s.at(0)==' '){
        cnt--;
    }
    if(s.at(size-1)==' '){
        cnt--;
        
    }
    cout<< cnt<<endl;
    
}
