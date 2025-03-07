#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    queue<int> q;

    int n;cin>>n;
    for(int i=1;i<=n;i++){
        q.push(i);
    }

    int last = 0;
    while(!q.empty()){
        last = q.front();
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << last;
    
    
    
}