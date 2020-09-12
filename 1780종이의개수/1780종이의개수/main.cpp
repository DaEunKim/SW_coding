//
//  main.cpp
//  1780종이의개수
//
//  Created by 김다은 on 2020/05/24.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    int arr[1000001][1000001]={0,};
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    
}
