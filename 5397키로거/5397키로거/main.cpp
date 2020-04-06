//
//  main.cpp
//  5397키로거
//
//  Created by 김다은 on 2020/03/16.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        string s;
        cin >> s;
        
        stack<char> left;
        stack<char> right;
        long long size = s.size();
        for(long long j = 0;j<size;j++){
            char checkChar = s.at(j);
            if(checkChar == '<'){
                if(!left.empty()){
                    right.push(left.top());
                    left.pop();
                }
            }
            else if(checkChar == '>'){
                if(!right.empty()){
                    left.push(right.top());
                    right.pop();
                    
                }
            }
            else if(checkChar == '-'){
                if(!left.empty())
                    left.pop();
            }
            else{
                left.push(checkChar);
            }
        }
        
        long long sizeLeft = left.size();
        for(int j = 0;j<sizeLeft;j++){
            right.push(left.top());
            left.pop();
            
        }
        while (!right.empty()) {
            cout<< right.top();
            right.pop();
        }
        cout<<"\n";
        
    }
}
