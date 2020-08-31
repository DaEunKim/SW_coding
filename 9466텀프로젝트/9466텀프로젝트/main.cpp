//
//  main.cpp
//  9466텀프로젝트
//
//  Created by 김다은 on 2020/08/19.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100001
int n;
int cnt;
int arr[MAX];
bool visit[MAX], check[MAX];

void DFS(int index) {
    int next_num = arr[index];
    visit[index] = true;

    if (!visit[next_num])
        DFS(next_num);
    else {
//        만약 1 → 2 → 3 → 1 의 사이클이 형성되었다면, 1 부터 반복문을 돌린다 (index: 3, next_num: 1)
//        사이클의 마지막 노드 전까지 반복하며 cnt++ 을 수행한다
//        마지막 노드를 포함하면 곧바로 종료 되기 때문에 마지막에 cnt에 +1 을 수행해준다
        if (!check[next_num]) {
            for (int i = next_num; i != index; i = arr[i])
                cnt++;
            cnt++;
        }
    }
    
    check[index] = true;
}


int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    
    for(int z = 0;z<T;z++){
        cin >> n;
        cnt = 0;

        memset(arr, 0, sizeof(arr));
        memset(visit, false, sizeof(visit));
        memset(check, false, sizeof(check));
        for(int i = 1;i<=n;i++){
            cin >> arr[i];

        }

        for (int i = 1; i <= n; i++)
            if (!visit[i])
                DFS(i);
        cout << n- cnt << endl;

    }
    
}
