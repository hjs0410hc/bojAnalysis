#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,k;cin>>n>>k;
    
    // 탐색 범위 1~k-1

    int s{1}, e{k}, mid;
    int ans;
    while(s<=e){
        mid = (s+e)/2;
        
        //개수 세기
        int sum = 0;
        for(int i=1;i<=n;i++){
            sum += ((mid/i) > n ? n :mid/i);
        }

        if(sum >= k){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    cout << s;
}