#include <bits/stdc++.h>

using namespace std;


int main(){
    string s;
    vector<vector<int>> grind;
    vector<vector<int>> dp;
    while(getline(cin,s)){
        vector<int> v;
        vector<int> dpt;
        for(auto c:s){
            v.push_back(c-'0');
            dpt.push_back(0); 
        }
        dp.push_back(dpt);
        grind.push_back(v);
    }
    for(int i=0;i<grind.size();i++){
        for(int j=0;j<grind[i].size();j++){
            if(i==0 and j==0)
                continue;
            else
                dp[i][j]=grind[i][j]+min(((i-1>=0)?dp[i-1][j]:INT_MAX),((j-1>=0)?dp[i][j-1]:INT_MAX));
        }
    }
    int h=grind.size()-1;
    cout <<dp[h][dp[h].size()-1];
}
