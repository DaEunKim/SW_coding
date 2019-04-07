//
//  main.cpp
//  1389캐빈베이컨의6단계법칙
//
//  Created by 김다은 on 07/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int N, M;
    cin >> N >> M;
    
    int arr[101][101] = {0,};
    for(int i = 0;i<=N;i++){
        for(int j = 0;j<=N;j++){
            if(i!=j)
                arr[i][j] = 987654321;
        }
    }
    
    for(int i = 0;i<M;i++){
        int A, B;
        cin >> A >>B;
        arr[A][B] = arr[B][A] = 1;
    }
    
    for(int k=1 ;k<=N;k++){
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=N;j++){
//                arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    
    int min_val = 987654321;
    int save_i = 0;
    for(int i = 1;i<=N;i++){
        int sum = 0;
        for(int j = 1;j<=N;j++){
            sum += arr[i][j];
        }
        if(min_val > sum){
            min_val = sum;
            save_i = i;
        }
    }
    cout<< save_i <<endl;
    return 0;
}
