//
//  main.cpp
//  4344평균은넘겠지
//
//  Created by 김다은 on 20/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int testCase;
    cin >> testCase;
    for(int z = 0;z<testCase;z++){
        double students;
        cin >> students;

        int score[1001];
        double average;
        double sum = 0;
        for(int i = 0;i<students;i++){
            cin >> score[i];
            sum += score[i];
        }
        
        average = sum/students;
        
        int cnt = 0;
        for(int i = 0;i<students;i++){
            if(score[i]>average){
                cnt++;
            }
        }
        
        double overAverage;
       
        cout << fixed;
        cout.precision(3);
        overAverage = cnt * 100 / students;
        
        cout<< overAverage<<"%"<<endl;

    }
}
