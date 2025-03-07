#include <bits/stdc++.h>
using namespace std;

int path[200001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    memset(path, -1, sizeof(path));
    int n,k;cin>>n>>k;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == k)break;

        if(path[2*cur] == -1 && 2*cur >= 0 && 2*cur <= 200000){
            path[2*cur] = cur;
            q.push(2*cur);
        }
        if(path[cur+1] == -1 && cur+1 >= 0 && cur+1 <= 200000){
            path[cur+1]=cur;
            q.push(cur+1);
        }
        if(path[cur-1] == -1 && cur-1 >= 0 && cur-1 <= 200000){
            path[cur-1]=cur;
            q.push(cur-1);
        }
    }
    int cur = k;
    int ans = 0;
    while(cur != n){
        ans++;
        cur = path[cur];
    }
    cout << ans;
    
    
}
