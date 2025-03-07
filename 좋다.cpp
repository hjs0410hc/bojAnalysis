#include <bits/stdc++.h>
using namespace std;

int arr[2001]; // real number, index


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n;cin>>n;int x;
    for(int i=0;i<n;i++){
        cin>>x;
        arr[i] = x;
    }

    sort(arr, arr+n);
    int ans = 0;

    for(int cur = 0; cur < n; cur++){ // 정렬된 인덱스
        int si{0}, ei{n-1};
        long long sum;bool good=false;
        while(si < ei){ // 같은 수를 쓸 수 없게 한다.
            if(si==cur){
                si++;
                continue;
            }else if(ei==cur){
                ei--;
                continue;
            }
            sum = arr[si] + arr[ei];
            if(sum==arr[cur]){
                good=true;break;
            }else if(sum > arr[cur]){
                ei--;
            }else if(sum < arr[cur]){
                si++;
            }
        }
        if(good) ans++;
    }
    
    cout << ans;
    
    
}