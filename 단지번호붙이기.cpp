#include <bits/stdc++.h>
using namespace std;

int mat[26][26];
pair<int,int> dxdy[4] = {{0,1},{1,0},{-1,0},{0,-1}};
bool visited[26][26];
int n;

int bfs(int x,int y){
    visited[x][y]=true;
    int res = 0;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        res++;
        for(int i=0;i<4;i++){
            int nx=cur.first+dxdy[i].first;
            int ny =cur.second+dxdy[i].second;
            if(nx>=0&&ny>=0&&nx<n&&ny<n&&!visited[nx][ny]&&mat[nx][ny]){
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
    return res;
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    cin>>n;
    string s;
    vector<int> v;

    for(int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<n;j++){
            mat[i][j] = s[j]-'0';
        }
    }

    int totalCC =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] && !visited[i][j]){
                totalCC++;
                v.push_back(bfs(i,j));
            }
        }
    }
    
    cout << totalCC << "\n";
    sort(v.begin(),v.end());
    for(int i:v){
        cout << i <<"\n";
    }
    
    
    
}