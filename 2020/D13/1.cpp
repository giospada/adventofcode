#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define vtc vector

const vtc<int> readsplit(string s){
    int last=0;
    vtc<int> v;
    rep(i,s.size()){
        if(s[i]==','){
            string cs=s.substr(last,i-last);
            if(cs!="x"){
                v.push_back(stoi(cs));
            }
            last=i+1;
        }
    }
    string cs=s.substr(last,s.size()-last);
    if(cs!="x"){
        v.push_back(stoi(cs));
    }
    return v;
}

int main(){
    int val;
    scanf("%d\n",&val);
    string s;
    getline(cin,s);
    int mval=INT_MAX;
    int mid=-1;
    vtc<int> v{readsplit(s)};
    
    rep(i,v.size()){
         int r=v[i]-(val%v[i]); 
         if(mval>=r){
            mval=r;
            mid=v[i];
         }

    }
    printf("%d",mval*mid);


}

