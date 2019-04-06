//
//  main.cpp
//  SW1215회문1
//
//  Created by 김다은 on 05/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

bool Palindrome(int a, int b, char arr[][8], int n){
    int size = n/2;
    for(int i = 0;i<size; i++){
        if(arr[a][b+i]!=arr[a][b+n-1-i])
            return false;
    }
    return true;
}

bool Palindrome2(int a, int b, char arr[][8], int n){
    int size = n/2;
    for(int i = 0;i<size; i++){
        if(arr[a+i][b]!=arr[a+n-1-i][b])
            return false;
    }
    return true;
}


int main(int argc, const char * argv[]) {
    for(int z = 1;z<=10;z++){
        int n;//회문의 길이
        cin >> n;
        char arr[8][8];
        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                cin >> arr[i][j];
            }
        }
        
        int cnt = 0;
        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                if(j+n > 8)
                    continue;
                if(Palindrome(i, j, arr, n)){
                    cnt++;
                }
            }
        }
        for(int i = 0;i<8;i++){
            for(int j = 0;j<8;j++){
                if(i+n > 8)
                    continue;
                
                if(Palindrome2(i, j, arr, n)){
                    cnt++;
                }
            }
        }
        
        cout<< "#"<<z<<" "<<cnt<<endl;
    }
    return 0;
}
