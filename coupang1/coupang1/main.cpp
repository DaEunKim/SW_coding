//
//  main.cpp
//  coupang1
//
//  Created by 김다은 on 2020/10/09.
//

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    
//    int maxResult = 0;
    vector<pair<int, int>> maxResult;
    int maxValue = 0;
    for(int z = 2;z<10;z++){
        vector<int> result;
        int N = 14;
        while (1) {
            if(N%z!=0)
                result.push_back(N%z);
            if(N/z==0){
                break;
            }
            N = N/z;
        }
        
        int mul = 1;
        for(int i = 0;i<result.size();i++){
            mul *= result[i];
        }
        maxResult.push_back(make_pair(z, mul));
        maxValue = max(maxValue, mul);
        
        while (!result.empty()) {
            result.pop_back();
        }
        
    }
    
   
    int maxIndex = 0;
    for(int i = 0;i<maxResult.size();i++){
        if(maxValue == maxResult[i].second)
            maxIndex = maxResult[i].first;
//        cout<< maxResult[i].first <<" "<<maxResult[i].second <<endl;
    }
    cout <<maxIndex<<" "<<maxValue<<endl;
}
