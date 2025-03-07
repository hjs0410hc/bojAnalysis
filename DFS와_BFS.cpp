#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
bool visitedDFS[1001];
bool visitedBFS[1001]; // i don't want to use memset for now.

void dfs(int node){
    visitedDFS[node]=true;
    cout << node << " ";
    for(int dest : graph[node]){
        if(!visitedDFS[dest]){
            dfs(dest);
        }
    }
}

void bfs(int node){
    queue<int> q;
    q.push(node);
    visitedBFS[node]=true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int dest: graph[cur]){
            if(!visitedBFS[dest]){
                visitedBFS[dest]=true;
                q.push(dest);
            }
        }
    }
}


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,m,v;cin>>n>>m>>v;
    int s,e;
    for(int i=0;i<m;i++){
        cin>>s>>e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    for(int i=1;i<=n;i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout << "\n";
    bfs(v);

    
    
    
}