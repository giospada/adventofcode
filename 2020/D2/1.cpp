#include <bits/stdc++.h>


using namespace std;


int main(){
    int sol=0;
    int a,b;
    char c;
    while(EOF!= scanf("%d-%d %c: ",&a,&b,&c)){
        string s;
        cin >>s;
        int rep=0;
        for(char tmp:s){
            if(tmp==c)
                rep++;
        }
        if(b>=rep && a<=rep)
            sol++;
    }


    printf("%d",sol);

}
