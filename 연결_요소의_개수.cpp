#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void bfs(int node){
    visited[node]=true;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int dest: graph[cur]){
            if(!visited[dest]){
                visited[dest]=true;
                q.push(dest);
            }
        }
    }
}



int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,m;cin>>n>>m;int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int ans = 0;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bfs(i);
            ans++;
        }
    }
    cout << ans;
    
    
}