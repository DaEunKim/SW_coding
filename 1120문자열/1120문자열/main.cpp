//
//  main.cpp
//  1120문자열
//
//  Created by 김다은 on 2020/05/24.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;


deque<int> deque_A;
deque<int> deque_B;


int minVal = 999;
void compare(string A){
    long long size_A = A.size();
    int cnt = 0;
    for(int i = 0;i<size_A;i++){
        if(deque_A[i] != deque_B[i]){
            cnt++;
        }
    }
    minVal = min(cnt, minVal);
}

void search(string A, string B){
    long long size_A = A.size();
    long long size_B = B.size();
    
    if(size_A==size_B){
        compare(A);
   }
   if(size_A<size_B){
       
       deque_A.push_front('a');
       search(A, B);
       deque_A.pop_front();
       
       deque_A.push_back('a');
       search(A, B);
       deque_A.pop_back();
   }
}

int main(int argc, const char * argv[]) {
    string A, B;
    cin >> A >> B;
    long long size_A = A.size();
    long long size_B = B.size();
    for(int i = 0;i<size_A;i++){
        deque_A.push_back(A.at(i));
    }
    for(int i = 0;i<size_B;i++){
        deque_B.push_back(B.at(i));
    }
    search(A, B);
    cout<<minVal<<endl;

}
