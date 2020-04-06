//
//  main.cpp
//  1019책페이지
//
//  Created by 김다은 on 06/04/2020.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

// 1 2 3 4 5 6 7 8 9 10 11
// 0 1 2 3 4 5 6 7 8 9
// 1 4 1 1 1 1 1 1 1 1
int arr[10] = {0,};
void eachNum(int n){
    if(n==0){
        arr[n]++;
        return;
    }
    if( 1 <= n && n <= 9){
        arr[n]++;
        eachNum(n-1);
    }
    else if(n >= 10){
        eachNum(n%10); //11 / 10
        eachNum(n/10);
        eachNum(n-1); // 10
    }
    
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    eachNum(N);
    for(int i = 0;i<10;i++){
        cout<< arr[i] <<" ";
    }
    cout<<endl;
    
}
