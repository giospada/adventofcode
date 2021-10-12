#include <bits/stdc++.h>

 

using namespace std;

#define vtc vector
#define rep(i,n) for(int i=0;i<n;i++)

vtc<pair<char,int> > v;

int x,y,wx,wy;

/* x=1 y=2 
 * rotate 
 * x=-2 y=1
 * rotate 
 * x=-1 y=-2
 * rotate 
 * x=2 y=-1
 * rotate
 * x=1 y=2
 *
 */


void print_pos(){printf("x:%d y:%d wx:%d wy:%d \n", x,y,wx,wy);}


int main(){
    string  s;
    while(getline(cin,s)){
        if(s.size()==1)break;
        v.push_back({s[0],stoi(s.substr(1,s.size()-1))});
    }
    x=0,y=0,wy=1,wx=10; 
 
    rep(i,v.size()){
        char m=v[i].first;
        int val=v[i].second;
        if(m=='L' or m=='R'){
            val/=90;
            rep(i,val)
                if(m=='L'){
                    int t=wx;
                    wx=wy*-1;
                    wy=t;
                }else if(m=='R'){
                    int t=wy;
                    wy=wx*-1;
                    wx=t;
                }


        }else{
            if(m=='N'){
                wy+=val;                
            }else if(m=='E'){        
                wx+=val;                
            }else if(m=='S'){        
                wy-=val;                
            }else if(m=='W'){        
                wx-=val;                
            }else if(m=='F'){
                x+=wx*val;
                y+=wy*val;
            }
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
