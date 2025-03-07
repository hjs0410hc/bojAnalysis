#include <bits/stdc++.h>
using namespace std;


struct Job{
    int idx, startTime, length;
};

class Comp{
    public:
        bool operator()(Job p1, Job p2){
            if(p1.length == p2.length){
                if(p1.startTime==p2.startTime){
                    return p1.idx > p2.idx;
                }
                return p1.startTime > p2.startTime;
            }
            return p1.length > p2.length;
        }
    };

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    priority_queue<Job, vector<Job>, Comp> pq;
    pq.push({0,0,3});
    pq.push({1,1,9});
    pq.push({2,2,6});

    while(!pq.empty()){
        Job f = pq.top();
        pq.pop();
        cout << f.idx << " " << f.length << " " << f.startTime << "\n";
    }
    
    
    
}