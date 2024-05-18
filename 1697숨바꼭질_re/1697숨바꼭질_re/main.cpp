//
//  main.cpp
//  1697숨바꼭질_re
//
<<<<<<< HEAD
//  Created by 김다은 on 2021/02/28.
//

#include <iostream>
#include <queue>
using namespace std;

int vis[100001] = {0,};

int bfs(int n, int k){
    int sec = 0;
    queue<int> q;
    q.push(n);
    
    while (1) {
        unsigned long size = q.size();
        for(int i = 0;i<size;i++){
            n = q.front();
            q.pop();
            if(n==k){
                return sec;
            }
            if(n > 0 && !vis[n-1]){
                vis[n-1] = 1;
                q.push(n-1);
            }
            if(n < 100000 && !vis[n+1]){
                vis[n+1] = 1;
                q.push(n+1);
            }
            if(2*n <= 100000 && !vis[2*n]){
                vis[2*n] = 1;
                q.push(2*n);
            }

        }
        sec++;
    }
    
}
int main(int argc, const char * argv[]) {
    int N, K;
    cin >> N >> K;
    
    cout<< bfs(N, K)<<endl;
    
    return 0;
    
}
=======
//  Created by 김다은 on 2021/01/05.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N, K;
    cin >> N >>K;
    
    
}
//수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
//
//수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
//
//입력
//첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.
//
//출력
//수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
//
//예제 입력 1
//5 17
//예제 출력 1
//4
//힌트
//수빈이가 5-10-9-18-17 순으로 가면 4초만에 동생을 찾을 수 있다.
>>>>>>> 2d544aaf8852ad1c6874d9c0f253c339e86c2866
