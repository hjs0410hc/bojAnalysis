#include <bits/stdc++.h>
using namespace std;


int instsum(int x,int y){ // x >= y
    return ((x-y+1)*(x+y))/2;
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n;cin>>n;
    
    int start{1}, end{1}, ans{0};
    int sum=1;

    while(start<=end){
        if(sum == n){
            ans++;
            end++;
            sum+=end;
        } else if(sum < n){
            end++;
            sum+=end;
        }else if(sum > n){
            sum-=start;
            start++;
        }
    }
    
    cout << ans;
}