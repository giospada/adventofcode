#include <bits/stdc++.h>

using namespace std;

int main(){
    int sol=0;
    string s;
    int posx=0;
    while(getline(cin,s)){
        int len=s.size();
        posx=posx%len;
        if(s[posx]=='#')
            sol++;
        posx+=3;
    }
    printf("%d",sol);
}
