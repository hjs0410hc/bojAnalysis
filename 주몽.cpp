#include <bits/stdc++.h>
using namespace std;

long long arr[15001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }   
    sort(arr, arr+n);
    int start{0}, end{n-1};
    int ans = 0;
    while(start < end){ // 두개가 같으면 안된다.
        long long calc = arr[start]+ arr[end];

        if(calc == m){
            ans++;
            start++;
            end--;
        }else if(calc < m){
            start++;
        }else if(calc > m){
            end--;
        }
    }
    cout << ans;
    
    
}