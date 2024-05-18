//
//  main.cpp
//  단어변환
//
//  Created by 김다은 on 2021/04/22.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<pair<string, int>> q;
int vis[51] = {0,};
int number = 0;
bool sameValue = false;

void bfs(string begin, vector<string> words, string target, int minNumber){
    q.push(make_pair(begin, minNumber));
    while(!q.empty()){
        begin = q.front().first;
        minNumber = q.front().second;
        q.pop();
        
        for(int i = 0;i<words.size();i++){
            int cnt = 0;
            for(int j = 0;j<words[i].size();j++){
                if(!vis[i] && begin[j] != words[i][j]){
                    cnt++;
                }
            }
            if(cnt == 1){
                // cout<< words[i]<<endl;
                // cout<< minNumber<<endl;
                minNumber++;
                vis[i] = 1;
                q.push(make_pair(words[i], minNumber));
                
                if(words[i]==target){
                    sameValue = true;
                    number = q.front().second;
                }
            }
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bfs(begin, words, target, 0);
    if(sameValue){
        answer = number;
    }
    else{
        answer = 0;
    }
    
    return answer;
}
int main(int argc, const char * argv[]) {
    string begin = "hit";
    string target = "cog";
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout<< solution(begin, target, words) <<endl;
}
