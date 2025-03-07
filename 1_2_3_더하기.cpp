#include <bits/stdc++.h>
using namespace std;

int dp[12];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    dp[1]=1;
    dp[2]=2; // 1,1 2
    dp[3]=4; // 1,1,1 1,2 2,1 3

    for(int i=4;i<11;i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    int tc;cin>>tc;while(tc--){

        int n;cin>>n;
        cout << dp[n] << "\n";
    }
    
    
}