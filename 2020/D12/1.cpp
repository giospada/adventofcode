#include <bits/stdc++.h>

 

using namespace std;

#define vtc vector
#define rep(i,n) for(int i=0;i<n;i++)

vtc<pair<char,int> > v;

int x,y,dire;

array<int,2> dir[]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0},
};


void print_pos(){printf("x:%d y:%d dir:%d \n", x,y,dire);}

int main(){
    string  s;
    while(getline(cin,s)){
        if(s.size()==1)break;
        v.push_back({s[0],stoi(s.substr(1,s.size()-1))});
    }
    x=0,y=0,dire=1;
 
    rep(i,v.size()){
        char m=v[i].first;
        int val=v[i].second;
        if(m=='L' or m=='R'){
            val/=90;
            if(m=='L')val*=-1;
            dire+=val;
            if(dire<0)dire+=4;
            dire%=4;
        }else{
            int lastd=dire;
            if(m=='N'){
                dire=0;
            }else if(m=='E'){        
                dire=1;
            }else if(m=='S'){        
                dire=2;
            }else if(m=='W'){        
                dire=3;
            }
            x+=val*dir[dire][0];
            y+=val*dir[dire][1];
            dire=lastd;
 
        }
        print_pos();
    }
    printf("%d\n",abs(x)+abs(y));
}
/*
#include <bits/stdc++.h>

using namespace std;
#define vtc vector
#define rep(i,n) for(int i=0;i<n;i++)
#define F first
#define S second

vector<pair<char,int>> v;

vtc<array<int,2>> dirc={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0},
};

int x,y,dir;



int main(){
    string s;
    while(getline(cin,s)){
        v.push_back({s[0],stoi(s.substr(1,s.size()-1))});
    }
    rep(i,v.size()){
        int gofor=0;
        char m=v[i].F;
        if(m=='R' or m=='L'){
            int add=v[i].S/90;
             
              
        }else{
            if(m=='N'){
                dir=1;
            }else if(m=='E'){
                dir=2;
            }else if(m=='S'){
                dir=3;
            }else if(m=='W'){
                dir=4;
            }
            gofor=v[i].S;
        }

    }

}
*/
