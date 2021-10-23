#include <bits/stdc++.h>

using namespace std;


#define rep(i,n) for(int i=0;i<n;i++)
#define vtc vector
#define ay array

vtc<ay<int,2>> inp;
vtc<bool> done;

//next jup or not
vtc<int> nextJN;



int find(int n){
    if(uf[n]==n)return n;
    else uf[n]=find(uf[n]);
}

int marge(int a,int b){
    a=find(a);
    b=find(b);
    uf[a]=b;
}

int nextJmpNop(int from){

}


int main(){
    map<string,int> ins={
        {"nop",0},
        {"jmp",1},
        {"acc",2}
    };

    //read input
    
    int riga=0;
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

    for(int i=0;i<inp.size();i++){
        if(inp[i][0]=="nop" or inp[i][0]=="jmp"){
            
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
