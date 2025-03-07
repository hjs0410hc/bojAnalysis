#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int tc;cin>>tc;while(tc--){
        string s1,s2;
        unordered_map<string,int> mp;
        int n;cin>>n;
        for(int i=0;i<n;i++){
            cin>>s1>>s2;
            mp[s2]++;
        }
        int ans=1;
        for(pair<string, int> p:mp){
            ans*=(p.second+1);
        }
        ans--;

        cout << ans << "\n";
    }

    
    
    
}