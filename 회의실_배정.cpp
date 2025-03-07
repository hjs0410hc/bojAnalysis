#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    vector<pair<int,int>> v;
    int n,x,y;cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        v.push_back({y,x}); // 반대로 넣는다.
    }

    sort(v.begin(),v.end());

    int ans = 0;
    int curtime = -1;

    for(int i=0;i<n;i++){
        if(v[i].second >= curtime){
            curtime = v[i].first;
            ans++;
        }
    }

    cout << ans;
    
    
    
}