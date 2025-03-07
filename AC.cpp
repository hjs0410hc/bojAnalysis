#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int tc;cin>>tc;while(tc--){
        string comm;
        cin>>comm;
        int n;cin>>n;
        deque<int> v;
        string nums; cin>>nums;
        int temp=0;
        for(char c:nums){
            if(c>='0' && c<='9'){
                temp*=10;
                temp+=c-'0';
            }else if(c == ',' || c== ']'){
                v.push_back(temp);
                temp=0;
            }
        }
        bool reversed = false;
        int frontout = 0;
        int rearout = 0;
        for(char c: comm){
            if(c=='R'){
                reversed = !reversed;
            }else{
                if(reversed){
                    rearout++;
                }else{
                    frontout++;
                }
            }
        }
        if(rearout+frontout > n){
            cout << "error\n";
            continue;
        }
        if(nums=="[]"){ // ;;
            cout << "[]\n";
            continue;
        }
        
        for(int i=0;i<frontout;i++){
            v.pop_front();
        }
        for(int i=0;i<rearout;i++){
            v.pop_back();
        }
        if(v.empty()){
            cout << "[]\n";
            continue;
        }
        cout << "[";
        if(reversed){
            while(v.size() > 1){
                cout << v.back() << ",";
                v.pop_back();
            }
            cout << v.back() <<"]";
        }else{
            while(v.size()>1){
                cout << v.front() << ",";
                v.pop_front();
            }
            cout << v.front() << "]";
        }
        cout << "\n";

    }
}