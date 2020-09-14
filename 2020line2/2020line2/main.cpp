//
//  main.cpp
//  2020line2
//
//  Created by 김다은 on 2020/09/13.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> answer;

void save(deque<int> tmp, deque<int> dq){
    if(dq.empty() || tmp.empty())
        return;
    for(auto i = tmp.begin();i!=tmp.end();i++){
        if(dq.empty() || tmp.empty())
            break;
        if(dq.front() == tmp.front()){
            answer.push_back(dq.front());
            tmp.pop_front();
            dq.pop_front();
            
        }
        if(dq.front() == tmp.back()){
            answer.push_back(dq.front());
            tmp.pop_back();
            dq.pop_front();
        }
        if(dq.back() == tmp.back()){
            answer.push_back(dq.back());
            tmp.pop_back();
            dq.pop_back();
        }
        if(dq.back() == tmp.front()){
            answer.push_back(dq.back());
            tmp.pop_front();
            dq.pop_back();
        }
    }
    
}
int main(int argc, const char * argv[]) {
    vector<int> ball;
    vector<int> order;
    ball.push_back(11);
    ball.push_back(2);
    ball.push_back(9);
    ball.push_back(13);
    ball.push_back(24);
    order.push_back(9);order.push_back(2);order.push_back(13);order.push_back(24);order.push_back(11);
    
    
    deque<int> dq;
    for(int i = 0;i<ball.size();i++)
        dq.push_back(ball[i]);
//    int tmpVal = -1;
    deque<int> tmp;
    for(int i = 0;i<order.size();i++){
        save(tmp, dq);
        if(dq.front() == order[i]){
            answer.push_back(dq.front());
            dq.pop_front();
        }
        else if(dq.back() == order[i]){
            answer.push_back(dq.back());
            dq.pop_back();
        }
        else{
            tmp.push_back(order[i]);
            
        }
        
    }
    
    
    for(int i = 0;i<answer.size();i++){
        cout<< answer[i]<<" ";
    }
    cout<<endl;
    
    
    
}
