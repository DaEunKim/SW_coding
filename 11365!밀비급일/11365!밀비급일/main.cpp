//
//  main.cpp
//  11365!밀비급일
//
//  Created by 김다은 on 2019/10/28.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    while (1) {
        string s;
        getline(cin, s);
        if(s=="END"){
            break;
        }
  
        int size = (int)s.size();
        
        char arr[500];
        for(int i = 0;i<size;i++){
            arr[i] = s.at(i);
        }
        
        for(int i = size-1;i>=0;i--){
            cout<< arr[i];
        }
        cout<<endl;
    }
    
}
