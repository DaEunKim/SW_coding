//
//  main.cpp
//  2439별찍기2
//
//  Created by 김다은 on 27/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = n;j>0;j--){
            if(i<j-1)
                cout<<" ";
            else
                cout<< "*";
        }
        cout<<endl;
    }
}
