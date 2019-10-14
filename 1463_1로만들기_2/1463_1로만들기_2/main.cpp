//
//  main.cpp
//  1463_1로만들기_2
//
//  Created by 김다은 on 2019/10/08.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;


void findNumber_1(int N, int cnt){
    if(N==1){
        return;
    }
    if(N%3==0){
        findNumber_1(N/3, ++cnt);
    }
    if(N%2==0){
        findNumber_1(N/2, ++cnt);
    }
    findNumber_1(N-1, ++cnt);

}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    int count = 0;
    
    while (1) {
        if(N==1){
            break;
        }
        count++;
        if(N % 3 == 0){
            N = N/3;
        }
        else if(N % 2 == 0){
            N = N/2;
        }
        else{
            N -= 1;
        }
    }
    cout<< count<<endl;
}
