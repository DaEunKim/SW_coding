//
//  main.cpp
//  kakao2
//
//  Created by 김다은 on 07/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;


string solution(string p) {
    string answer = "";
    stack<char> pCheck;
    stack<char> u, v;
    int length = (int)p.length();
    if(length==1){
        return "";
    }
    
    bool flag = true;

    for (int i = 0; i < length; i++){
        if (p[i] == '('){
            pCheck.push('(');
        }
        
        else if (p[i] == ')'){
            if (!pCheck.empty() && pCheck.top() == '('){
                for(int j = 0;j<i+1;j++){
                    u.push(p[j]);
                }
                pCheck.pop();
                
            }
            else{
                for(int j = 0;j<i+1;j++){
                    v.push(p[j]);
                }
                
                flag = false;
                break;
            }
        }
    }
    cout<<endl;
    if (flag && pCheck.empty()){
        answer = p;
        cout << "yes\n";
    }
    else{
        v.push(')');
        u.pop();
        
        int size = u.size();
        for(int i = 0;i<size;i++){
            answer = u.top();
            u.pop();
        }
        cout << "no\n";
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
//    solution("()))((()");
    cout<< solution(")(")<<endl;
    
    return 0;
}
