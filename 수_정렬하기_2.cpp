#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int temp[1000001];

void merge_sort(int s,int e){
    if (e-s < 1){
        return;
    }

    int m = s + (e-s)/2; // s+ len/2
    merge_sort(s,m);
    merge_sort(m+1,e);

    for(int i=s;i<=e;i++){
        temp[i] = arr[i];
    }

    int inputIndex = s;
    int leftIndex = s;
    int rightIndex = m+1;
    while(leftIndex <= m && rightIndex <= e){
        if(temp[leftIndex] < temp[rightIndex]){
            arr[inputIndex] = temp[leftIndex];
            inputIndex++;
            leftIndex++;
        }else{
            arr[inputIndex] = temp[rightIndex];
            inputIndex++;
            rightIndex++;
        }
    }

    while(leftIndex<=m){
        arr[inputIndex] = temp[leftIndex];
        inputIndex++;
        leftIndex++;
    }
    while(rightIndex<=e){
        arr[inputIndex] = temp[rightIndex];
        inputIndex++;
        rightIndex++;
    }

}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    merge_sort(1,n);
    for(int i=1;i<=n;i++){
        cout << arr[i] << "\n";
    }
    
    
}