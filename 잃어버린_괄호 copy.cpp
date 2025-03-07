#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    string s;
    stack<int> numbers;
    stack<int> ops;
    bool minus = false;
    cin>>s;
    int temp=0;
    for(char c:s){
        if(c >= '0' && c <= '9'){
            temp *= 10;
            temp += c-'0';
        }else{
            if(temp){
                numbers.push(temp);
                temp=0;
            }
            if(!ops.empty()){
                int op = ops.top();
                ops.pop();
                int first = numbers.top();
                numbers.pop();
                int second = numbers.top();
                numbers.pop();

                int result = second + op*first;

                numbers.push(result);
            }
            if(minus){
                ops.push(-1);
            }else if(c=='-'){
                minus=true;
                ops.push(-1);
            }else{
                ops.push(1);
            }
        }
    }
    
    if(ops.empty()){
        cout << temp;
        return 0;
    }
    int op=ops.top();
    int second = numbers.top();
    int first = temp;

    int result = second + op*first;
    cout << result;
    
    
}