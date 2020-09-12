//
//  main.cpp
//  1541잃어버린괄호
//
//  Created by 김다은 on 2020/05/12.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    cin >> s;
    unsigned long size = s.size();
    char symbol[50];
    char num[50];
    vector<string> num_list;
    
    for(int i = 0;i<size;i++){
        
        if(s.at(i)=='+' || s.at(i)=='-'){
            symbol[i] = s.at(i);
            num[i] = ' ';
        }
        else{
            num[i] = s.at(i);
        }
    }
//    char *p;
//    p = strtok(num, "\r\n\t");
//    for(int i = 0;i<size;i++){
//        cout<< p[i]<<endl;
//
//    }
    cout<< num[0]<<endl;
    for(int i = 0;i<size;i++){
        
        cout<< num[i];
    }
    cout<<endl;
    for(int i = 0;i<size;i++){
        cout<< symbol[i];
    }
    cout<<endl;

    for(int i = 0;i<size;i++){
        // 연산을 먼저 해보고 그다음에
        // 각 단계에서 최선의 선택을
        if(symbol[i] == '+'){
            
        }
    }
}
//세준이는 양수와 +, -, 그리고 괄호를 가지고 길이가 최대 50인 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.
//
//그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.
//
//괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.
//
//입력
//첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다.
//
//출력
//첫째 줄에 정답을 출력한다.
//

//예제 입력 1
//55-50+40

//-35
