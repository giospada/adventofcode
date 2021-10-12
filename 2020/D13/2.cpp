
#include <bits/stdc++.h>
// 578
// 145890 
// 0987154320
// 12347890:wq

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
    vtc<int> v{readsplit(s)};

    for(int i=0;true;i+=first){
        bool found=1;
        rep(j,v.size()){
            int t=i%v[j];
            if(t>first){
                found=0;
                break;
            }
        }
        if(found){
            printf("%d",i);
            break;
        }
    }


}

