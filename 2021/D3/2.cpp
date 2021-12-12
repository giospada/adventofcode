#include <bits/stdc++.h>

using namespace std;

vector<string> vs;




int getRes(bool minore){
    int l=0,r=vs.size()-1;
    for(int c=0;l-r!=0;c++){
        int n0=0,n1=0;
        for(int i=l;i<=r;i++){
            if(vs[i][c]=='1')n1++;
            else n0++;
        }
        if(n0==n1)
            if(minore)l+=n0;
            else r-=n1;
        else if((n0<n1)==minore) l+=n0;
        else r-=n1;
    }
    return l;
}


int main(){
    string s;
    int n=0;
    while(cin >>s){
        vs.push_back(s);
    }
    sort(vs.begin(),vs.end());
    int resa=getRes(true),resb=getRes(false);
    cout <<stoi(vs[resa],0,2)*stoi(vs[resb],0,2);

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
