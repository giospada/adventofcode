#include <bits/stdc++.h>


using namespace std;


int main(){
    string s;
    int n=0;
    vector<int> freq;
    while(cin >>s){
        if(freq.size()==0)
            freq.resize(s.size());
        for(int i=0;i<s.size();i++){
            freq[i]+=s[i]-'0';
        }
        n++;
    }
    int a=0,b=0;
    for(int i=0;i<s.size();i++){
        if(freq[i]*2<=n){
            a+=(1<<(s.size()-i-1));
        }else{
            b+=(1<<(s.size()-i-1));
        }
    }
    cout <<a<<" "<<b<<" "<<a*b<<endl;
}
