#include <bits/stdc++.h>
using namespace std;

int arr[200001];
int counts[10];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n;cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int types = 0;

    int s=0;
    int ans=0;

    for(int i=0;i<n;i++){
        if(counts[arr[i]]++ == 0){
            types++;
        }
        while(types > 2){
            if(--counts[arr[s]] == 0){
                types--;
            }
            s++;
        }
        ans = max(ans, i-s+1);
    }

    cout << ans;
    
    
    
}