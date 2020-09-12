//
//  main.cpp
//  11404플로이드
//
<<<<<<< HEAD
//  Created by 김다은 on 2020/04/13.
=======
//  Created by 김다은 on 12/04/2020.
>>>>>>> 050807bcffc52824e07caf6a7d4a7825735bb2cc
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
<<<<<<< HEAD
#include <algorithm>
using namespace std;

#define INF 987654321

int vertex, edge;
int arr[101][101];
int from, to, weight;

void floyd_warshall() {
    for (int i = 1; i <= vertex; i++) {            // i vertex를 거치는 경우
        for (int j = 1; j <= vertex; j++) {        // from vertex
            for (int k = 1; k <= vertex; k++) {    // to vertex
                if (arr[j][i] != INF && arr[i][k] != INF) {
                    cout<<"("<< j<<","<<k<<") -> (" <<j<<","<<i<<") ("<<i<<","<<k<<")"<<endl;
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> vertex >> edge;
    for (int i = 1; i <= vertex; i++) {        // vectex table 초기화
        for (int j = 1; j <= vertex; j++) {
            arr[i][j] = INF;
        }
    }
    for (int i = 0; i < edge; i++) {    // from vertex에서 to vertex 입력, 가중치 입력
        cin >> from >> to >> weight;
        if (arr[from][to] > weight){ // 갔던 곳은 가중치 작은것으로 추가.
            arr[from][to] = weight;
        }
    }
    for (int i = 1; i <= vertex; i++) {
        for (int j = 1; j <= vertex; j++) {
            if(i==j || arr[i][j]==INF){
                cout<< 0 <<" ";
            }
            else
                cout<< arr[i][j] <<" ";
        }
        cout<<endl;
    }
    floyd_warshall();
    
    for (int i = 1; i <= vertex; i++) {
        for (int j = 1; j <= vertex; j++) {
            if(i==j || arr[i][j]==INF){
                cout<< 0 <<" ";
            }
            else
                cout<< arr[i][j] <<" ";
//            cout << i << " -> " << j << "의 최단 경로 : " << arr[i][j] << endl;
        }
        cout<<endl;
    }
=======
using namespace std;

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    
    int a, b, c; // 시작 도시 a, 도착 도시 b, 비용 c
//    vector<vector<pair<int, int>>> v;
    int arr[101][101] = {0,};
    int vis[101][101] = {0,};
    for(int z = 0; z < m; z++){
        cin >> a >> b >> c;
        if(!vis[a][b]){
            arr[a][b] = c;
            vis[a][b] = 1;
        }
        else{
            arr[b][a] = c;
            vis[b][a] = 1;
        }
//        v[a].push_back(make_pair(b, c));
    }
    cout<<endl;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout<< arr[i][j] <<" ";
        }
        cout<<endl;
    }
//    for(int i = 1;i<=n;i++){
//        for(int j = 1;j<=m;j++){
//            cout<<  v[i][j].second<<" ";
//        }
//        cout<<endl;
//    }
//
>>>>>>> 050807bcffc52824e07caf6a7d4a7825735bb2cc
}
