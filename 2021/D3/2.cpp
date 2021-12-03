#include <bits/stdc++.h>

using namespace std;

vector<int> freq;
vector<string> vs;


int binarysearch(int &l,int &r,int c){
    int tb=l;
    int p=1;
    while((r-l)<p)p*=2;
    for(;p>0;p/=2){
        while((tb+p<=r)&&vs[tb+p][c]!='1')tb+=p;
    }
    return tb;
}


int getRes(bool minore){
    int l=0,r=vs.size()-1;
    for(int c=0;l-r!=0;c++){
        int res=binarysearch(l,r,c);
        cout <<vs[l]<<" "<<vs[res]<<"-"<<vs[res+1]<<" "<<vs[r]<<endl;
        cout <<l<<" "<<res<<" "<<r<<endl;
        if(freq[c]*2==vs.size()){
            if(minore){
                r=res; 
            }else{
                l=res+1; 
            }
        }else if((freq[c]*2<=vs.size())==minore){
            l=res+1; 
        }else{
            r=res; 
        }
    }
    cout <<endl;
    return l;
}


int main(){
    string s;
    int n=0;
    while(cin >>s){
        if(freq.size()==0)
            freq.resize(s.size());
        for(int i=0;i<s.size();i++){
            freq[i]+=s[i]-'0';
        }
        vs.push_back(s);
    }
    for(auto i :freq)cout <<i<<endl;
    cout <<endl<<vs.size()<<endl;
    sort(vs.begin(),vs.end());
    int resa=getRes(true),resb=getRes(false);
    cout <<vs[resa]<<" "<<vs[resb]<<endl;
    cout <<stoi(vs[resa],0,2)<<" "<<stoi(vs[resb],0,2);

}


/*
   a=0;b=vs.size()-1;
   for(int i=0;i<s.size();i++){
   if(a-b==0){
   break;
   }
   int k=a;
   for(;k<=b;k++){
   if(vs[k][i]=='1'){
   break;
   }
   }
   if(freq[i]*2<=vs.size()){
   b=k-1;
   }else{
   a=k;        
   }
   }
   */
