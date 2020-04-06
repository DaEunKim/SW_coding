//
//  main.cpp
//  ST_problem1
//
//  Created by 김다은 on 10/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
// 카드게임

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int z = 0;z<T;z++){
        int N;
        int A[101]={0};
        cin >> N;
        for(int i = 0;i<N;i++){
            cin >> A[i];
        }
        
        int M;
        int B[101] ={0};
        cin >> M;
        for(int i =0;i<M;i++){
            cin >> B[i];
        }
        
        //딸기 : 4, 바나나 : 3, 라임 : 2, 자두 : 1
        int cnt_A_4=0, cnt_A_3=0, cnt_A_2=0, cnt_A_1=0;
        for(int i = 0;i<N;i++){
            if(A[i]==4) cnt_A_4++;
            else if(A[i]==3) cnt_A_3++;
            else if(A[i]==2) cnt_A_2++;
            else if(A[i]==1) cnt_A_1++;
        }
        int cnt_B_4=0, cnt_B_3=0, cnt_B_2=0, cnt_B_1=0;
        for(int i = 0;i<M;i++){
            if(B[i]==4) cnt_B_4++;
            else if(B[i]==3) cnt_B_3++;
            else if(B[i]==2) cnt_B_2++;
            else if(B[i]==1) cnt_B_1++;
        }
        
        
        if(cnt_A_4 > cnt_B_4)
            cout<< "A" <<endl;
        else if(cnt_A_4 == cnt_B_4){
            if(cnt_A_3 > cnt_B_3) cout<< "A" <<endl;
            else if(cnt_A_3 == cnt_B_3){
                if(cnt_A_2 > cnt_B_2) cout<< "A" <<endl;
                else if(cnt_A_2 == cnt_B_2){
                    if(cnt_A_1 > cnt_B_1) cout<< "A" <<endl;
                    
                    else if(cnt_A_1 == cnt_B_1) cout<< "D" <<endl;
                    
                    else cout<< "B" <<endl;
                }
                else cout<< "B" <<endl;
            }
            else cout<<"B" <<endl;
        }
        else cout<< "B" <<endl;
        
    }
    return 0;
}
