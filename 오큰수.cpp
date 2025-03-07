#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int ans[1000001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    stack<int> st;

    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(st.empty()){
            st.push(i);
        }else{
            while(!st.empty() && arr[i] > arr[st.top()]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
    }

    while(!st.empty()){
        ans[st.top()] = -1;
        st.pop();
    }

    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
}