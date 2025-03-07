#include <bits/stdc++.h>
using namespace std;


int mat[101][101];
pair<int,int> path[101][101];
pair<int,int> dxdy[4] = {{0,1},{1,0},{-1,0},{0,-1}};

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            path[i][j] = {-1,-1};
        }
    }
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            mat[i][j+1] = s[j]-'0';
        }
    }

    queue<pair<int,int>> q;
    q.push({1,1});
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        if(cur.first == n && cur.second == m){
            break;
        }
        for(int i=0;i<4;i++){
            int nx = cur.first + dxdy[i].first;
            int ny = cur.second + dxdy[i].second;
            if(nx>0 && ny >0 && nx <= n 
                && ny <= m 
                && path[nx][ny].first == -1 
                && mat[nx][ny] == 1){

                path[nx][ny] = {cur.first,cur.second};
                q.push({nx,ny});
            }
        }
    }
    int ans = 0;
    pair<int,int> cur = {n,m};
    while(cur.first != 1 || cur.second != 1){
        pair<int,int> thepath = path[cur.first][cur.second];
        cur = {thepath.first, thepath.second};
        ans++;
    }

    ans++;
    cout << ans;


    
    
    
}