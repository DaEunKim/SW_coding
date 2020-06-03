//
//  main.cpp
//  1238파티
//
//  Created by 김다은 on 2020/05/10.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
<<<<<<< HEAD
=======
#include <algorithm>
>>>>>>> 050807bcffc52824e07caf6a7d4a7825735bb2cc
using namespace std;

int N, M, X;
int arr[1001][1001] = {0, };
int maxTime = 0;
void floydWarshall(){
    int d[1002][1002];
    
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            d[i][j] = arr[i][j];
        }
    }
    
<<<<<<< HEAD
    
=======
>>>>>>> 050807bcffc52824e07caf6a7d4a7825735bb2cc
    for(int z = 1; z <= N; z++){ // 중간 인덱스
        for(int i = 1; i <= N; i++){ // 시작
            for(int j = 1; j <= N; j++){ // 끝
                if (d[i][z] + d[z][j] < d[i][j]) { // 거쳐가는 길이 더 짧으면 그길로 시작과 끝으로 설정
                    d[i][j] = d[i][z] + d[z][j];
                }
            }
        }
    }
    
<<<<<<< HEAD
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            cout<<d[i][j]<<" ";
            maxTime = max(d[i][j], maxTime);
        }
        cout<<endl;
=======
    for(int i = 1;i<=N;i++){ // X번 마을로 갔다가 그들 마을로 돌아와야 한다는 문제의 조건
        maxTime = max(d[i][X] + d[X][i], maxTime);
>>>>>>> 050807bcffc52824e07caf6a7d4a7825735bb2cc
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> N >> M >> X;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            if(i != j){
                arr[i][j] = 7654321;
            }
        }
    }

    for(int i = 0;i<M;i++){
        int x, y, t;
        cin >> x >> y >> t;
        arr[x][y] = t;
    }
    floydWarshall();
    cout<< maxTime<<endl;
}
<<<<<<< HEAD
=======

>>>>>>> 050807bcffc52824e07caf6a7d4a7825735bb2cc
