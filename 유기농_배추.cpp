#include <bits/stdc++.h>
using namespace std;

int n,m;
bool visited[51][51];
int mat[51][51];
pair<int,int> dxdy[4] = {{0,1}, {1,0},{0,-1},{-1,0}};

void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> qt = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = qt.first + dxdy[i].first;
            int ny = qt.second + dxdy[i].second;

            if(nx>=0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && mat[nx][ny]){
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }

}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        memset(visited,0,sizeof(visited));
        memset(mat,0,sizeof(mat));
        int k,x,y;cin>>m>>n>>k;

        for(int i=0;i<k;i++){
            cin>>y>>x;
            mat[x][y] = 1;
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && mat[i][j]==1){
                    ans++;
                    bfs(i,j);
                }
            }
        }
        cout << ans << "\n";
    }
    
    
    
}
