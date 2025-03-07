#include <bits/stdc++.h>
using namespace std;

long long psum[1000001];
long long counts[1001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,m;cin>>n>>m;long long x;
    for(int i=0;i<n;i++){
        cin >> x;
        if(i==0){
            psum[i] = x%m;
        }else{
            psum[i] = (psum[i-1]%m + x%m)%m;
        }
        counts[psum[i]]++;
    }

    // psum = 0~i까지의 합
    // 뺐을 때 0이면 나눠 떨어짐. OK !!

    // nC2 = n*(n-1)/2

    long long ans = 0;
    ans += counts[0];
    for(int i=0;i<m;i++){
        ans += (counts[i] * (counts[i]-1))/2;
    }
    cout << ans;
    
}