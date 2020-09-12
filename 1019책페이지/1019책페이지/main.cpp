//
//  main.cpp
//  1019책페이지
//
//  Created by 김다은 on 06/04/2020.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

long long ans[10] = {0,};
void calc(long long n, long long ten){
    while (n>0) {
        ans[n%10]+=ten;
        n /= 10;
    }
}

int main(int argc, const char * argv[]) {
    long long N;
    cin >> N;
    
    long long start = 1;
    long long ten = 1;
    while (start <= N) {
        
        while (start % 10 != 0 && start <= N) {
            calc(start, ten);
            start += 1;
        }
        if(start > N)
            break;
        
        while (N%10 != 9 && start <= N) {
            calc(N, ten);
            N -= 1;
        }
        
        long long cnt = (N/10 - start/10 + 1);
        for(int i = 0;i<10;i++){
            ans[i] += cnt*ten;
        }
        
        start /= 10;
        N /= 10;
        ten *= 10LL;
    }
    for(int i = 0;i<10;i++){
        cout<< ans[i]<<" ";
    }
    cout<<endl;
}
//https://mygumi.tistory.com/180
