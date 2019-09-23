//
//  main.cpp
//  1546평균
//
//  Created by 김다은 on 20/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    double arr[1001] = {0,};
    double maxValue = 0;
    
    for(int i = 0;i<N;i++){
        cin >> arr[i];
        maxValue = max(maxValue, arr[i]);
    }
    
    double newScore[1001];
    double sum = 0;
    for(int i = 0;i<N;i++){
        newScore[i] = arr[i] * 100 / maxValue;
        sum += newScore[i];
    }
    
    double avg;
    avg = sum/N;
    if((int)sum*10000 % N == 0){
        cout<<fixed;
        cout.precision(2);
        cout<< avg <<endl;
    }
    else{
        cout<<fixed;
        cout<< avg <<endl;
    }
}
