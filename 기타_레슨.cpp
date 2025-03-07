#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[100001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    cin>>n>>m; // 블루레이 개수가 주어짐 : m
    long long sum=0;
    int maxi = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+= arr[i];
        maxi= max(maxi , arr[i]);
    }

    // 블루레이 크기에 대해서 이진탐색
    // 가능한지 여부, 블루레이 크기가 최소
    
    long long s{maxi}, e{sum};
    
    
    while(s<=e){
        int mid = (s+e)/2;
        // check if possible
        int cnt = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(sum + arr[i] > mid){
                sum = 0;
                cnt++;
            }
            sum += arr[i];
            
        }
        if(sum){
            cnt++;
        }
        if(cnt > m){
            s = mid+1;
        }else if(cnt <= m){
            e = mid-1;
        }
    }
    cout << s;
}