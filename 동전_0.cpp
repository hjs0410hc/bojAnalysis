#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    priority_queue<int> pq;
    int n,m;cin>>n>>m;int x;
    for(int i=0;i<n;i++){
        cin>>x;
        pq.push(x);
    }   
    int ans = 0;
    while(m>0){
        if(pq.top() > m){
            pq.pop();
        }else{
            ans += m/pq.top();
            m %= pq.top();
        }
    }
    
    cout << ans;
    
    
}