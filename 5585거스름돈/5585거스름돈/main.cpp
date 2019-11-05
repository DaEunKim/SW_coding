//
//  main.cpp
//  5585거스름돈
//
//  Created by 김다은 on 2019/11/05.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int money = 0;
    cin >> money;
    money = 1000-money;
    
    int change[6] = {500, 100, 50, 10, 5, 1};
    
    int ans = 0;
    
    int i = 0;
    while (1) {
        ans += money/change[i];
        if(money/change[i] == 0){
            i++;
            continue;
        }
        money = money % change[i];
        if(money == 0)
            break;
        
    }
    cout<< ans <<endl;
}
