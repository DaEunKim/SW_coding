//
//  main.cpp
//  4949균형잡힌세상
//
//  Created by 김다은 on 2020/07/29.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    while (1) {
        string s;
        getline(cin, s);
        
        if(s == ".")
            break;
        long long size = s.length();
        
        stack<char> check;
        bool flag = true;
        for(int i = 0;i<size;i++){
            char ch = s.at(i);
            if(ch == '(' || ch =='['){
                check.push(ch);
                flag = false;
            }
            else if(ch == ')'){
                if(!check.empty() && check.top()=='('){
                    flag = true;
                    check.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }
            else if(ch == ']'){
                if(!check.empty() && check.top()=='['){
                    flag = true;
                    check.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(check.empty() && flag){
            cout<< "yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }

        while (!check.empty()) {
            check.pop();
        }
    }
}
