//
//  main.cpp
//  10872팩토리얼
//
//  Created by 김다은 on 2019/10/14.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    int ans = 1;
    for(int i= 1;i<=N;i++){
        ans *= i;
    }
    cout<< ans<<endl;
}
