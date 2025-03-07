#include <bits/stdc++.h>
using namespace std;

int dp[50001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    dp[1] = 1;
    for(int i=2;i<=50000;i++){
        dp[i] = 2e9;
        for(int k=1;k*k<=i;k++){
            if(dp[i] > dp[i-k*k]){
                dp[i] = dp[i-k*k]+1;
            }
        }
    }
    
    int n;cin>>n;
    cout << dp[n];
    
}