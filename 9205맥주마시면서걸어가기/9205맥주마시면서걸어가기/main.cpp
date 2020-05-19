//
//  main.cpp
//  9205맥주마시면서걸어가기
//
//  Created by 김다은 on 20/04/2020.
//  Copyright © 2020 김다은. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    for(int z = 0;z<t;z++){
        int n;
        cin >> n;
        
//        double default_x = 0, default_y = 0;
        double home_x = 0, home_y = 0;
        double store_x = 0, store_y = 0;
        double rock_x = 0, rock_y = 0;
        
//        cin >> default_x >> default_y;
        cin >> home_x >> home_y;
  
        for(int i = 0;i<n;i++){
            
        }
        cin >> store_x >> store_y;
        cin >> rock_x >> rock_y;

        double dist_store = sqrt((home_x - store_x)*(home_x - store_x) + (home_y - store_y)*(home_y - store_y));
        double beer = 20;
        double beer_store = dist_store / 50; // 편의점까지 마신 맥주 갯수
        beer = beer - beer_store;
        if(beer <= 0){
            beer = beer + 20;
        }
        double dist_rock = sqrt((store_x - rock_x)*(store_x - rock_x) + (store_y - rock_y)*(store_y - rock_y));
        double beer_rock = dist_rock / 50; // 락페까지 마신 맥주 갯수
        beer = beer - beer_rock;
        if(beer < 0){
            cout<< "sad"<<endl;
        }
        else{
            cout<<"happy"<<endl;
        }
        
    }
}
