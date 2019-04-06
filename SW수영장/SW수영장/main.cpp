//
//  main.cpp
//  SW수영장
//
//  Created by 김다은 on 03/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    
    for(int z = 0;z<T;z++){
        
        int priceList[4] = {0,};
        for(int i = 0;i<4;i++){
            cin >> priceList[i]; //1일 이용권, 1달 이용권, 3달 이용권, 1년 이용권
        }
        //priceList[0] - 1일 이용권, priceList[1] - 1달 이용권, priceList[2] - 3달 이용권, priceList[3] - 1년 이용권
        
        int month[12] = {0,};
        for(int i = 0;i<12;i++){
            cin >> month[i];
        }
        
        
        
        
    }
}
