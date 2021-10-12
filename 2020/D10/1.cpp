#include <bits/stdc++.h>

using namespace std;

vector<int> in;
int all[4];

int main(){
    int a;
    while(EOF!= scanf("%d",&a)){
        in.push_back(a);
    }
    sort(in.begin(),in.end());
    
    int last=0;
    for(int i:in){
        if(last-i<4){
            all[i-last]++;
            last=i;
        }else{
            break;
        }
    }
    all[3]++;
    printf("%d\n",all[1]*all[3]);

}
