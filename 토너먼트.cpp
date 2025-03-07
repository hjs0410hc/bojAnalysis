#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,a,b;cin>>n>>a>>b;

    int ans =0;
    while(a!=b){
        a = (a+1)/2;
        b = (b+1)/2;
        ans++;
    }

    cout << ans;
    
    
    
}