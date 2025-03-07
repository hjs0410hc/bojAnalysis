#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    set<int> st;
    int m;cin>>m;
    string s;int x;
    for(int i=0;i<m;i++){
        cin>>s;
        if(s=="add"){
            cin>>x;
            st.insert(x);
        }else if(s=="check"){
            cin>>x;
            cout << (st.count(x) > 0 ? 1 : 0) << "\n";
        }else if(s=="remove"){
            cin>>x;
            st.erase(x);
        }else if(s=="toggle"){
            cin>>x;
            if(st.count(x)>0){
                st.erase(x);
            }else{
                st.insert(x);
            }
        }else if(s=="all"){
            for(int i=1;i<=20;i++){
                st.insert(i);
            }
        }else if(s=="empty"){
            st.clear();
        }
    }
    
    
    
}