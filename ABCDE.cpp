#include <bits/stdc++.h>
using namespace std;

int n,m;
bool ans = false;

bool visited[2001];
vector<int> graph[2001];

void DFS(int node, int len){
    visited[node]=true;
    if(len == 4){
        ans = true;
        return;
    }

    for(int dest : graph[node]){
        if(!visited[dest]){
            DFS(dest, len+1);
        }
    }
    visited[node]=false; // backtracking
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    cin>>n>>m;int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    for(int i=0;i<n;i++){
        if(!ans){
            DFS(i, 0);
        }else break;
    }
    
    cout << (ans ? 1 : 0);
    
}