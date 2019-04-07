//
//  main.cpp
//  2606바이러스
//
//  Created by 김다은 on 07/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int computer_num, computer_conn;
    cin >> computer_num >> computer_conn;
    
    int arr[101][101];
    
    for(int i = 1;i<=computer_num;i++){
        for(int j = 1;j<=computer_num;j++){
            if(i!=j)
                arr[i][j] = 987654321;
        }
    }
    
    for(int i = 0 ;i<computer_conn;i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }
    
    for(int k = 1;k<=computer_num;k++){
        for(int i = 1;i<=computer_num;i++){
            for(int j = 1; j<=computer_num; j++){
                if(arr[i][j] > arr[i][k]+arr[k][j]){
                    arr[i][j] = arr[i][k]+arr[k][j];
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 1;i<=computer_num;i++){
        if(arr[1][i]<987654321){
            cnt++;
        }
    }
    cout<< cnt-1<<endl;
    
    return 0;
}
