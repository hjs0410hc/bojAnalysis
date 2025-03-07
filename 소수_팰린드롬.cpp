#include <bits/stdc++.h>
using namespace std;

bool notPrime[10000001];

bool check(int k){
    string s = to_string(k);
    int st{0}, e{(int)s.size()-1};
    while(st<=e){
        if(s[st] != s[e]){
            return false;
        }
        st++;
        e--;
    }
    return true;
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    notPrime[1]=true;
    for(int i=2;i<=sqrt(10000000);i++){
        for(int j=i+i; j<=10000000;j+=i){
            notPrime[j] = true;
        }
    }

    int n;cin>>n;

    for(int i=n;i<=10000000;i++){
        if(!notPrime[i] && check(i)){
            cout << i;
            break;
        }
    }
    
    
}