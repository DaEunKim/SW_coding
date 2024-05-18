//
//  main.cpp
//  1932정수삼각형
//
//  Created by 김다은 on 2021/02/28.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int input;
    
    int arr[501][501] = {0,};
    memset(arr, -1, sizeof(arr));
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i+1;j++){
            cin >> input;
            arr[i][j] = input;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<< arr[i][j] <<" ";
        }
        cout<<endl;
    }

}
