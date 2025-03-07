#include <bits/stdc++.h>
using namespace std;

class Comp{
    public:
    bool operator()(int x, int y){
        int absX = (x<0? -1*x : x);
        int absY = (y<0?-1*y:y);
        if(absX==absY){
            return x>y; // 오름차순?
        }
        return absX>absY; //오름차순?
    }
};

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    priority_queue<int, vector<int>, Comp> pq;

    int n,x;cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x==0){
            if(pq.empty()){
                cout << 0 << "\n";
            }else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }else{
            pq.push(x);
        }
    }
    
    
    
    
}