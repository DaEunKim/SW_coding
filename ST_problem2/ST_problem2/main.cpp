//
//  main.cpp
//  ST_problem2
//
//  Created by 김다은 on 10/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
// 피자

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int z = 0;z<T;z++){
        int A, B, C, N; //스몰, 미디움, 라지 사이즈, 미팅에 참가하는 사람의 수
        cin >> A >> B >> C >> N;
        
        int sum = 0;
        bool flag = false;
        for(int i = 0;i<301;i++){
            for(int j = 0;j<301;j++){
                for(int k  = 0;k<301;k++){
                    sum = i*A + j*B + k*C;
                    if(sum == N){
                        flag = true;
                        break;
                    }
                }
            }
        }
        if(flag == true)
            cout<< "1"<<endl;
        else
            cout<< "0" <<endl;
        
    }
    return 0;
}
