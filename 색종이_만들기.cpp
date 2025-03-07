#include <bits/stdc++.h>
using namespace std;

int n;
int mat[129][129];
int ans[2];

void recur(int x,int y, int size){
    if(size==1){
        ans[mat[x][y]]++;
        return;
    }
    int prev = mat[x][y];
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(mat[i][j] != prev){
                // another recursion
                recur(x,y, size/2);
                recur(x+size/2,y,size/2);
                recur(x,y+size/2,size/2);
                recur(x+size/2,y+size/2,size/2);
                return;
            }else{
                prev=mat[i][j];
            }
        }
    }
    ans[mat[x][y]]++;
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    recur(0,0,n);
    
    cout << ans[0]<<"\n"<<ans[1];
    
}