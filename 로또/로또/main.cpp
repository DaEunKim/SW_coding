//
//  main.cpp
//  로또
//
//  Created by 김다은 on 2021/07/03.
//

#include <iostream>
#include <time.h>
using namespace std;
int number = 15;
typedef struct node *nodePointer;
typedef struct node{ int data; nodePointer left, right; }
node; // 전위
void preorder(nodePointer pointer){ if(pointer){
    // pointer가 null이 아니라면
    cout << pointer->data << ' '; preorder(pointer->left); preorder(pointer->right);
    
}
    
}
// 중위
void inorder(nodePointer pointer){ if(pointer){
    // pointer가 null이 아니라면
    inorder(pointer->left);
    cout << pointer->data << ' '; inorder(pointer->right); } }

// 후위
void postorder(nodePointer pointer){ if(pointer){
    // pointer가 null이 아니라면
    postorder(pointer->left);
    postorder(pointer->right);
    cout << pointer->data << ' '; } }
int main(void){ node nodes[number+1];
    // 초기화
    for(int i=1; i<= number; i++){ nodes[i].data = i; nodes[i].left = NULL; nodes[i].right = NULL; } for(int i=2; i<=number; i++){ if(i%2==0){ nodes[i/2].left = &nodes[i]; }else{ nodes[i/2].right = &nodes[i]; } } preorder(&nodes[1]); cout << endl; inorder(&nodes[1]); cout << endl; postorder(&nodes[1]); cout << endl; return 0; }


int main(int argc, const char * argv[]) {
    // insert code here...
    int iNum[45] = {};
    for (int i = 0; i < 45; i++) {
        iNum[i] = i + 1;
        
    }
    srand((unsigned int)time(0)); // time seed
    // 인덱스를 랜덤으로 뽑아서 스왑만하므로, 중복된 값은 나오지 않는다.
    // Suffle
    int iTemp, idx1, idx2;

    for (int i = 0; i < 100; i++) {
        idx1 = rand() % 45;
        idx2 = rand() % 45; // swap
        iTemp = iNum[idx1];
        iNum[idx1] = iNum[idx2];
        iNum[idx2] = iTemp;
        
    }
    // 결과 출력
    for (int i = 0; i < 5; i++) {
        cout << (i+1) << "번째 번호 : " << iNum[i] << endl;
        
    }
    cout << "보너스 번호 : " << iNum[5] << endl;


}
