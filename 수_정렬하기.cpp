#include <bits/stdc++.h>
using namespace std;

int arr[1001];

void swap(int i1, int i2){
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

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j] > arr[j+1]){
                swap(j,j+1);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << "\n";
    }
    
    
}