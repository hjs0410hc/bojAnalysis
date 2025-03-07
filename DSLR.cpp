#include <bits/stdc++.h>
using namespace std;

char ops[10000];
int path[10000];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        memset(ops, 0, sizeof(ops));
        memset(path, -1, sizeof(path));
        int x,y;
        cin>>x>>y;
        queue<int> q;
        path[x] = 0;
        q.push(x);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur == y){
                break;
            }

            // D
            int doub = (2*cur)%10000;
            if(path[doub] == -1){
                path[doub] =cur;
                ops[doub] = 'D';
                q.push(doub);
            }

            // S
            int subt = (cur-1 < 0) ? 9999 : cur-1;
            if(path[subt] == -1){
                path[subt] = cur;
                ops[subt] = 'S';
                q.push(subt);
            }

            // L
            int le = (cur*10 + cur/1000) % 10000;
            if(path[le] == -1){
                path[le] = cur;
                ops[le] = 'L';
                q.push(le);
            }

            // R
            int ri = (cur+ 10000*(cur%10))/10;
            if(path[ri] == -1){
                path[ri] = cur;
                ops[ri] = 'R';
                q.push(ri);
            }

            //cout << cur << ": "<< doub <<  " " << subt << " "<< le << " " << ri << "\n";
        }
        int cur = y;
        string ans = "";
        while(cur != x){
            ans += ops[cur];
            cur = path[cur];
        }
        for(int i=ans.size()-1;i>=0;i--){
            cout << ans[i];
        }
        cout << "\n";

    }
    
    
    
}