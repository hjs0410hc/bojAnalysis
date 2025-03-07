#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
class Comparator{
    public:
    bool operator()(int i1, int i2){
        return i1<i2;
    }
};
int main(){
    vector<int> v = {1,2,3,4,5};
    reverse(v.begin(),v.end());
    for(auto i:v){
        cout << i << " ";
    }
    cout << "\n";
    for(auto i=v.rbegin();i<v.rend();i++){
        cout << *i << " ";
    }

}