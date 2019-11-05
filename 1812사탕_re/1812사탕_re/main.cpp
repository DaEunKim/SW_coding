//
//  main.cpp
//  1812사탕_re
//
//  Created by 김다은 on 2019/11/04.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    int arr[999] ={0,};
    int total = 0;
    for(int i =0;i<N;i++){
        cin >> arr[i];
        total += arr[i];
    }
    total /= 2;
    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = 0; j < N; j+=2){
            sum += arr[(i+j)%N];
        }
        cout<< sum - total <<endl;
    }
}
