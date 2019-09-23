//
//  main.cpp
//  10817세수
//
//  Created by 김다은 on 18/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int arr[3];
    for(int i = 0;i<3;i++){
        cin >> arr[i];
    }
    sort(arr, arr + 3);
   
    cout<<arr[1]<<endl;
}
