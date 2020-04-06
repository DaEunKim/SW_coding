//
//  main.cpp
//  ST_problem3
//
//  Created by 김다은 on 10/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int z = 0;z<T;z++){
        int N;
        cin >> N;
        vector<int> v;
        
        int cnt = 0;
        for(int i = 0;i<N;i++){
            
            int a, b;
            cin >> a >> b;
            
            bool flag = true;
            for(int j = a;j<b;j++){
                if(!v.empty()){
                    for(auto k = v.begin();k!=v.end();k++){
                        if(*k == j){
                            flag = false;
                            break;
                        }
                    }
                }
                v.push_back(j);
                if(flag == true){
//                    cout<< v.back()<<endl;
                    cnt++;
                    
                }
            }

        }
        cout<<cnt<<endl;
    }
    return 0;
}
