#include <bits/stdc++.h>


using namespace std;


int main(){
    int sol=0;
    string s;
    bitset<27> b;
    bool fl=1;
    while(getline(cin,s)){
        if(s==""){
            sol+=b.count();
            b.reset();
            fl=1;
            continue;
        }
        if(fl){
            for(char tmp:s){
                int pos=(int)tmp-'a';
                b[pos]=1;
            }
            fl=0;
        }else{
            bitset<27> nb;
            for(char tmp:s){
                int pos=(int)tmp-'a';
                nb[pos]=1; 
            }
            b=b&nb;
        }
    }
    sol+=b.count();
    printf("%d",sol);
}
