#include <bits/stdc++.h>
using namespace std;

int graph[51][51];
int ans[51];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n;cin>>n;string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j] == 'Y'){
                graph[i][j] = 1;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){ // i -> j 친구냐?
            if(i!=j){
                if(graph[i][j]){
                    ans[i]++;
                    continue;
                }
                for(int k=0;k<n;k++){ // C 찾기
                    if(k!=i && k!=j && graph[k][i] && graph[k][j]){
                        ans[i]++;
                        break;
                    }
                }
            }
        }
    }
    
    int maxi = 0;
    for(int i=0;i<n;i++){
        maxi = max(maxi, ans[i]);
    }

    cout << maxi;
    
}