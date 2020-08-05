//
//  main.cpp
//  2668숫자고르기2
//
//  Created by 김다은 on 2020/08/04.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<int> ans;
vector<int> v;;
int vis[101] = {0,};
void dfs(int startNode,int currentNode){
    if(vis[currentNode]){
        if(currentNode==startNode) {// 사이클 형성될 때 노드 저장
            ans.push_back(startNode);
        }
    }else{
        vis[currentNode]++;
        dfs(startNode,v[currentNode]);
    }
}

int main(int argc, const char * argv[]) {
    cin >> N;
    v.push_back(0); // 0 번 인덱스 자리의 값을 넣어주기 위해. (1부터 시작하기 때문에 )
    for(int i = 1;i<=N;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp); // 0번에 0값 넣어주면 push back 형식으로 값을 넣어줄 수 있다.
//        아니면 v[i]형식인 operator 형식으로 데이터 넣어줘야함 operator 사용시 벡터 선언할때 필요한 크기만큼 0으로 초기화
    }

    for(int i = 1;i<=N;i++){
        dfs(i, i);
        memset(vis,0, sizeof(vis));
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}
