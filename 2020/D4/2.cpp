#include <bits/stdc++.h>


using namespace std;

map<string,int> all={
    {"byr",0},{"iyr",1},{"eyr",2},
    {"hgt",3},{"hcl",4},{"ecl",5},{"pid",6}};




void check(string v,bitset<7> &bi){
    auto it=all.find(v.substr(0,3));
    if(it!= all.end()){
        //0-2 :prefix
        //3 :separator ':'
        //value
        switch(it->second){
            case 0:
                int val=stoi(v.substr(3,v.size()-4));
                bi[0]|= (val>=1920 and val<=2002);
                break;
            case 1:
                bi[0]|= (val>=1920 and val<=2002);
                break;

        }

    }
}


vector<int> st;

int main(){
    int sol=0;
    string s;
    bitset<7> bi;
    while(getline(cin,s)){
        if(s==""){
            if(bi.all())
                sol++;
            bi.reset();
        }

        int lsp=0; 
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                check(s.substr(lsp,i-lsp),bi);
                lsp=i+1;
            }
        }
        check(s.substr(lsp,s.size()-1),bi);
    }

    printf("%d\n",sol);
}
