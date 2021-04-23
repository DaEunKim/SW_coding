//
//  main.cpp
//  여행경로
//
//  Created by 김다은 on 2021/04/23.
//

#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool dfs(string target, vector<vector<string>> tickets, int cnt, vector<string>& answer, vector<bool> vis){
    
    answer.push_back(target);
    if(cnt == tickets.size()){
        return true;
    }
    
    for(int j = 0;j<tickets.size();j++){
        
        if(!vis[j] && target == tickets[j][0]){
            vis[j] = 1;
            bool chk = dfs(tickets[j][1], tickets, cnt+1, answer, vis);
            if(chk){
                return true;
            }
            vis[j] = 0;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visit(tickets.size(), false);

    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, 0, answer, visit);
    
    for(int i = 0;i<answer.size();i++){
        cout<< answer[i] <<endl;
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<vector<string>> tickets = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
    
    solution(tickets);
    cout<<endl;
    tickets = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};
    solution(tickets);
    return 0;
}
