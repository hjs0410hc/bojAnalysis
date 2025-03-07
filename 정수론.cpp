#include <bits/stdc++.h>
#define NUMBERS 5'000'000
using namespace std;

bool isPrime[NUMBERS];


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);

 
    // 에라스토테네스의 체
    isPrime[1]=true;
    isPrime[2]=false;
    for(int i=2;i<=sqrt(NUMBERS);i++){
        for(int j=i+i; j < NUMBERS; j+=i){
            isPrime[j]=true;
        }
    }

    cout << boolalpha << isPrime[5];
    
    
}