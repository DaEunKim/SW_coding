//
//  main.cpp
//  2979트럭주차
//
//  Created by 김다은 on 12/04/2020.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int a, b, c;
    // 한 대 주차 : 1분에 한 대당 A원
    // 두 대 주차 : 1분에 한 대당 B원
    // 세 대 주차 : 1분에 한 대당 C원
    cin >> a >> b >> c;
    
    int arrive, leave;
    int truck[101] = {0,}; // 주차장에 있는 1분당 트럭수
    for(int z = 0;z<3;z++){
        cin >> arrive >> leave;
        for(int i = arrive;i<leave;i++){
            truck[i] += 1;
        }
    }
    int cost = 0;
    for(int i = 1;i<=100;i++){
        if(truck[i] == 1){
            cost += a;
        }
        else if(truck[i] == 2){
            cost += b*2;
        }
        else if(truck[i] == 3){
            cost += c*3;
        }
    }
    cout<< cost <<endl;
    
}
