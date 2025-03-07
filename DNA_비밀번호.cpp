#include <bits/stdc++.h>
using namespace std;


int cvt(char c){
    switch (c){
        case 'A':
        return 0;
        case 'C':
        return 1;
        case 'G':
        return 2;
        case 'T':
        return 3;
        default:
        return -1;
    }
}

int counts[4];
int cond[4];

bool check(){
    for(int i=0;i<4;i++){
        if(counts[i] < cond[i]){
            return false;
        }
    }
    return true;
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    string s;
    cin>>s;
    
    for(int i=0;i<4;i++){
        cin >> cond[i]; // A C G T
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        // 고려해야 될 건 s[i] 하나다.
        if(i < m-1){
            counts[cvt(s[i])]++;
        }else{
            counts[cvt(s[i])]++;
            if(check()){
                ans++;
            }
            counts[cvt(s[i-m+1])]--;
        }

        
    }
    cout << ans;
}