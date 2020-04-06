//
//  main.cpp
//  kakao1
//
//  Created by 김다은 on 07/09/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <string>
#include <vector>
using namespace std;
char arr[1001];
int solution(string s) {
    int answer = 0;
    int size = s.size();
    for(int i = 0;i<size;i++){
        arr[i] = s.at(i);
    }
    for(int i = 0;i<size;i++){
        printf("%c\n", arr[i]);
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    solution("aabbaccc");
}
