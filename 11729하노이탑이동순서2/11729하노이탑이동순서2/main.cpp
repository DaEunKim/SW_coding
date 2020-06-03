//
//  main.cpp
//  11729하노이탑이동순서2
//
//  Created by 김다은 on 2020/05/28.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;


//이동 횟수는
//하노이탑은 원판의 크기가 1칸 증가하게 되면
//현재 원판 * 2 + 1의 규칙


int main(int argc, const char * argv[]) {
    int N; // 원판의 개수
    cin >> N;
    
    int K; // 옮긴 횟수
    stack<int> s1;
    for(int i = 0;i<N;i++){
        s1.push(N-i);
    }
    
    stack<int> s2, s3;
    
//    top끼리 비교
    
//    비어잇는 스택이 잇으면 없는 스택에 넣는데, 넣는 조건은 탑이 큰거부터 3->2순서대로 (값이 큰애를 3이 비어잇으면 3에 2면 2에 이렇게 3부터)
    
//    스택이 다 차면 top의 크기를 비교해서 가장 작은거를 그다음 작은거 잇는 스택에 push
    
    //
    
//    스택에 1개이상 들어있으면 비어잇는 스택에 push , 비어잇는곳 없으면 원판값이 작은애를 그다음 작은애잇는 스택으로 push
//    많이 들어있는 스택꺼를 없는쪽으로
//    스택이 비어있는 곳이 없으면
//    스택의 top의 원판값을 비교해서 큰애를 스택3으로 옮기고
//    원판값이 큰데 이미 스택3이면 다시 작은애를 아무것도 없는 스택으로 옮기는거
//    스택3에 들어있는 애보다 1개작은 원판이 top에 있으면 3으로 이동
//    cout<< K<<endl;
//    A번째 탑의 가장 위에 있는 원판을 B번째 탑의 가장 위로 옮긴다는 뜻
    

}
//세 개의 장대가 있고 첫 번째 장대에는 반경이 서로 다른 n개의 원판이 쌓여 있다. 각 원판은 반경이 큰 순서대로 쌓여있다. 이제 수도승들이 다음 규칙에 따라 첫 번째 장대에서 세 번째 장대로 옮기려 한다.
//
//한 번에 한 개의 원판만을 다른 탑으로 옮길 수 있다.
//쌓아 놓은 원판은 항상 위의 것이 아래의 것보다 작아야 한다.
//이 작업을 수행하는데 필요한 이동 순서를 출력하는 프로그램을 작성하라. 단, 이동 횟수는 최소가 되어야 한다.
//
//아래 그림은 원판이 5개인 경우의 예시이다.
//
//
//
//입력
//첫째 줄에 첫 번째 장대에 쌓인 원판의 개수 N (1 ≤ N ≤ 20)이 주어진다.
//
//
//
//출력
//첫째 줄에 옮긴 횟수 K를 출력한다.
//
//두 번째 줄부터 수행 과정을 출력한다. 두 번째 줄부터 K개의 줄에 걸쳐 두 정수 A B를 빈칸을 사이에 두고 출력하는데, 이는 A번째 탑의 가장 위에 있는 원판을 B번째 탑의 가장 위로 옮긴다는 뜻이다.

//3



//7
//1 3
//1 2
//3 2
//1 3
//2 1
//2 3
//1 3
