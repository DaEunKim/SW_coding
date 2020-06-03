//
//  main.cpp
//  1316그룹단어체커
//
//  Created by 김다은 on 2020/06/03.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    string s[101];
    for(int i = 0;i<N;i++){
        cin >> s[i];
    }
    
    int cnt = 0;
//    equalChar에 연속되는 char 넣고, 그 안에 중복된 char 잇으면 false
    
    for(int i = 0;i<N;i++){
        long long size = s[i].size();
        
        vector<char> equalChar;
        for(int j = 0;j<size;j++){
            if(j+1 >= size){
                break;
            }
            if(s[i].at(j) != s[i].at(j+1)){
                equalChar.push_back(s[i].at(j));
            }
        }
        equalChar.push_back(s[i].at(size-1));
        
        long long equalcharSize = equalChar.size();
        bool flag = true;
        for(int j = 0;j<equalcharSize;j++){
            for(int z = 0;z<equalcharSize;z++){
                if(j!=z){
                    if(equalChar[j] == equalChar[z]){
                        flag = false;
                        break;
                    }
                }

            }
        }
        if(flag==true){
            cnt++;
        }

    }
    cout<<cnt<<endl;
    
}
