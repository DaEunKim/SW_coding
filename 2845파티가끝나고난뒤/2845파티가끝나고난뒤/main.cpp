//
//  main.cpp
//  2845파티가끝나고난뒤
//
//  Created by 김다은 on 2020/03/24.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int L, P;
    cin >> L >> P; // 1m^2당 사람 수, 파티장 넓이
    int arr[11] = {0,};
    for(int i = 0;i<5;i++){
        cin >> arr[i]; // 기사에 실려 있는 참가자의 수
    }
    
    int realNumPeople = L*P;
    for(int i = 0;i<5;i++){
        cout<< arr[i] - realNumPeople;
        if(i<4){
            cout<<" ";
        }
    }
}
