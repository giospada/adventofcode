#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(long long i=0;i<n;i++)
#define ll long long
#define vtc vector

#define NB 36


string toBinary(ll i){
    ll k=0; 
    string s;
    rep(l,NB){
        s+="0";
    }
    while(i>0&&k<NB){
        if(i%2==1){
            s[NB-k-1]='1';
        }
        i/=2;
        k++; 
    }
    return s;
}

string applyMask(string mask,string binaryNum){
    assert(mask.size()==binaryNum.size());
    for(int i=0;i<mask.size();i++){
        if(mask[i]=='1')
            binaryNum[i]='1';
        else if(mask[i]=='X')
            binaryNum[i]='X';
    }
    return binaryNum;
}

ll countIfNotInTheSet(set<ll> &s,string b){
    ll numX=count(b.begin(),b.end(),'X');
    vector<ll> posX;
    ll current=0;
    rep(i,b.size()){
        if(b[i]=='1'){
            current+=1<<(b.size()-i-1);
        }else if(b[i]=='X'){
            posX.push_back(b.size()-i-1);
        }
    }
    if(posX.size()==0 && s.find(current)==s.end()){
        s.insert(current);
        return 1;
    }
    ll res=0;
    rep(i,1<<(posX.size())){
        ll parziale=0;
        rep(j,posX.size()){
            if(i&(1<<(j))){
                parziale+=1<<(posX[j]);
            }
        }
        if(s.find(parziale+current)==s.end()){
            s.insert(parziale+current);
            res++;
        }
    }
    return res;
}

int main(){
    assert(toBinary(42)==("000000000000000000000000000000101010"));
    vector<pair<string,ll>> vs;
    ll memory_cell,val;
    string curerntMask="";
    string input;
    while(getline(cin,input)){
        if(input.find("mask")!=string::npos){
            curerntMask=input.substr(input.size()-NB,input.size()-1);
        }else if(input.find("mem")!=string::npos){
            //read mem
            size_t i_parentesi=input.find("[");            
            size_t f_parentesi=input.find("]");            
            size_t i_numero=input.find("=");            
            memory_cell=stoi(input.substr(i_parentesi+1,f_parentesi-i_parentesi));
            string binary=toBinary(memory_cell);
            val=stol(input.substr(i_numero+2,input.size()-(i_numero+1)));
            //applica la masschera
            binary=applyMask(curerntMask,binary);
            vs.push_back({binary,val});
        }
    }
    set<ll> s;
    long long res=0;
    reverse(vs.begin(),vs.end());
    for(auto i:vs){
        res+=countIfNotInTheSet(s,i.first)*i.second;
    }
    cout <<res<<endl;
}
