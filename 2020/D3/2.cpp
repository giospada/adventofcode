#include <bits/stdc++.h>

using namespace std;


vector<string> v;

long long traverse(int dx,int dy,int len){
    long long cnt=0;
    int x=0,y=0;
    while(y<v.size()){
        if(v[y][x]=='#')
            cnt++;
        x+=dx;
        x%=len;
        y+=dy;
    }
    return cnt;
}
int main(){
    long long sol=1;
    string s;
    while(getline(cin,s)){
        v.push_back(s);
    }
    int len=v[0].size();
    sol*=traverse(1,1,len);
    sol*=traverse(3,1,len);
    sol*=traverse(5,1,len);
    sol*=traverse(7,1,len);
    sol*=traverse(1,2,len);
    printf("%lld",sol);
}
