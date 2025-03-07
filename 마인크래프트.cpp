#include <bits/stdc++.h>
using namespace std;

int mat[501][501];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,m,b;cin>>n>>m>>b;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    int mini = 2e9;
    int miniheight = 0;
    for(int height=0;height<=256;height++){
        int tobreak = 0;
        int tobury = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] > height){
                    tobreak += mat[i][j] - height;
                }else{
                    tobury += height-mat[i][j];
                }
            }
        }
        int result=2e9;
        if(tobury <= tobreak+b){
            result = tobury+tobreak*2;
        }
        if (mini >= result){
            mini = result;
            miniheight = height;
        }
    }

    cout << mini << " " << miniheight;
    
    
    
}