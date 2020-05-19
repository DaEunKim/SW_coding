//
//  main.cpp
//  2795사업확장
//
//  Created by 김다은 on 2020/05/10.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int N, M;
int arr[201][201] = {0,};
int guard[201] = {0,};

int cnt = 0;

void floydWarshall(){ // 뉴욕에서 출발해서 LA를 방문했다가 다시 뉴욕으로 돌아온다. 뉴욕은 1, LA는 2
    int d[1002][1002];
    
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            d[i][j] = arr[i][j];
        }
    }
    for(int z = 1; z <= N; z++){ // 중간 인덱스
        for(int i = 1; i <= N; i++){ // 시작
            for(int j = 1; j <= N; j++){ // 끝
                if (d[i][z] + d[z][j] < d[i][j]) {
                    if(i==1 || z==2){
                        
                        guard[j]++;
                    }
                    if(j==1 || z==2){
//                        cout<<i <<" "<<j <<" "<<d[i][z] + d[z][j]<<endl;
                        guard[i]++;
                    }
                    d[i][j] = d[i][z] + d[z][j];
                }
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    cin >> N >>M;
    
    
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            if(i!=j)
                arr[i][j] = 54321;
        }
    }
    for(int i = 0;i<M;i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    floydWarshall();
    guard[1] = 1;
    for(int i = 1;i<=N;i++){
        if(guard[i]!=0)
            cnt++;
//        cout<<guard[i] <<" ";
    }
//    cout<<endl;
    cout<< cnt<<endl;
}
