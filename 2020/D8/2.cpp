#include <bits/stdc++.h>

using namespace std;


#define rep(i,n) for(int i=0;i<n;i++)
#define vtc vector
#define ay array

vtc<ay<int,2>> inp;
vtc<bool> done;
vtc<int> from;
vtc<vtc<ay<int,2>>> v;

//find next trova il prossimo jump o nop da una determinata posizione
int findNext(int from){
    for(int i=from;i<inp.size();i++)
        if(inp[i][0]!=2)return i;
    return -1;
}


int dfs(int c,int changed_node,int cost){
    if(done[c])return -1;
    done[c]=1;
    for(auto i:v[c]){
        if(i[0]==-1 and cost+i[1]==1){
            return ((i[1]==1)?c:changed_node);
        }else if(i[1]+cost<2){
            int r=dfs(i[0],(i[1]==1?c:changed_node),cost+i[1]);
            if(r!=-1)return r;
        }
    }
    done[c]=0;
    return -1;
}

int main(){
    map<string,int> ins={
        {"nop",0},
        {"jmp",1},
        {"acc",2}
    };

    //read input
    string s;
    while(cin >>s){
        int a;
        cin >>a;
        auto it=ins.find(s);
        if(it!=ins.end()){
            inp.push_back({it->second,a});
            done.push_back(0);
        }else{
            assert(true);
        }
    }

    v.resize(inp.size());
    rep(i,inp.size()){
        ay<int,2> tmp=inp[i];
        if(tmp[0]==2)continue;
        int jumpI=findNext(i+(tmp[1]));
        int nopI=findNext(i+1);
        v[i].push_back({nopI,tmp[0]});
        if(jumpI!=i) 
            v[i].push_back({jumpI,1-tmp[0]});
    }

    /**
    priority_queue<ay<int,2>> pq;
    pq.push({0,findNext(0)});
    int last=0;
    while(!pq.empty()){
        ay<int,2> tmp=pq.top();
        pq.pop();
        if(tmp[1]==-1){
            break;
        }
        if(-tmp[0]>=done[tmp[1]])continue;
        done[tmp[1]]=-tmp[0];
        for(auto t:v[tmp[1]]){
            if(t[0]==-1)
                pq.push({-t[1]+tmp[0],t[0]});
            else if(done[t[0]]>t[1]-tmp[0])
                pq.push({-t[1]+tmp[0],t[0]});
        }
    }
    dijikstra è implementato bene tranne trovare il nodo prima
    */
    int tochange=dfs(findNext(0),-1,0);
    inp[tochange][0]=1-inp[tochange][0];

    int reg=0;
    int index=0;
    while(index<inp.size()){
        switch(inp[index][0]){
            case 1:
                index+=inp[index][1]-1;
                break;
            case 2:
                reg+=inp[index][1];
                break;

        }
        index++;
    }
    printf("%d",reg);

}
