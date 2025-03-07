#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int n, r,c;

void Z(int x,int y, int size){
    if(size==0){
        if(x==r && y==c){
            cout << ans;
        }
        ans++;
        return;
    }

    int realSize = pow(2,size);
    if(r >= x && r < x+realSize && c>=y && c < y+realSize){
        // 4 분할
        Z(x,y,size-1);
        Z(x, y+realSize/2, size-1);
        Z(x+realSize/2, y, size-1);
        Z(x+realSize/2, y+realSize/2, size-1);
    }else{
        ans += realSize*realSize;
    }

}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    cin >>n>>r>>c;
    Z(0,0,n);
    
    
}