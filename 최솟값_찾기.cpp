#include <bits/stdc++.h>
using namespace std;

long long arr[5000001];
long long ans[5000001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    deque<pair<int,int>> dq;
    int n,L; cin>>n>>L;

    int x;
    for(int i=0;i<n;i++){
        cin>>x;

        while(!dq.empty() && dq.back().first > x){ // 이게 중요
            dq.pop_back();
        }

        dq.push_back({x,i});

        if(dq.front().second <= i-L){ // 슬라이딩 윈도우
            dq.pop_front();
        }
        cout << dq.front().first << " ";
    }
}