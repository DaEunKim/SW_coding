//
//  main.cpp
//  11729하노이탑이동순서
//
//  Created by 김다은 on 2019/12/05.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

void Hanoi(int n, int from, int by, int to){
    if(n==1)
        printf("%d %d\n", from , to);
    else{
        Hanoi(n-1, from, to, by);
        printf("%d %d\n", from , to);
        Hanoi(n-1, by, from, to);
    }
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    int totalCnt = 0;
    for(int i = 0;i<N;i++){
        totalCnt = totalCnt*2 + 1;
    }
    
    printf("%d\n", totalCnt);

    Hanoi(N, 1, 2, 3);
}
