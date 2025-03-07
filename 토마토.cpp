#include <bits/stdc++.h>
using namespace std;

int mat[101][101][101];

struct Point{
    int x,y,z;
};

Point ddd[6] = {{0,0,1}, {1,0,0}, {0,1,0}, {0,0,-1}, {0,-1,0}, {-1,0,0}};


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    queue<Point> q;
    int m,n,h;cin>>m>>n>>h;
    for(int k=0;k<h;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> mat[i][j][k];
                if(mat[i][j][k] == 1){
                    q.push({i,j,k});
                }
            }
        }
    }
    

    while(!q.empty()){
        Point cur = q.front();
        q.pop();

        for(int i=0;i<6;i++){
            int nx = cur.x+ddd[i].x;
            int ny = cur.y+ddd[i].y;
            int nz = cur.z+ddd[i].z;
            if(nx>=0 && ny>=0&&nz>=0&&nx<n&&ny<m&&nz<h&&mat[nx][ny][nz]==0){
                mat[nx][ny][nz]=mat[cur.x][cur.y][cur.z]+1;
                q.push({nx,ny,nz});
            }
        }
    }
    int maxi = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<h;k++){
                if(mat[i][j][k] == 0){
                    cout << -1;return 0;
                }
                maxi = max(maxi, mat[i][j][k]);
            }
        }
    }

    cout << maxi-1;
}