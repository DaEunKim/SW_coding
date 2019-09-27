//
//  main.cpp
//  2605줄세우기
//
//  Created by 김다은 on 20/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    int arr[101] = {0,};
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    list<int> lt;
    lt.push_back(1);
    
    if(arr[1]==0){
        lt.push_back(2);
    }
    else{
        lt.push_front(2);
        
    }
    list< int >::iterator pos = lt.end();
    for(int i = 2;i<n;i++){
        for(int j = 0;j<arr[i];j++){
            pos--;
        }
        lt.insert(pos ,1, i+1);
        pos = lt.end();
    }
    list<int>::iterator iter;
    for (iter = lt.begin(); iter != lt.end(); ++iter){
        cout << *iter << ' ';
    }
    cout << endl;
}
