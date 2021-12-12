#include <bits/stdc++.h>

using namespace  std;

int main(){
    vector<vector<int>> v;
    string s;
    while(getline(cin,s)){
        vector<int> temp;
        for(auto &c:s){
            temp.push_back(c-'0');
        }
        v.emplace_back(temp);
    }
    int sum=0;
    for(int y=0;y<v.size();y++){
        for(int x=0;x<v[y].size();x++){
            bool isMin=true;
            isMin&=(x+1<v[y].size())?v[y][x+1]>v[y][x]:true; 
            isMin&=(y+1<v.size())?v[y+1][x]>v[y][x]:true; 
            isMin&=(x-1>=0)?v[y][x-1]>v[y][x]:true; 
            isMin&=(y-1>=0)?v[y-1][x]>v[y][x]:true; 
            if(isMin)sum+=v[y][x]+1;
        }
    }
    cout <<sum<<endl;
}