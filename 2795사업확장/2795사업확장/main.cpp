//
//  main.cpp
//  2795사업확장
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


void dfs(int cur, int checkArr[201][201]){
    int start = cur;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            
        }
    }
}
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
//                if((i==1 || j==2) && (i==2 || j==1)){
//                    guard[z]++;
                    if (d[i][z] + d[z][j] < d[i][j]) {
                        // i, z, j 경우의 수를...?
                        cout<<i <<" "<<z<<endl;
                        cout<<z <<" "<<j<<endl; // <<d[i][z] + d[z][j]<<endl;
                        guard[i]++;
                        guard[z]++;
                        guard[j]++;
                        d[i][j] = d[i][z] + d[z][j];
                    }
//                }
//                if (d[i][z] + d[z][j] < d[i][j]) {
//                    if(i==1 || j==2){
//                        cout<<i <<" "<<j <<" "<<d[i][z] + d[z][j]<<endl;
//
//                    }
//                    if(i==2 || j==1){
//
//                        guard[z]++;
//                    }
//                    d[i][j] = d[i][z] + d[z][j];
//                }
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
    cout<<endl;
    floydWarshall();
//    guard[1] = 1;
    for(int i = 1;i<=N;i++){
        if(guard[i]!=0)
            cnt++;
        cout<<guard[i] <<" ";
    }
    cout<<endl;
    cout<< cnt<<endl;
}
//성공한 벤쳐회사 "봉씨"의 사장 연종이는 사업을 미국으로 확장하기로 결정했다.
//
//봉씨는 LA에 있는 투자자들을 만나기 위해 미국으로 출발했다. 하지만, 비행기를 내리고 보니 그곳은 LA가 아니었다. 연종이의 비서는 아는 미국 도시가 뉴욕밖에 없었기 때문에, 당연히 사장의 항공편을 뉴욕행으로 예약한 것이다.
//
//연종이는 LA까지 가는 비용을 최대한 줄이려고 한다. 따라서, 그는 비행기를 타는 대신에 차를 빌려서 이동할 것이다.
//
//미국에는 N개의 도시가 있고, 각 도시는 1번부터 N번까지 번호가 매겨져 있다. 또, M개의 도로가 있다. 도로는 두 도시를 연결하며, 한 방향으로만 움직일 수 있다.
//
//뉴욕의 도시 번호는 1번이고, LA의 번호는 2번이다.
//
//연종이의 회사는 구글을 넘는 가치를 지니고 있기 때문에, 연종이가 방문하는 도시에 경호원을 고용하려고 한다. 이때, 고용해야하는 경호원의 수를 최소화하는 프로그램을 작성하시오. 어떤 도시에서 경호원을 고용하면, 몇 번을 방문하더라도 재고용하지 않아도 된다. 연종이는 뉴욕에서 출발해서 LA를 방문했다가 다시 뉴욕으로 돌아온다.
//
//입력
//첫째 줄에는 N과 M이 주어진다. (2 ≤ N ≤ 100, 2 ≤ M ≤ 200)
//
//다음 M개의 줄에는 서로 다른 정수 A와 B가 주어진다. (1 ≤ A, B ≤ N) 이 두 숫자는 도로에 대한 정보이고, A에서 B로 가는 도로라는 뜻이다. 같은 도로가 두 번이상 주어지는 경우는 없지만, 반대 방향 도로(B -> A)가 주어질 수는 있다.
//
//출력
//첫째 줄에 뉴욕에서 LA로 갔다가, 다시 뉴욕으로 돌아오는 경로 중 고용해야하는 경호원의 수의 최솟값을 출력한다. 항상 답이 존재하는 경우만 입력으로 주어진다.

//6 7
//1 3
//3 4
//4 5
//5 1
//4 2
//2 6
//6 3
