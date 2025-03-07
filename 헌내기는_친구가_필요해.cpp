#include <bits/stdc++.h>
using namespace std;

char mat[601][601];
bool visited[601][601];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,m;string s;int sx,sy;
    pair<int,int> dxdy[4] = {{1,0},{0,1},{-1,0},{0,-1}};
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            mat[i][j] = s[j];
            if(s[j] == 'I'){
                sx=i;
                sy=j;
            }
        }
    }   
    
    int ans = 0;
    queue<pair<int,int>> q;
    visited[sx][sy]=true;
    q.push({sx,sy});
    while(!q.empty()){
        pair<int,int> qt = q.front();
        q.pop();
        if(mat[qt.first][qt.second] == 'P'){
            ans++;
        }
        for(int i=0;i<4;i++){
            int nx= qt.first + dxdy[i].first;
            int ny = qt.second + dxdy[i].second;
            if(nx>=0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && mat[nx][ny]!='X'){
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
    if(ans == 0){
        cout << "TT";
    }else{
        cout << ans;
    }
}