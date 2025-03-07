#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    priority_queue<int> maxpq;
    priority_queue<int,vector<int>, greater<int>> minpq;
    int n,x;cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x==0){
            if(minpq.empty() && maxpq.empty()){
                cout << 0 << "\n";
            }else if(minpq.empty()){
                cout << maxpq.top() << "\n";
                maxpq.pop();
            }else if(maxpq.empty()){
                cout << minpq.top() << "\n";
                minpq.pop();
            }else{
                if(-1*maxpq.top() == minpq.top()){
                    cout << maxpq.top() << "\n";
                    maxpq.pop();
                }else if(-1*maxpq.top() < minpq.top()){
                    cout << maxpq.top() << "\n";
                    maxpq.pop();
                }else if(-1*maxpq.top() >  minpq.top()){
                    cout << minpq.top() << "\n";
                    minpq.pop();
                }
            }
        }else{
            if(x>0){
                minpq.push(x);
            }else{
                maxpq.push(x);
            }
        }
    }
    
    
    
    
}