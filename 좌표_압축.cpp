#include <bits/stdc++.h>
using namespace std;

long long arr[1000001];
long long original[1000001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    unordered_map<long long, int> rank;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        original[i] = arr[i];
    }

    sort(arr,arr+n);

    rank[arr[0]] = 0;
    int curRank = 0;
    long long prev = arr[0];
    for(int i=1;i<n;i++){
        if(prev < arr[i]){
            rank[arr[i]] = ++curRank;
        }
        prev=arr[i];
    }

    for(int i=0;i<n;i++){
        cout << rank[original[i]] << " ";
    }
    
    
    
}