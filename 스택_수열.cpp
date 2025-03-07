#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n;cin>>n;
    stack<int> st;
    string output = "";
    st.push(0);
    int x;
    int cur = 1;
    for(int i=0;i<n;i++){
        cin>>x;
        
        while(cur <= x){
            output += "+\n";
            st.push(cur++);
        }
        if(x == st.top()){
            output += "-\n";
            st.pop();
        }else{
            output = "NO\n";
            break;
        }
    }

    cout << output;
    
    
    
}