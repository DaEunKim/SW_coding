//
//  main.cpp
//  1924_2007년
//
//  Created by 김다은 on 2019/10/10.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

// 2007년만 고려하면 되기 때문에 윤년 계산이 필요없음.

int main(int argc, const char * argv[]) {
    int month, day;
    cin >> month >> day;
    int monthArr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int countDay = 0;
    for(int i = 0;i<month;i++){
        countDay += monthArr[i];
        
    }
    countDay += day;
    
    int dayOfWeek = countDay % 7;
    string dayOfWeekArr[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    cout<< dayOfWeekArr[dayOfWeek] <<endl;
    
}
