//
//  main.cpp
//  1956운동
//
//  Created by 김다은 on 2021/03/19.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, E;
    cin >> V >> E;
    
    int v[401][401] = {0,};
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            v[i][j] = 1e9;
        }
    }//
    for(int i = 0;i<E;i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a][b] = c;
        
    }
    for(int k = 1; k <= V;k++){
        for(int i = 1;i<=V;i++){
            for(int j = 1;j<=V;j++){
                
                if(v[i][j] > v[i][k] + v[k][j]){
                    v[i][j] = v[i][k] + v[k][j];
                }
            }
        }

    }
    int answer = 1e9;
    for(int i = 1;i<=V;i++){
        answer = min(answer, v[i][i]);
//        for(int j = 1;j<=V;j++){
////            answer = min(answer, v[i][i]);
//            cout<< v[i][j]<<" ";
//
//        }
//        cout<<endl;
    }
    if(answer != 1e9){
        cout<< answer<<endl;
    }
    else{
        cout<< "-1"<<endl;
    }

    
}
