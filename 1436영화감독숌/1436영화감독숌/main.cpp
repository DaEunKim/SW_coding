//
//  main.cpp
//  1436영화감독숌
//
//  Created by 김다은 on 2019/11/05.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    int num = 0;
    int count = 0;
    
    int i = 0;
    while (1) {
        i++;
        num = i;
        bool flag = 0;
        while (num) {
           
            if(num % 1000 == 666){
                
                flag = 1;
            }
            num/=10;
        }
        if(flag){
            count++;
            if(count == N)
                break;
        }
    }
    cout<< i <<endl;
}
