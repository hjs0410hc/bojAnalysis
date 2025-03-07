#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    string _kingPos, _stonePos;int n; cin>>_kingPos>>_stonePos>>n;
    pair<int,int> kingPos, stonePos;

    kingPos = {_kingPos[0]-'1', _kingPos[0]-'A'}; // 행 열
    stonePos = {_stonePos[0]-'1', _stonePos[0]-'A'};

    string comm;
    for(int i=0;i<n;i++){
        cin>>comm;
        if(comm=="R"){
            if(kingPos.second < 7){
                kingPos.second++;
            }
        }else if(comm=="L"){
            if(kingPos.second > 0){
                kingPos.second--;
            }
        }else if(comm=="B"){
            if(kingPos.first < 7){
                kingPos.first++;
            }
        }else if(comm=="T"){
            if(kingPos.first > 0){
                kingPos.first--;
            }
        }else if(comm=="RT"){
            if(kingPos.first > 0 && kingPos.second < 7){
                kingPos.first--;
                kingPos.second++;
            }
        }else if(comm=="LT"){
            if(kingPos.first > 0 && kingPos.second < 7){
                kingPos.first--;
                kingPos.second++;
            }
        }else if(comm=="RB"){
            if(kingPos.first > 0 && kingPos.second < 7){
                kingPos.first--;
                kingPos.second++;
            }
        }else if(comm=="LB"){
            if(kingPos.first > 0 && kingPos.second < 7){
                kingPos.first--;
                kingPos.second++;
            }
        }

        if(kingPos.first == stonePos.first && kingPos.second == stonePos.second){
            
        }
    }
    
    
    
}