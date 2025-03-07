#include <bits/stdc++.h>
using namespace std;

int arr[101];
int path[101];
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    int x;
    for(int i=0;i<n;i++){
        cin>>x>>arr[x];
    }

    for(int i=0;i<m;i++){
        cin>>x>>arr[x];
    }

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == 100){
            break;
        }
        for(int i=1;i<=6;i++){
            int nextmove = arr[cur+i] > 0 ? arr[cur+i] : cur+i;
            if(nextmove <= 100 && !path[nextmove]){
                path[nextmove] = cur;
                q.push(nextmove);
            }
        }
    }
    int cur = 100;
    int ans =0;
    while(cur != 1){
        cur = path[cur];
        ans++;
    }
    cout << ans;
}