#include <bits/stdc++.h>
using namespace std;

bool isPrime[10000001];


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    long long int a,b;cin>>a>>b;
    long long int ans = 0;
 
    isPrime[1]=true;
    for(int i=2;i<=sqrt(10000001);i++){
        for(long long int j=i+i; j <= 10000000; j+=i){
            isPrime[j]=true;
        }
    }

    for(long long i=2;i<=10000000;i++){
        if(!isPrime[i]){
            long long temp = i;
            while((double)i <= (double)b / (double)temp){
                if((double)i >= (double)a / (double)temp){
                    ans++;
                }
                temp = temp * i;
            }
        }
    }

    cout << ans;
}