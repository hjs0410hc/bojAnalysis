#include <bits/stdc++.h>
using namespace std;

class Comp{ // pq comparator ...
public:
    bool operator()(int i1, int i2){
        return i1<i2; // 기본, 내림차순.
    }
};

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    priority_queue<int, vector<int>, Comp> pq;
    vector<int> arr;
    int n=10;
    for(int i=0;i<n;i++){
        arr.push_back(i);
        pq.push(i);
    }
    sort(arr.begin(), arr.end(), [](int i1, int i2){
        return i1<i2; // 기본, 오름차순
    });
    for(int i:arr){
        cout << i << " ";
    }
    cout << "\n";
    
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    
    
}