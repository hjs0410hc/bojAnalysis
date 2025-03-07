#include <bits/stdc++.h>
using namespace std;

bool notPrime[1'000'001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    long long a,b; cin>>a>>b;
    
    notPrime[1]=true;

    int antians = 0;

    // for(int i=2;i<=sqrt(1'000'000);i++){
    //     for(int j=i+i;j<=1'000'000;j+=i){
    //         notPrime[j]=true;
    //     }
    // }

    for(int i=2;i*i<=b;i++){
        long long square = i*i;
        for(long long j=a/square; square*j <= 1e12; j++){
            if (square*j >= a && square*j <= b){
                antians++;
            }
        }
    }
    
    cout << antians;
    
    
    
}