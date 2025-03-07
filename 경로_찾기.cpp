#include <bits/stdc++.h>
using namespace std;

int n;
int graph[101][101];
bool visited[101][101];

void dfs(int orgnode, int curnode){
    // 중지시키는 방법 ?

    for(int i=0;i<n;i++){
        if(!visited[orgnode][i] && graph[curnode][i]){
            visited[orgnode][i] = true;
            graph[orgnode][i]=1;
            dfs(orgnode, i);
        }
    }
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>> graph[i][j];
        }
    }
    for(int i=0;i<n;i++){
        dfs(i,i);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    
}