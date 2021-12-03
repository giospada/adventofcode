#include <bits/stdc++.h>

using namespace std;


int main() {
    int last=INT_MAX;
    int n;
    int res=0;
    while(cin >>n){
        if(n>last)
            res++;
        last=n;
    }
    cout <<res<<endl;
}
