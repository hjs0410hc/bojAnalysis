#include <bits/stdc++.h>
using namespace std;

long long arr[1000001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    long long n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   

    sort(arr, arr+n);
    long long start{0}, end{arr[n-1]+1}, middle;

    while(start < end){
        middle = (start+end)/2+1;
        long long wood = 0;
        for(int i=0;i<n;i++){
            wood += (arr[i]-middle > 0) ? arr[i]-middle : 0;
        }
        if(wood < m){
            end = middle-1;
        }else if(wood >= m){
            start = middle;
        }
    }
    
    cout << start;
    
    
}