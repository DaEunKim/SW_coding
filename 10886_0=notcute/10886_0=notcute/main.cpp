//
//  main.cpp
//  10886_0=notcute
//
//  Created by 김다은 on 2019/11/04.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    int checkCute = 0, cute = 0, notCute = 0;;
    for(int i = 0;i<N;i++){
        cin >> checkCute;
        checkCute == 1 ? cute++ : notCute++;
    }
    cute > notCute ? cout << "Junhee is cute!" <<endl : cout<< "Junhee is not cute!"<<endl;
}
