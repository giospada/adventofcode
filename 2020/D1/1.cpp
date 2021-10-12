#include <bits/stdc++.h>

using namespace std;

#define MN 2020

bitset<MN+2> bit;

int main(){
    int n;
//    bit.reset();
    while(EOF != scanf("%d",&n))
        if(bit[MN-n])
            printf("%d\n",n*(2020-n));
        else
            bit[n]=1;
}
