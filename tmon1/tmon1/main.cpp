//
//  Created by 김다은 on 2020/11/25.
//
// input
// 1 1 5
// 5 3 커트 파마 염색
// 2 2 파마 염색
// 0 2 드라이 클리닉
// 1 2 커트 드라이
// 3 1 염색
//
// output
// 3시간 40분, 98만원
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<< q.front()<<endl;
    q.pop();
    cout<< q.front()<<endl;
    /* 조건 */
//    vector<pair<string, int>> timeOfProc; // 시술 별 조건 (시술명 : 시간(분))
//    timeOfProc.push_back(make_pair("파마", 120));
//    timeOfProc.push_back(make_pair("클리닉", 30));
//    timeOfProc.push_back(make_pair("염색", 60));
//    timeOfProc.push_back(make_pair("드라이", 20));
//    timeOfProc.push_back(make_pair("커트", 40));
//
//    vector<pair<string, int>> hairStateOfProc; // 시술 별 조건 (시술명 : 머릿결 상태 증감)
//    hairStateOfProc.push_back(make_pair("파마", -2));
//    hairStateOfProc.push_back(make_pair("클리닉", 2));
//    hairStateOfProc.push_back(make_pair("염색", -2));
//    hairStateOfProc.push_back(make_pair("드라이", -1));
//    hairStateOfProc.push_back(make_pair("커트", 0));
//
//    vector<pair<string, int>> priceOfProc; // 시술 별 금액 (시술명 : 금액)
//    priceOfProc.push_back(make_pair("파마", 20));
//    priceOfProc.push_back(make_pair("클리닉", 10));
//    priceOfProc.push_back(make_pair("염색", 12));
//    priceOfProc.push_back(make_pair("드라이", 5));
//    priceOfProc.push_back(make_pair("커트", 7));
//
//
//    int N, M, K; //실장님의 수 (1 ≤ N ≤ 5), 디자이너의 수 (1 ≤ M ≤ 5), 손님의 수 (1 ≤ K ≤ 30)
//    cin >> N >> M >> K;
//
//    int hairState = 0; // 머리결
//    int procedureCnt; // 한사람이 받고자 하는 시술 개수
//    vector<string> procedure; // 시술명
//
//    int totalTime = 0;
//    int maxTime = 0;
//    int totalIncome = 0;
//    for(int i = 0;i<K;i++){
//        cin >> hairState;
//        cin >> procedureCnt;
//
//        for (int j = 0; j<procedureCnt; j++) {
//            string s;
//            cin >> s;
//            procedure.push_back(s);
//        }
//
//        // 클리닉은 머리결을 더해주기 때문에 순서과 무관하게 계산
//        for(int j = 0;j<procedureCnt;j++){
//            if(procedure[j]=="클리닉"){
//                procedure.erase(procedure.begin()+j);
//                hairState += 2;
//                totalIncome += 10;
//                break;
//            }
//        }
//        for(int j = 0; j<procedureCnt; j++){
//            for(int z = 0;z<5;z++){
//                if(hairState!=0){
//                    if(procedure[j] == hairStateOfProc[z].first){
//                        hairState += hairStateOfProc[z].second;
//                        totalTime += timeOfProc[z].second;
//                        totalIncome += priceOfProc[z].second;
//                    }
//                }
//                else{
//                    if(procedure[j]=="커트" and procedure[j] == hairStateOfProc[z].first){
//                        hairState += hairStateOfProc[z].second;
//                        totalTime += timeOfProc[z].second;
//                        totalIncome += priceOfProc[z].second;
//                    }
//
//                }
//            }
//
//        }
//        maxTime = max(maxTime, totalTime); // 최대 시간을 총 걸린 시간으로 측정
//        totalTime = 0;
//    }
//
//
//    int hour = maxTime / 60;
//    int min = maxTime % 60;
//
//    if(min==0){
//        cout<< hour<<"시간, "<<totalIncome<<"만원"<<endl;
//    }
//    else{
//        cout<< hour<<"시간 "<< min <<"분, "<<totalIncome<<"만원"<<endl;
//    }
}
