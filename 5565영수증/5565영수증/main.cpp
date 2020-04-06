//
//  main.cpp
//  5565영수증
//
//  Created by 김다은 on 2019/10/28.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int totalPrice = 0;
    int price[9] = {0,};
    
    cin >> totalPrice;
    for(int i = 0;i<9;i++){
        cin >> price[i];
    }
    int sum = 0;
    for(int i = 0;i<9;i++){
        sum += price[i];
    }
    
    cout<< totalPrice - sum <<endl;
}
