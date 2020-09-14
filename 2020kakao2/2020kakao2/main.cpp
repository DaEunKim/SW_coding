//
//  main.cpp
//  2020kakao2
//
//  Created by 김다은 on 2020/09/12.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<string> functionVal;
vector<string> answer;
struct WORD{
    string str;
    int count;
};

vector<WORD*> words;

int findWords(const string& s){
    for(int i = 0;i<words.size();i++){
        if(words[i]->str == s)
            return i;
    }
    return -1;
}
void countWords(const string &s){
    int index = findWords(s);
    if(index == -1){
        WORD *pWord = new WORD;
        pWord->str = s;
        pWord->count = 1;
        words.push_back(pWord);
    }
    else{
        words[index]->count++;
    }
}
void showWords(){
    for(int i = 0;i<words.size();i++){
        answer.push_back(words[i]->str);
//        cout<< words[i]->str <<" : "<<words[i]->count <<endl;
    }
}
void removeAll(){
    for(int i = 0;i<words.size();i++){
        delete words[i];
    }
}

void rowComb(string order){
    int vis[26] = {0,};
    for(int i = 0;i<order.size();i++){
        vis[order[i]-'A']++;
    }
    vector<char> tmp;
    for(int i = 0;i<26;i++){
        if(vis[i]>0){
            tmp.push_back(i+'A');
        }
    }
    // 0과1을 저장 할 벡터 생성
    vector<int> ind;
    // 4개를 뽑으니까
    int k = 2;
    // k개의 1 추가
    for(int i=0; i<k; i++){
        ind.push_back(1);
    }
    // 2개(6개-4개)의 0 추가
    for(int i=0; i<tmp.size()-k; i++){
        ind.push_back(0);
    }

    // 정렬
    sort(ind.begin(), ind.end());
    

    string s;
    do{
        for(int i=0; i<ind.size(); i++){
            if(ind[i] == 1){
                s += tmp[i];
            }
        }
        functionVal.push_back(s);
        s = "";
    }while(next_permutation(ind.begin(), ind.end()));
    
}


int main(int argc, const char * argv[]) {
    vector<string> orders;
    vector<int> course;
    course.push_back(2);
    course.push_back(3);
    course.push_back(4);
    
    orders.push_back("ABCFG");
    orders.push_back("AC");
    orders.push_back("CDE");
    orders.push_back("ACDE");
    orders.push_back("BCFG");
    orders.push_back("ACDEH");
    
    
    int vis[26] = {0,};
    for(int i = 0;i<orders.size();i++){
        for(int j = 0;j<orders[i].size();j++){
            vis[orders[i][j]-'A']++;
        }
    }
    vector<char> tmp;
    for(int i = 0;i<26;i++){
        if(vis[i]>0){
            tmp.push_back(i+'A');
        }
    }
    // 0과1을 저장 할 벡터 생성
    vector<int> ind;
    // 4개를 뽑으니까
    int k = 2;
    // k개의 1 추가
    for(int i=0; i<k; i++){
        ind.push_back(1);
    }
    // 2개(6개-4개)의 0 추가
    for(int i=0; i<tmp.size()-k; i++){
        ind.push_back(0);
    }

    // 정렬
    sort(ind.begin(), ind.end());
    vector<string> save;
    string s;
    do{
        for(int i=0; i<ind.size(); i++){
            if(ind[i] == 1){
                s += tmp[i];
            }
        }
        save.push_back(s);
        s = "";
    }while(next_permutation(ind.begin(), ind.end()));



    
    for(int i = 0;i<save.size();i++){
        rowComb(orders[i]);
        string buff = save[i];
        countWords(buff);
        
    }
    showWords();
    removeAll();
    for(int i = 0;i<functionVal.size();i++){
        string buff = functionVal[i];
        countWords(buff);
    }
    showWords();
    removeAll();
    

}
