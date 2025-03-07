#include <bits/stdc++.h>
using namespace std;

long long graph[101][101]; // adj matrix

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int s,e;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            graph[i][j] = 2e9;
        }
    }
    for(int i=0;i<m;i++){
        cin>>s>>e;
        graph[s][e]=1;
        graph[e][s]=1;
    }   

    // Floyd Warshall

    for(int m=1;m<=n;m++){
        for(s=1;s<=n;s++){
            for(e=1;e<=n;e++){
                if(graph[s][e] > graph[s][m]+graph[m][e]){
                    graph[s][e] = graph[s][m]+graph[m][e];
                }
            }
        }
    }
    long long minival = 2e9;
    int miniwho = -1;

    for(int i=1;i<=n;i++){
        long long numsum = 0;
        for(int j=1;j<=n;j++){
            if(i!=j){
                numsum+=graph[i][j];
            }
        }
        if(numsum < minival){
            minival=numsum;
            miniwho = i;
        }
    }

    cout << miniwho;
}