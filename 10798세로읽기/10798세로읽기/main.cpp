//
//  main.cpp
//  10798세로읽기
//
//  Created by 김다은 on 2020/06/03.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string s[16];
    char arr[16][16];
    long long maxSize = 0;
    for(int i = 0;i<5;i++){
        cin >> s[i];
        long long size = s[i].size();
        maxSize = max(maxSize, size);
        for(int j = 0;j<size;j++){
            arr[i][j] = s[i].at(j);
        }

    }
    for(int i = 0;i<maxSize;i++){
        for(int j = 0;j<5;j++){
            if(arr[j][i]!=NULL)
                cout<< arr[j][i];
        }
    }
}
