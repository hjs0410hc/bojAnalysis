#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    // 음수인 경우 음수랑 묶고, 양수인 경우 양수 큰것과 묶는다.
    // 0은 maxpq에 들어가는데, 이때 이 친구는 경우의 수가 좀 있다.
    // 0 만 남았을 경우
    // 0이 여러개 남았을 경우
    // 0과 음수가 하나 남았을 경우
    priority_queue<int> maxpq;
    priority_queue<int,vector<int>,greater<int>> minpq;

    int n; cin>>n;
    int x;
    int numOnes = 0;
    int numZeros = 0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x==1){
            numOnes++;
        }else if(x==0){
            numZeros++;
        }else if(x>0){
            maxpq.push(x);
        }else if(x<0){
            minpq.push(x);
        }
    }

    long long ans = 0;

    while(maxpq.size() > 1){
        int first = maxpq.top();
        maxpq.pop();
        int second = maxpq.top();
        maxpq.pop();

        ans+=first*second;
    }
    if(!maxpq.empty()){
        ans += maxpq.top();
    }
    while(minpq.size() > 1){
        int first = minpq.top();
        minpq.pop();
        int second = minpq.top();
        minpq.pop();

        ans+= first*second;
    }

    if(!minpq.empty()){
        if(!numZeros){
            ans += minpq.top();
        }
    }

    ans+= numOnes;

    cout << ans;
    
}