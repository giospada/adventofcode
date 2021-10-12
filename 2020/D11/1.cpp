#include <bits/stdc++.h>

using namespace std;
#define vtc vector
#define rep(i,n) for(int i=0;i<n;i++)
//for strick the time of execution we can use a precalculed value 
// 3 2 0 0 0 0 
// 2 2 0 0 0 0 
// 0 0 0 0 0 0 

vtc<vtc<int>> st[2];
vtc<vtc<int>> gs;

int h=0;
int w=0; 


// you cand do it in two ways one is with precomputed sum
// the other with check evrey cell near it
int sumAdj(int xp,int yp,int s){
    int sum=0;
    for(int x=max(xp-1,0);x<=min(xp+1,w-1);x++)
        for(int y=max(yp-1,0);y<=min(yp+1,h-1);y++)
            sum+=st[s][x][y];
    return sum;
}
//    the alterative with precomputed sum look like this
//    int ym=min(y+1,w+1),xm=min(x+1,h-1);
//    int a=(x==0||y==0)?0:st[s][x-1][y-1];
//    int b=(x==0)?0:st[s][x-1][y-1];
//    int c=(y==0)?;
//    int d=st[s][][];
//    return d-b-c+a;
//

void debug_arr(int cs){
    rep(i,st[cs].size()){
        rep(j,st[cs][i].size()){
            printf("%c",(st[cs][i][j]==0)?'.':'#'); 
        }
        printf("\n");
    }
    printf("----------------------\n");
}


bool step(int cs){ 
    int ns=1-cs;
    bool ch=0;
    for(int x=0;x<w;x++)
        for(int y=0;y<h;y++){
            if(gs[x][y])continue;
            int adj=sumAdj(x,y,cs);
            if(adj==0){
                st[ns][x][y]=1;
                ch=1;
            }else if(st[cs][x][y]==1 && adj-1>=4){
                st[ns][x][y]=0;
                ch=1;
            }else
                st[ns][x][y]=st[cs][x][y];
        }

    //debug_arr(ns);

    return ch;
}



int main(){
    string s;
    while(getline(cin,s)){
        h=s.size();
        gs.push_back({});
        for(char c:s){
            gs[w].push_back((c=='.')?1:0);
        }
        w++;
    }
    st[0].resize(w);
    rep(i,w)st[0][i].resize(h); 

    st[1].resize(w);
    rep(i,w)st[1][i].resize(h); 

    bool ch=1;
    int cs=0;
    while(ch){
        ch=step(cs);
        cs=1-cs;
    }
    
    int sum=0;
    rep(i,st[1].size()){
        rep(j,st[1][i].size()){
            sum+=st[1][i][j]; 
        }
    }
    printf("%d",sum);
}
