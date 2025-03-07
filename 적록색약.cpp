#include <bits/stdc++.h>
using namespace std;

char mat[101][101];
bool visited[101][101];
pair<int,int> dxdy[4] = {{0,1},{1,0},{0,-1},{-1,0}};

int n;

void bfs(int x,int y, int mode){
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first+dxdy[i].first;
            int ny = cur.second+dxdy[i].second;
            if(nx >=0&&ny>=0&&nx<n&&ny<n&&!visited[nx][ny]){
                if(mode){ // R==G
                    if((mat[cur.first][cur.second] == 'R' || mat[cur.first][cur.second] == 'G')
                && (mat[nx][ny]=='R' || mat[nx][ny] =='G')){
                        visited[nx][ny] = true;
                        q.push({nx,ny});
                    }else if(mat[cur.first][cur.second]=='B' && mat[nx][ny] == 'B'){
                        visited[nx][ny] =true;
                        q.push({nx,ny});
                    }
                }else{
                    if(mat[cur.first][cur.second] == mat[nx][ny]){
                        visited[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            mat[i][j] = s[j];
        }
    }
    int norm = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                norm++;
                bfs(i,j,0);
            }
        }
    }
    memset(visited,0,sizeof(visited));

    int ch = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                ch++;
                bfs(i,j,1);
            }
        }
    }
    cout << norm << " " << ch;

    
    
    
}