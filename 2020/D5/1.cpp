#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)


int main(){
    string s; 
    int sol=0;
    while(getline(cin,s)){
        int a=0,b=127;
        rep(i,7){
            int m=(a+b+1)/2;
            if(s[i]=='B')
                a=m+1;
            else
                b=m-1;
        }
        int c=a-1;
        a=0,b=7;
        rep(i,3){
            int m=(a+b+1)/2;
            if(s[i+7]=='R')
                a=m+1;
            else
                b=m-1;
        }
        sol=max(sol,c*8+b);

    }

    printf("%d",sol);
}
