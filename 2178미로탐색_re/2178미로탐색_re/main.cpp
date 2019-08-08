//
//  main.cpp
//  2178미로탐색_re
//
//  Created by 김다은 on 28/05/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    
    int arr[101][101] = {0};
    char tmp;
    for(int i = 0;i<N; i++){
        for(int j = 0;j<M;j++){
            cin >> tmp;
            arr[i][j] = tmp -'0';
        }
    }
    
    for(int i = 0;i<N; i++){
        for(int j = 0;j<M;j++){
            cout << arr[i][j] <<" ";
        }
        cout<<endl;
    }
}
