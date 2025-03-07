#include <bits/stdc++.h>
using namespace std;

void swap(string& target, int i1, int i2){
    char temp = target[i2];
    target[i2] = target[i1];
    target[i1] = temp;
    
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    
    // SELECTION SORT
    // 선택 정렬은 최솟값인 놈을 찾는 정렬 방법이다.

    string s;cin>>s;

    for(int i=0;i<s.size()-1;i++){
        int miniIdx = i;
        for(int j=i; j<s.size();j++){
            if(s[miniIdx] < s[j]){
                miniIdx=j;
            }
        }
        swap(s,i,miniIdx);
    }

    cout << s;

    
    
}