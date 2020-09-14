//
//  main.cpp
//  2020line1
//
//  Created by 김다은 on 2020/09/13.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool compare(int a, int b){
    return a < b;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> boxes;
    vector<int> v;
    v = {1, 2};    boxes.push_back(v);
    v = {2, 1};    boxes.push_back(v);
    v = {3, 3};    boxes.push_back(v);
    v = {4, 5};    boxes.push_back(v);
    v = {5, 6};    boxes.push_back(v);
    v = {7, 8};    boxes.push_back(v);
    for(int i = 0;i<boxes.size();i++){
        cout<< boxes[i].front() <<" "<<boxes[i].back()<<endl;
    }
    cout<<endl;
    sort(boxes[0].begin(), boxes[boxes.size()-1].end(), compare);
    for(int i = 0;i<boxes.size();i++){
        cout<< boxes[i].front() <<" "<<boxes[i].back()<<endl;
    }

    
}
