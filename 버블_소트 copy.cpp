// 이 문제는 몇회+1 만에 버블소트가 종료되었는지 판별하는 문제이다.
// 정렬 전 index와 정렬 후 index를 비교해서 그 차이를 구해 최댓값을 구하면 된다. 
// 차이 = 얼마나 이동했는가? => 왼쪽으로 이동한 경우 양수가 나온다. 
// 그러나 왼쪽으로 이동하는 범위가 한 루프당 최대 1이므로 이것이 버블소트 알고리즘 루프수가 된다.

#include <bits/stdc++.h>
using namespace std;

pair<int,int> org[500001];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n;cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin >> x;
        org[i] = {x, i};
    }

    sort(org, org+n);

    int maxi=0;
    for(int i=0;i<n;i++){
        maxi = max(maxi, org[i].second - i);
    }

    cout << maxi+1;
    

    
    
    
    
}