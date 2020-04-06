//
//  main.cpp
//  nh1
//
//  Created by 김다은 on 29/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//


//3
//ant bee dragonfly
//
//Y
//3
//3
//
//4
//ant bee dragonfly ant
//
//N
//4
//3
//
//3
//ant bee ant
//
//Y
//4
//2
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    string bug[1001];
    int cnt[1001]={0,};
    for(int i = 0;i<N;i++){
        cin >> bug[i];
    }
    
    int totalCount = N;
    int typeCount = 0;
    
    string check;
    for(int i = 0;i<N; i++){
        check = bug[i];
        cnt[i]++;
        typeCount++;
        for(int j = i+1;j<N;j++){
            if(check==bug[j]){
                cnt[i]++;
                typeCount--;
            }
        }
        
    }
    
    bool checkCnt = true;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(cnt[i]!=cnt[j]){
                checkCnt = false;
            }
        }
    }
    
    if(checkCnt==true){
        
        cout<< "Y" <<endl;
    }
    else{
        cout<< "N" <<endl;
    }
    cout<< totalCount<<endl;
    cout<< typeCount<<endl;
    return 0;
}
