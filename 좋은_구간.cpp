#include <bits/stdc++.h>
using namespace std;

int arr[51];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int l;cin>>l;
    for(int i=0;i<l;i++){
        cin>>arr[i];
    }   
    int n;cin>>n;
    sort(arr, arr+l);
    int closest = -1;
    for(int i=0;i<l;i++){
        if(arr[i] == n){
            cout << 0;
            return 0;
        }
        if(arr[i] > n){
            closest = i;
            break;
        }
    }

    int start = 1;
    int end = arr[closest]-1;
    if(closest != 0){
        start=arr[closest-1]+1;
    }
    //cout << start << " " << end << "\n";

    if(start>=end){
        cout << 0;
        return 0;
    }

    int left = n-start+1;
    int right = end-n+1;

    cout << left*right-1;

    
    
    
}