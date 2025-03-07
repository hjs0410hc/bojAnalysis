#include <bits/stdc++.h>
using namespace std;

int n,m,sx,sy;
int mat[1001][1001];
pair<int,int> dxdy[4] = {{1,0},{0,1}, {-1,0}, {0,-1}};
int ans[1001][1001];

struct elem{
    int x,y,dist;
};

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    memset(ans, -1, sizeof(ans));
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
            if(mat[i][j] == 2){
                sx=i;sy=j;
            }else if(mat[i][j] == 0){
                ans[i][j] = 0;
            }
        }
    }
    
    ans[sx][sy] = 0;
    queue<elem> q;
    q.push({sx,sy,0});
    while(!q.empty()){
        elem cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.x+dxdy[i].first;
            int ny = cur.y+dxdy[i].second;
            if(nx>=0 && ny>=0&&nx<n&&ny<m&&ans[nx][ny]==-1&&mat[nx][ny]!=0){
                ans[nx][ny]=cur.dist+1;
                q.push({nx,ny,cur.dist+1});
            }
        }
    }


    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    
}