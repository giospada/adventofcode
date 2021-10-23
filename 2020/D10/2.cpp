#include <bits/stdc++.h>

using namespace std;

vector<int> in;
vector<long long> dp;


int main(){
    int a;
    in.push_back(0);
    dp.push_back(0);
    while(EOF!= scanf("%d",&a)){
        in.push_back(a);
        dp.push_back(0);
    }
    sort(in.begin(),in.end());
    
    int last=0;
    dp[0]=1;
    for(int i=0;i<in.size();i++){
        int addNext=i+1;
        while(in.size()> addNext && in[i]+3>=in[addNext]){
            dp[addNext]+=dp[i];
            addNext++;
        }
    }
    cout <<dp.back()<<endl;
}


