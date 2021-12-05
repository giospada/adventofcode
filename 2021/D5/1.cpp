#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

struct Segment{
    int x,y,l;
    Segment(int x,int y,int l): l(l),x(x),y(y) {}
};

int main(){
    int x1,x2,y1,y2;
    string s;
    int res;
    vector<Segment> v,o;

    while(getline(cin,s)){
        sscanf(s.c_str(),"%d,%d -> %d,%d",&x1,&x2,&y1,&y2);
        if(x1==x2){ 
            o.emplace_back({x1,min(y1,y2),abs(y1-y2)}); 
        }
        if(y1==y2){
            v.emplace_back({min(x1,x2),y1,abs(x1-x2)}); 
        }
    }
    sort(o.begin(),o.end(),[](Segment s,Segment s1){if(s.x==s1.x){return s.x<s1.x}else{return s.y<s1.y}});
    sort(v.begin(),v.end(),[](Segment s,Segment s1){if(s.y==s1.y){return s.y<s1.y}else{return s.x<s1.x}});
    priority_queue<int> pq;

    cout <<res;
}
