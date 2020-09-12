#include <iostream>
#include <stack>
using namespace std;

int main(){
    string input;
    cin >> input;
    long long size = input.length();
    stack<char> left;
    stack<char> right;
    bool flag = true;
    for(int i = 0;i<size;i++){
        char ch = input.at(i);
        if(ch == '1'){
            left.push(ch);
        }
        else if(ch == '2'){
            right.push(ch);

        }
    }
    if(left.size()>=2){
        flag = false;
    }
    if(flag){
        cout<< "true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;

}
