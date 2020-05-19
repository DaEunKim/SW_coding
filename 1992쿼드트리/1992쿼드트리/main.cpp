//
//  main.cpp
//  1992쿼드트리
//
//  Created by 김다은 on 19/04/2020.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[65][65] = {0,};
void divide_and_conquer(int n, int x, int y){
//    cout<<"size = "<<n<<" ("<<x<<","<<y<<")"<<endl;
    int cur = arr[y][x];
//    cout<<"cur = "<<cur<<endl;
    bool flag = true;
    for(int i = y; i < y+n; i++){
        for(int j = x; j < x+n; j++){
            if(cur!= arr[i][j]){
                flag = false;
            }
        }
    }
    
    if(flag){
        cout<< cur;
    }
    else{
        cout<<"(";
        divide_and_conquer(n/2, x, y); // 2분면
        divide_and_conquer(n/2, x + n/2, y); // 1분면
        divide_and_conquer(n/2, x, y + n/2); // 3분면
        divide_and_conquer(n/2, x + n/2, y + n/2); // 4분면
        cout<<")";
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    for(int i = 0;i<n;i++){
        string s;
        cin >> s;
        for(int j = 0;j<n;j++){
            arr[i][j] = s.at(j) - '0';
        }
    }
    
    divide_and_conquer(n, 0, 0);
    
}
