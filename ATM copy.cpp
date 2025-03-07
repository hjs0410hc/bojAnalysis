#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   

    sort(arr,arr+n);
    int temp = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        temp += arr[i];
        ans += temp;
    }
    cout << ans;
}