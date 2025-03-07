#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int psum[100001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        psum[i] = psum[i-1]+arr[i];
    }
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        cout << psum[y]-psum[x-1] << "\n";
    }
    
    
    
}