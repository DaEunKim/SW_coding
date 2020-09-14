//
//  main.cpp
//  2020kakao3
//
//  Created by 김다은 on 2020/09/12.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<string> infoArr;
vector<string> queryArr;

void dfs(string s, int cur){
    if(cur==5)
        return;
    
    for(int i = 0;i<infoArr.size();i++){
        if(s==infoArr[i]){
            dfs(infoArr[i], cur+1);
        }
    }
}
int main(int argc, const char * argv[]) {
    vector<string> query;
    query.push_back("java and backend and junior and pizza 100");
    query.push_back("python and frontend and senior and chicken 200");
    query.push_back("cpp and - and senior and pizza 250");
    query.push_back("- and backend and senior and - 150");
    query.push_back("- and - and - and chicken 100");
    query.push_back("- and - and - and - 150");
    
    vector<string> info;
    info.push_back("java backend junior pizza 150");
    info.push_back("python frontend senior chicken 210");
    info.push_back("python frontend senior chicken 150");
    info.push_back("cpp backend senior pizza 260");
    info.push_back("java backend junior chicken 80");
    info.push_back("python backend senior chicken 50");
    
    int cnt = 0;
    for(int i = 0;i<query.size();i++){
        char *queryBuffer = new char[1000000];
        strcpy(queryBuffer, query[i].c_str());
        char *queryTok = strtok(queryBuffer, " ");
        
        while(queryTok != NULL) {
            if(string(queryTok)!="and")
                queryArr.push_back(string(queryTok));
            queryTok = strtok(NULL, " ");
        }
        for(int j = 0;j<info.size();j++){
            char *infoBuffer = new char[1000000];
            strcpy(infoBuffer, info[i].c_str());
            char *infoTok = strtok(infoBuffer, " ");
            while(infoTok != NULL) {
                infoArr.push_back(string(infoTok));
                infoTok = strtok(NULL, " ");
            }
            for(int z  =0;z<queryArr.size();z++){
                for(int k = 0;k<infoArr.size();k++){
                    if(queryArr[z]<=infoArr[k]){
                        cnt++;
                        
                    }
                }
                cout<<cnt<<endl;
                cnt =0;
                
            }
        }
    }
    
}
