//
//  main.cpp
//  11404플로이드
//
//  Created by 김다은 on 12/04/2020.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
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
}
