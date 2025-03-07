#include <bits/stdc++.h>
using namespace std;

int arr[1001];
void swap(int i1,int i2){
    int temp = arr[i1];
    arr[i1]=arr[i2];
    arr[i2]=temp;
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   

    // INSERTION SORT IMPLEMENTATION
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            if(arr[i] < arr[j]){
                int insert_value = arr[i];
                for(int k=i;k>j;k--){
                    arr[k] = arr[k-1];
                }
                arr[j]=insert_value;
                break;
            }
        }
    }

    int temp = 0;int ans =0;
    for(int i=0;i<n;i++){
        temp += arr[i];
        ans+=temp;
    }
    cout << ans;

}