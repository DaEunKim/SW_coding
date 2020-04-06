//
//  main.cpp
//  7785회사에있는사람
//
//  Created by 김다은 on 2020/03/16.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); // 시간 줄여줌
    int n;
    cin >> n; // 범위 : 2 ≤ n ≤ 10^6
    string name;
    string status;
    set<string> s;
    
    for(int i = 0;i<n;i++){
        cin >> name >> status;
        if(status =="enter"){
            s.insert(name);
        }
        else{
            s.erase(name);
        }
        
    }

    for(auto i = s.rbegin(); i!=s.rend(); i++){
        cout<< *i <<"\n"; // endl;은 시간이 오래걸림.
    }
}
