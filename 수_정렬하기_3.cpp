#include <bits/stdc++.h>
using namespace std;

int counts[10001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n;cin>>n;int x;
    for(int i=0;i<n;i++){
        cin >> x;
        counts[x]++;
    }

    for(int i=1;i<=10000;i++){
        for(int j=0;j<counts[i];j++){
            cout << i << "\n";
        }
    }


    
}