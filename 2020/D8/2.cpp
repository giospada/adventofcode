#include <bits/stdc++.h>

using namespace std;


#define rep(i,n) for(int i=0;i<n;i++)
#define vtc vector
#define ay array

vtc<ay<int,2>> inp;
vtc<bool> done;


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


    //emulte mashine
    int reg=0;
    int index=0;
    while(not done[index]){
        done[index]=1;
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
