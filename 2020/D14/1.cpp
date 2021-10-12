#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define vtc vector

#define LEN 36

map<int,int> bitmap;
map<int,string> mask;
vtc<string> val;
vtc<int> loc;


void readinput(){
    vector<string> v;
    string s;
    while(getline(cin,s)){
        v.push_back(s); 
        int ib=0;
        rep(i,s.size()){
            char c=s[i];
            if(c=='['){
                ib=i;
            }else if(c==']'){
                loc.push_back(stoi(s.substr(ib+1,i-ib-1)));
            }else if(c=='='){
                val.push_back(s.substr(i+2,s.size()-i-2));
                if(ib==0)
                    loc.push_back(-1);
                break;
            }
        }

    }

}

ll applaymask(string s,int n,ll v){
    rep(i,LEN){
        if(s[LEN-i-1]=='0'){
            v&=~((ll)1<<i);
        }else if(s[LEN-i-1]=='1'){
            v|=((ll)1<<i);
        }
    }
    return v;
}


int main(){
    readinput();

    string lm;
    rep(i,loc.size()){
        if(loc[i]==-1){
            lm=val[i];
        }else{
            mask[loc[i]]=lm;
            bitmap[loc[i]]=i;
        }
    }

    ll sum=0;
    for(auto& c:bitmap){
        int i=c.second;
        ll l=stoll(val[i]);
        sum+=applaymask(mask[c.first],loc[i],l);
    }
    printf("%lld",sum);

}
