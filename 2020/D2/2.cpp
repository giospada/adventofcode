#include <bits/stdc++.h>


using namespace std;


int main(){
    int sol=0;
    int a,b;
    char c;
    while(EOF!= scanf("%d-%d %c: ",&a,&b,&c)){
        a--;b--;
        string s;
        cin >>s;
        if((s[a]==c)!=(s[b]==c))
            sol++;
    }


    printf("%d",sol);

}
