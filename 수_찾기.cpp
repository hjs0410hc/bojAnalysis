#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[100001];

bool binary_search(int target){ //재귀로도 구현이 가능하다?
    int s{0}, e{n-1},mid;

    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid] == target) return true;
        else if(arr[mid] > target) e=mid-1;
        else if(arr[mid] < target) s=mid+1;
    }
    return false;
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n); // 필수

    cin>>m;
    int x;
    for(int i=0;i<m;i++){
        cin>>x;
        cout << (binary_search(x) ? 1: 0) << "\n";
    }
    
    
    
}