//
//  main.cpp
//  1431시리얼번호
//
//  Created by 김다은 on 2020/03/02.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int sum(string s){
    int result = 0;
    for (int i = 0; i < s.length(); i++){
        if ((s[i] - '0') >= 1 && (s[i] - '0') <= 9)
            result += (s[i] - '0');
    }
    return result;
}

bool compArr(string a, string b){
    if(a.length()!=b.length()){
        return a.length() < b.length();
    }
    else{
        int aSum = sum(a);
        int bSum = sum(b);
        
        if(aSum != bSum){
            return aSum < bSum;//합이 작은거 먼저
        }
        else{ // 길이도 같고 합도 같은 것 중에 숫자가 먼저(사전순)
            return a < b;
        }
    }
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    string saveArr;
    vector<string> v;
    for(int i = 0;i<N;i++){
        cin >> saveArr;
        v.push_back(saveArr);
    }
    sort(v.begin(), v.end(), compArr);

    for(auto i = v.begin(); i!=v.end();i++){
        cout<< *i <<endl;
    }

}
<<<<<<< HEAD
=======

>>>>>>> a44af2984420b7dcf3cdd5d89b08701fc040bc54
