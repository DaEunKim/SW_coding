//
//  main.cpp
//  1074Z
//
//  Created by 김다은 on 2020/05/13.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
// N이 주어졌을 때, (r, c)를 몇 번째로 방문하는지 출력하는 프로그램

int N, r, c;
int arr[225][225] = {0,};
int cnt = 0;

void divideConquer(int n, int x, int y){
//    cout<<n<<" "<<x<<" "<<y<<endl;
    //제일 작은 크기, 2 == (1 << 1)
//    arr[x][y] = cnt;

    if(n==2){
        if(x==r && y==c){
            cout<<cnt++<<endl;
            return;
        }
        cnt++;
        if(x==r && y+1==c){
            cout<<cnt++<<endl;
            return;
        }
        cnt++;
        if(x+1==r && y==c){
            cout<<cnt++<<endl;
            return;
        }
        cnt++;
        if(x+1==r && y+1==c){
            cout<<cnt++<<endl;
            return;
        }
        cnt++;
        return;
    }
    divideConquer(n/2, x, y); // 2분면
    divideConquer(n/2, x, y + n/2); // 3분면
    divideConquer(n/2, x + n/2, y); // 1분면
    divideConquer(n/2, x + n/2, y + n/2); // 4분면
}

int main(int argc, const char * argv[]) {
    cin >> N >> r >> c;
    divideConquer(pow(2,N), 0, 0);
//    for(int i = 0;i<N;i++){
//        for(int j = 0;j<N;j++){
//            cout<< arr[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    
}
