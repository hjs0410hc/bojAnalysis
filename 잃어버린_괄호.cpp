#include <bits/stdc++.h>
using namespace std;


vector<string> split(string str, char delim){
    istringstream istr(str);
    string buf;
    vector<string> result;

    while(getline(istr,buf,delim)){
        result.push_back(buf);
    }

    return result;
}

int sumOfString(string str){
    vector<string> splitted = split(str, '+');
    int result = 0;
    for(string s: splitted){
        result += stoi(s);
    }
    return result;
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    string s; cin>>s;
    
    bool first=true;
    long long ans = 0;
    for(string form : split(s,'-')){
        int sum = sumOfString(form);

        if(first){
            first=false;
            ans+=sum;
        }else{
            ans-=sum;
        }
    }
    
    cout << ans;
    
    
}