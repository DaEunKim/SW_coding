//
//  main.cpp
//  SW최적경로(백트래킹)
//
//  Created by 김다은 on 04/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int N =0;
int company_x, company_y;
int home_x, home_y;
int x[101] = {0,};
int y[101] = {0,};

int min_val = 999;
void Backtrack(int permut[]){
    int total_dis = 0;
    
    total_dis += abs(company_x - x[permut[0]]) + abs(company_y - y[permut[0]]);
    for(int i = 1;i<N-2;i++){
        total_dis += abs(x[permut[i]] - x[permut[i+1]]) + abs(y[permut[i]] - y[permut[i+1]]);
//        cout<< total_dis <<" ";
    }
    total_dis += abs(x[permut[N-1]] - home_x) + abs(y[permut[N-1]] - home_y);
//    cout<< total_dis<<" ";
    
    if(min_val > total_dis)
        min_val = total_dis;

}


int data[101]={0};

void init(int data[]){
    for(int i = 0;i<101;i++){
        data[i] = i;
    }
}

int swap(int i,int j){
    int temp;
    if(i==j) return 0;
    temp = data[i];
    data[i]=data[j];
    data[j]=temp;
    return 0;
}


int Permutation(int n, int depth){
    int i;
    int save_data[101]= {0};
    if( n==depth ) {
        for(int i = 0;i<n;i++){
            save_data[i] = data[i];
        }
        Backtrack(save_data);
        return 0;
    }
    
    for(i=depth;i<n;i++){
        swap(i,depth);
        Permutation(n, depth+1);
        swap(i,depth);
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int z = 0;z<T;z++){
        cin >> N;//고객의 수
        //회사의 좌표,집의 좌표, N명의 고객의 좌표
        cin >> company_x >> company_y;
        cin >> home_x >> home_y;

        for(int i  = 0; i<N; i++){
            cin >> x[i]>>y[i];
        }
        
        Permutation(N, 0);
        
        cout<<"#"<<z+1<<" " <<min_val<<endl;
        min_val = 999;
        
    }
    return 0;
}
