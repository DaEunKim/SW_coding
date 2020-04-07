//
//  main.cpp
//  1181단어정렬
//
//  Created by 김다은 on 06/03/2020.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool reqRange(string a, string b){
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    else{
        return a < b;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<string> v;
    string s;
    
    for(int i = 0;i<n;i++){
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), reqRange);
    v.erase(unique(v.begin(), v.end()), v.end()); // set 컨테이너도 중복제거해줌. set으로 하려면 길이에 따른 정렬은 직접 해줘야함 (sort 함수 사용 불가, set에서 insert하면 알아서 정렬해주기 때문. 정렬조건 변경 불가)

    for(auto i = v.begin(); i!=v.end(); i++){
        cout<< *i <<endl;
    }
}
