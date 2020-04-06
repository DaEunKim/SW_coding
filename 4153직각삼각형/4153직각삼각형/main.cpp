//
//  main.cpp
//  4153직각삼각형
//
//  Created by 김다은 on 2020/02/13.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int a, b, c;
    
    while (1) {
        cin >> a >> b>> c;
        
        if(a==0 && b==0 && c==0)
            break;
        
        int longestLine = max(max(a, b), c);
        
        bool checkRightTriangle = true;
        if(longestLine == a){
            if(b*b + c*c == a*a){
                checkRightTriangle = true;
            }
            else{
                checkRightTriangle = false;
            }
        }
        else if(longestLine == b){
            if(a*a + c*c == b*b){
                checkRightTriangle = true;
            }
            else{
                checkRightTriangle = false;
            }
        }
        else if(longestLine == c){
            if(a*a + b*b == c*c){
                checkRightTriangle = true;
            }
            else{
                checkRightTriangle = false;
            }
        }
        
        
        if(checkRightTriangle)
            cout<< "right" <<endl;
        else
            cout<< "wrong" <<endl;
        
    }
}
