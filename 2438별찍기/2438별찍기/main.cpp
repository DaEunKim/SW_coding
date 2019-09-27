//
//  main.cpp
//  2438별찍기
//
//  Created by 김다은 on 27/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    for(int i =0; i<N;i++){
        for(int j = 0;j<i+1;j++){
            cout<< "*";
        }
        cout<<endl;
    }
}
