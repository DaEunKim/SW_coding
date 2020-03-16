//
//  main.cpp
//  9663NQueen
//
//  Created by 김다은 on 2020/03/04.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int N;
//[1][0][0][0]
int result = 0;
int col[15];

bool check(int v){
    for(int i = 0;i<v;i++){
        // 새로운 퀸과 기존의 퀸이 같은 행에 있거나 대각선에 있을 경우
        if(col[i]==col[v] || abs(col[v]-col[i]) == (v-i))
            return false;
    }
    return true;
}

void NQueen(int v){
    if(v==N)
        result += 1;
    else{
        for(int i = 0;i<N;i++){
            col[v] = i;
            if(check(v))
                NQueen(v+1);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> N;
    NQueen(0);
    cout<< result <<endl;
}
