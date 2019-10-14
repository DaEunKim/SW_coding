//
//  main.cpp
//  2490윷놀이
//
//  Created by 김다은 on 2019/10/14.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    for(int z = 0;z<3;z++){
        int yut[4];
        for(int i = 0;i<4;i++){
            cin >> yut[i];
        }
        
        int cnt = 0;
        for(int i = 0;i<4;i++){
            if(yut[i]==0){
                cnt++;
            }
        }
        if(cnt == 0){
            cout<< "E" <<endl;
        }
        else if(cnt == 1){
            cout<< "A" <<endl;
        }
        else if(cnt == 2){
            cout<< "B" <<endl;
        }
        else if(cnt == 3){
            cout<< "C" <<endl;
        }
        else if(cnt == 4){
            cout<< "D" <<endl;
        }
    }

}
