#include <bits/stdc++.h>
using namespace std;

int n; 


bool isPrime(int x){
    for(int i=2;i<=x/2;i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}

void DFS(int num, int len){
    if(len==n){
        cout << num << "\n";
        return;
    }

    for(int i=1;i<10;i+=2){
        int newNum = num*10 + i;
        if(isPrime(newNum)){
            DFS(newNum, len+1);
        }
    }
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    cin>>n; /// 자리수
    
    // 에라토스테네스의 체 사용 불가, 메모리 제한 4MB, 자리수최대 8
    // 1~99999999 약 1억개 100'000'000 == 400MB

    // 2,3,5,7

    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);

    
    
}