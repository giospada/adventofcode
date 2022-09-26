#include <bits/stdc++.h>


using namespace std;

        
vector<int> split(string q,string c){
    vector<int> res;
    size_t last=0;
    size_t next=-1;
    string sub;
    while((next=q.find(c,next+1))!=std::string::npos){
        sub=q.substr(last,next-last);
        res.push_back(stoi(sub)); 
        last=next+c.size();
    }
    sub=q.substr(last,q.size()-last);
    res.push_back(stoi(sub));
    return res;
}


vector<array<int,2>> readPos(){
    vector<array<int,2>> pos;
    string s;
    while(getline(cin,s)){
        if(s=="")break;
        vector<int> temp=split(s,",");
        pos.push_back({temp[0],temp[1]});
    }
    return pos;
}

vector<array<int,2>> readFold(){
    vector<array<int,2>> pos;
    string s;
    while(getline(cin,s)){
        char xoy=s[11];
        int t=stoi(s.substr(13,s.size()-13));
        if(xoy=='y'){
            pos.push_back({0,t});
        }else{
            pos.push_back({t,0});
        }
    }
    return pos;
}

int main(){
    vector<array<int,2>> pos=readPos();
    vector<array<int,2>> fold=readFold();
    set<array<int,2>> mappa;
    for(auto tmp:pos){
        mappa.insert(tmp); 
    }
    for(auto f:fold){
        int change=(f[0]==0)?1:0;
        vector<array<int,2>> tmp;
        for(auto pos:mappa){
            if(f[change]<=pos[change])
                tmp.push_back(pos);
        }
        for(auto pos:tmp){
            mappa.erase(pos);
            if(f[change]<pos[change]){
                pos[change]=f[change]-(pos[change]-f[change]);
                mappa.insert(pos);
            }
        }

        break;
    }
    cout <<mappa.size()<<endl;
}
