#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;cin>>n;   int x;
    for(int i=0;i<n;i++){
        cin>>x;
        pq.push(x);
    }
    long long ans = 0;
    while(pq.size() > 1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first+second);
        ans+=first+second;
    }

    cout << ans;

    
    
}