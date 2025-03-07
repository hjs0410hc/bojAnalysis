#include <bits/stdc++.h>
using namespace std;

int stairs[301];
int dp[301];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>stairs[i];
    }   

    dp[1] = stairs[1];
    dp[2] = stairs[1]+stairs[2];
    for(int i=3;i<=n;i++){
        dp[i] = stairs[i]+ max(dp[i-3]+stairs[i-1], dp[i-2]);
    }

    cout << dp[n];
}