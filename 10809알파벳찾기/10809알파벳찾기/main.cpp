//
//  main.cpp
//  10809알파벳찾기
//
//  Created by 김다은 on 01/10/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    string S;
    cin >> S;
    
    long size = S.size();
    int arr[101];
    for(int i = 0;i<size;i++){
        arr[i] = S.at(i) -'a';
    }
    
    int visited[26] = {0, };
    int check[26] = {0, };
    memset(check, -1, sizeof(check));
    for(int i = 0;i<size;i++){
        for(int j = 0;j<26;j++){
            if(!visited[j] && arr[i] == j){
                check[j] = i;
                
                visited[j] = 1;
            }
        }
    }
    
    for(int i = 0;i<26;i++){
        cout<< check[i] <<" ";
    }
    cout<<endl;
}
