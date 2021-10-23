#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define vtc vector


#define NB 36


string toBinary(int i){
    int k=0; 
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


int res(string s){
    ll sum=0;
    ll sumx=0;
    ll n_x=0;
    for(int i=NB-1;i>=0;i--){

    }
    return sumx*n_x+sum;

}


int main(){
    map<int,string> memo;
    int memory_cell,val;
    string curerntMask="";
    string input;
    while(getline(cin,input)){
        if(input.find("mask")!=string::npos){
            curerntMask=input.substr(input.size()-NB,input.size()-1);
        }else if(input.find("mem")!=string::npos){
            size_t i_parentesi=input.find("[");            
            size_t f_parentesi=input.find("]");            
            size_t i_numero=input.find("=");            
            memory_cell=stoi(input.substr(i_parentesi+1,f_parentesi-i_parentesi));
            val=stoi(input.substr(i_numero+2,input.size()-(i_numero+1)));
            string binary=toBinary(val);
            binary=applyMask(curerntMask,binary);
            memo.insert({memory_cell,binary});
            cout <<binary<<endl;
        }
    }
    long long res=0;
    for(auto i:memo){
    //    res=calc(i.second);
    }
    cout <<res<<endl;
}
