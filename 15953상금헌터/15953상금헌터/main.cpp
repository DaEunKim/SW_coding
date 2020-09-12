//
//  main.cpp
//  15953상금헌터
//
//  Created by 김다은 on 2020/08/31.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    
    int firstRanking, secondRanking;
    queue<pair<int, int>> firstPrize;
    queue<pair<int, int>> secondPrize;
    
    for(int i = 0;i<T;i++){
        cin >> firstRanking >> secondRanking;
        
        int rank = 0;
        
        
        int a = 1;
        int b = 1;
        int totalPrize = 0;
        while (!firstPrize.empty()) {
            firstPrize.pop();
        }
        while (!secondPrize.empty()) {
            secondPrize.pop();
        }

        firstPrize.push(make_pair(500, 1));
        firstPrize.push(make_pair(300, 2));
        firstPrize.push(make_pair(200, 3));
        firstPrize.push(make_pair(50, 4));
        firstPrize.push(make_pair(30, 5));
        firstPrize.push(make_pair(10, 6));

        secondPrize.push(make_pair(512, 1));
        secondPrize.push(make_pair(256, 2));
        secondPrize.push(make_pair(128, 4));
        secondPrize.push(make_pair(64, 8));
        secondPrize.push(make_pair(32, 16));

        if(firstRanking <= 21){
            while (!firstPrize.empty()) {
                rank += firstPrize.front().second;
                if(rank >= firstRanking){
                    a = firstPrize.front().first;
                    break;
                }
                firstPrize.pop();
            }
            
        }
        else{
            a = 0;
        }
            
        rank = 0;
        if(secondRanking <= 31){
            while (!secondPrize.empty()) {
                rank += secondPrize.front().second;
                if(rank >= secondRanking){
                    b = secondPrize.front().first;
                    break;
                }
                secondPrize.pop();
            }
        }
        else{
            b = 0;

        }
        if(firstRanking==0){
            a=0;
            
        }
        if(secondRanking==0)
            b=0;
        totalPrize = a+b;
        cout<< totalPrize * 10000 <<endl;

    }
}

//제이지는 자신이 코드 페스티벌에 출전하여 받을 수 있을 상금이 얼마인지 궁금해졌다. 그는 자신이 두 번의 코드 페스티벌 본선 대회에서 얻을 수 있을 총 상금이 얼마인지 알아보기 위해, 상상력을 발휘하여 아래와 같은 가정을 하였다.
//
//제1회 코드 페스티벌 본선에 진출하여 a등(1 ≤ a ≤ 100)등을 하였다. 단, 진출하지 못했다면 a = 0으로 둔다.
//
//제2회 코드 페스티벌 본선에 진출하여 b등(1 ≤ b ≤ 64)등을 할 것이다. 단, 진출하지 못했다면 b = 0으로 둔다.
//
//제이지는 이러한 가정에 따라, 자신이 받을 수 있는 총 상금이 얼마인지를 알고 싶어한다.
//
//입력
//첫 번째 줄에 제이지가 상상력을 발휘하여 가정한 횟수 T(1 ≤ T ≤ 1,000)가 주어진다.
//
//다음 T개 줄에는 한 줄에 하나씩 제이지가 해본 가정에 대한 정보가 주어진다. 각 줄에는 두 개의 음이 아닌 정수 a(0 ≤ a ≤ 100)와 b(0 ≤ b ≤ 64)가 공백 하나를 사이로 두고 주어진다.
//
//출력
//각 가정이 성립할 때 제이지가 받을 상금을 원 단위의 정수로 한 줄에 하나씩 출력한다. 입력이 들어오는 순서대로 출력해야 한다.
//
//예제 입력 1
//6
//8 4
//13 19
//8 10
//18 18
//8 25
//13 16
//예제 출력 1
//1780000
//620000
//1140000
//420000
//820000
//620000
//출처
