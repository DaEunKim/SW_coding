//
//  main.cpp
//  2588곱셈
//
//  Created by 김다은 on 20/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    string A, B;
    cin >> A >> B;
    int ans1[3] = {0,};
    int ans2[3] = {0,};
    
    for(int i = 0;i<3;i++){
        ans1[i] = A.at(i)-'0';
        ans2[i] = B.at(i)-'0';
    }
    int num1 = ans1[0]*100 + ans1[1]*10 + ans1[2];
    int num3 = num1*ans2[2];
    int num4 = num1*ans2[1];
    int num5 = num1*ans2[0];
   
    cout<< num3 <<endl;
    cout<< num4 <<endl;
    cout<< num5 <<endl;
    
    int num6 = num3 + num4*10 + num5*100;
    cout<< num6<<endl;
}
