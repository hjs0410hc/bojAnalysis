#include <bits/stdc++.h>
using namespace std;

bool visited[1000001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n;cin>>n;
    int mini = 2e9;
    queue<pair<int,int> > q;
    q.push({n,0});
    while(!q.empty()){
        pair<int,int> qt = q.front();
        q.pop();
        if(qt.first == 1 && mini > qt.second){
            mini = qt.second;
            break;
        }

        if(qt.first > 1){
            int y = qt.first;
            if(y%3==0 && !visited[y/3]){
                visited[y/3]=true;
                q.push({y/3, qt.second+1});
            }
            if(y%2==0 && !visited[y/2]){
                visited[y/2]=true;
                q.push({y/2, qt.second+1});
            }
            if(!visited[y-1]){
                visited[y-1]  =true;
                q.push({y-1, qt.second+1});

            }
        }
        
    }


    cout<<mini;
}