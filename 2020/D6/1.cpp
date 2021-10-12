#include <bits/stdc++.h>


using namespace std;


int main(){
    int sol=0;
    string s;
    bitset<27> b;
    while(getline(cin,s)){
        if(s==""){
            sol+=b.count();
            b.reset();
            continue;
        }
        for(char tmp:s){
            int pos=(int)tmp-'a';
            b[pos]=1;
        }
    }
    sol+=b.count();
    printf("%d",sol);
}
