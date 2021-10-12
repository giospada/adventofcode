#include <bits/stdc++.h>

using namespace std;

#define MN 2020

bitset<MN+1> o;
bitset<MN+1> s;

int main(){
    int n;
    while(EOF != scanf("%d",&n)){
        if(s[MN-n]){
            break;
        }else{
            s|=o<<n; 
            o[n]=1;
        }
    }
    int r=MN-n;
    for(int i=0;i<r;i++){
        if(o[i] and o[abs(i-r)]){
            printf("%d\n",i*abs(i-r)*n);
            break;
        }
    }

}
