//
//  main.cpp
//  2020kakao1
//
//  Created by 김다은 on 2020/09/12.
//  Copyright © 2020 김다은. All rights reserved.
// 통과 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    string new_id = "...!@BaT#*..y.abcdefghijklm";
    
    for(int i = 0;i<new_id.size();i++){
        if(new_id.at(i)>='A' && new_id.at(i)<='Z'){
            new_id.at(i) = new_id.at(i) + 32;
        }
    }
    
    string re = " ";
    for(int i = 0;i<new_id.size();i++){
        char c = new_id.at(i);
        if(c=='.' || c=='-' || c=='_' || (c>='a' && c<='z')|| (c>='0' && c<='9')){
            
        }
        else{
            new_id.replace(i, 1, re);
        }
    }
    new_id.erase(std::remove(new_id.begin(), new_id.end(), ' '), new_id.end());

    for(int i = 0;i<new_id.size();i++){
        if(i+1>=new_id.size()){
            break;
        }
        if(new_id.at(i)=='.' && new_id.at(i+1)=='.'){
            new_id.replace(i, 1, re);
        }
    }

    new_id.erase(std::remove(new_id.begin(), new_id.end(), ' '), new_id.end());

    if(new_id.at(0)=='.'){
        new_id.replace(0, 1, re);
    }
    
    if(new_id.at(new_id.size()-1)=='.'){
        new_id.replace(new_id.size()-1, 1, re);
    }
    
    new_id.erase(std::remove(new_id.begin(), new_id.end(), ' '), new_id.end());
    if(new_id.empty()){
        new_id.push_back('a');
    }
    if(new_id.size()>=16){
        new_id.replace(15,new_id.size(),re);
    }
    if(new_id.at(new_id.size()-1)=='.'){
        new_id.replace(new_id.size()-1, 1, re);
    }
    new_id.erase(std::remove(new_id.begin(), new_id.end(), ' '), new_id.end());
    
    while (1) {
        if(new_id.size()>=3)
            break;
        else{
            char lastChar = new_id.at(new_id.size()-1);
            new_id.push_back(lastChar);
        }
    }
    if(new_id.at(new_id.size()-1)=='.'){
        new_id.replace(new_id.size()-1, 1, re);
    }
    new_id.erase(std::remove(new_id.begin(), new_id.end(), ' '), new_id.end());
    
    cout<< new_id<<endl;

}
