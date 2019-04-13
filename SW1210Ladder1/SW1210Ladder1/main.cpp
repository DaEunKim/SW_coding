//
//  main.cpp
//  SW1210Ladder1
//
//  Created by 김다은 on 13/04/2019.
//  Copyright © 2019 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

#define MAX_Val 100

int main(int argc, const char * argv[]) {
    int T;
    while (1) {
        cin >> T;
        int arr[101][101] = {0};
        for(int i = 0;i<MAX_Val;i++){
            for(int j = 0;j<MAX_Val;j++){
                cin >> arr[i][j];
            }
        }
        
        int x, y=0;
        for(int i = 0;i<MAX_Val;i++){
            for(int j = 0;j<MAX_Val;j++){
                if(arr[i][j]==2){
                    x = i;
                    y = j;
                    
                }
            }
        }
        
        for (int i = MAX_Val-1; i >= 0; i--) {//맨 아래층부터 한칸씩 위로 올라간다
            if (arr[i][y + 1] == 1) {//오른쪽에 길이 있으면 갈 수 있을 떄 까지 오른쪽으로 이동
                while (true) {
                    y++;
                    if (arr[i][y + 1] != 1)
                        break;
                }
            }
            else if (arr[i][y - 1] == 1) {//왼쪽에 길이 있으면 갈 수 있을 떄 까지 왼쪽으로 이동
                while (true) {
                    y--;
                    if (arr[i][y - 1] != 1)
                        break;
                }
            }
        }
        
        cout<<"#"<<T<<" "<<y<<endl;
        
        if(T==10)
            break;
    }
    return 0;
}
