#include <bits/stdc++.h>
using namespace std;

bool isPrime[1000001];


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);

 
    // 에라스토테네스의 체
    isPrime[1]=true;
    for(int i=2;i<=sqrt(1000000);i++){
        for(int j=i+i; j <= 1000000; j+=i){
            isPrime[j]=true;
        }
    }

    int m,n;cin>>m>>n;

    for(int i=m;i<=n;i++){
        if(!isPrime[i]){
            cout << i << "\n";
        }
    }
    
}