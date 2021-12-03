#include <iostream>
#include <string>

using namespace std;


int main(){
    string s;
    int n;
    int x=0,y=0;
    while(cin >>s>>n){
        if(s.compare("up")==0)
            y-=n;
        if(s.compare( "down")==0)
            y+=n;
        if(s.compare("forward")==0)
            x+=n;
    }
    cout <<x*y<<endl;
}
