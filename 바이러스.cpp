#include <bits/stdc++.h>
using namespace std;

bool visited[101];
vector<int> graph[101];
int ans = 0;


void DFS(int x){
    ans++;
    for(int dest: graph[x]){
        if(!visited[dest]){
            visited[dest] = true;
            DFS(dest);
        }
    }
}

void BFS(int x){
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int t = q.front();
        ans++;
        q.pop();
        for(int dest:graph[t]){
            if(!visited[dest]){
                visited[dest]=true;
                q.push(dest);
            }
        }
    }
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    visited[1]= true;
    //DFS(1);
    BFS(1);
    
    cout << ans-1;
}