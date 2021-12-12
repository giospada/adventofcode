#include <bits/stdc++.h>


#define rep(i,n) for(int i=0;i<n;i++)
#define fep(i,k,n) for(int i=k;i<n;i++)

using namespace std;

#define vc vector

typedef array<int,2> ii;

int res=0;

void print(vc<vc<int>> &v){
    rep(x,v.size()){
        rep(y,v[x].size()){
            cout <<v[x][y];
        }
        cout <<endl;
    }
    cout <<endl;
}


void exploreAll(vc<vc<int>> &v,queue<ii> &q){
    while(!q.empty()){
        ii a=q.front();
        q.pop();
        int x=a[0],y=a[1];
        if(v[x][y]==0)continue;
        res++;
        v[x][y]=0;
        fep(dx,-1,2){
            fep(dy,-1,2){
                if(x+dx>=v.size() or y+dy>=v[x+dx].size())continue;
                if(x+dx<0 or y+dy<0)continue;
                if(v[x+dx][y+dy]==0)continue;
                if((++v[x+dx][y+dy])>9)q.push({x+dx,y+dy});
            }
        }
    }
}

void incrementLight(vc<vc<int>> &v,queue<ii> &q){
    rep(x,v.size()){
        rep(y,v[x].size()){
            if(++v[x][y]>9) q.push({x,y});
        }
    }
    exploreAll(v,q);
}




int main(){
    vc<vc<int>> v;
    string s;
    queue<ii> q;
    while(getline(cin,s)){
        vc<int> t;
        for(auto c:s){
            t.push_back(c-'0');
        }
        v.push_back(t);
    }
    
    int step=0; 
    while(res!=100){
        res=0;
        incrementLight(v,q);
        step++;
    }
    cout <<step<<endl;
}
