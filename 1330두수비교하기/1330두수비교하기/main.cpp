//
//  main.cpp
//  1330두수비교하기
//
//  Created by 김다은 on 18/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int A, B;
    cin >> A >> B;
    if(A>B){
        cout<< ">" <<endl;
        
    }
    else if(A<B){
        cout<< "<" <<endl;
        
    }
    else{
        cout<<"=="<<endl;
    }
}
