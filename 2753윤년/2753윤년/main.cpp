//
//  main.cpp
//  2753윤년
//
//  Created by 김다은 on 18/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    if(N%4==0 && (N%100!=0 || N%400==0))
        cout<< "1"<<endl;
    else
        cout<< "0"<<endl;
}
