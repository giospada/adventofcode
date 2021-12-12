#include <bits/stdc++.h>

using namespace std;

vector<string> split(string q,string c){
    vector<string> res;
    size_t last=0;
    size_t next=-1;
    string sub;
    while((next=q.find(c,next+1))!=std::string::npos){
        sub=q.substr(last,next-last);
        res.push_back(sub); 
        last=next+c.size();
    }
    sub=q.substr(last,q.size()-last);
    res.push_back(sub);
    return res;
}



class DecodeDisplay{
protected:
    string getElementOnlyInA(string a,string b){
        int i=0,j=0; 
        string diff="";
        for(;i<a.size() and j<b.size();){
            if(a[i]==b[j]){
                i++;
                j++;
            }else if(a[i]<b[j]){
                diff+=a[i];
                i++;
            }else{
                j++;
            }
        } 
        while(j==b.size() and i<a.size()){
            diff+=a[i];
            i++;
        }
        return diff;
    }
    string removeChar(string my_str,char rem){
        my_str.erase(remove(my_str.begin(), my_str.end(), rem), my_str.end());
        return my_str;
    }
    map<char,char> decode;
    vector<string> all;
    vector<string> output;
    const map<string, int> todisp = {{"abcefg", 0}, {"cf", 1}, {"acdeg", 2}, {"acdfg", 3}, {"bcdf", 4}, {"abdfg", 5}, {"abdefg", 6}, {"acf", 7}, {"abcdefg", 8}, {"abcdfg", 9}};

public:
    DecodeDisplay(string s)
    {
        vector<string> f = split(s, " | ");
        all = split(f[0], " ");
        for (string &s : all)
            sort(s.begin(), s.end());
        sort(all.begin(), all.end(), [](const string &s1, const string &s2)
             { return s1.size() < s2.size(); });
        output = split(f[1], " ");
    }
    void searchSol()
    {
        int index[9];
        index[8]=9;
        index[1]=0;
        index[7]=1;
        index[4]=2;
        //prende 'a' sapendo che è la differenza tra 7 e 1
        char a= getElementOnlyInA(all[index[7]], all[index[1]])[0];
        decode.insert({a, 'a'});
        //capisce dov'è il tre perchè non ha differenze con 1
        for(int i=3;i<=5;i++){
            if(getElementOnlyInA(all[index[1]],all[i])==""){
                index[3]=i;
            }
        }
        //grazie al 3 ci ricaviamo b 
        char b=getElementOnlyInA(all[index[4]],all[index[3]])[0];
        decode.insert({b, 'b'});
        //ricviamo gli index 3 e 5
        for(int i=3;i<=5;i++){
            if(i==index[3])continue;
            int diff=getElementOnlyInA(all[index[4]],all[i]).size();
            if(diff==2)
                index[2]=i;
            else
                index[5]=i;
        }
        char c=getElementOnlyInA(all[index[1]],all[index[5]])[0];
        decode.insert({c,'c'});
    
        char d=removeChar(getElementOnlyInA(all[index[4]],all[index[1]]),b)[0];
        decode.insert({d,'d'});

        char e=getElementOnlyInA(all[index[2]],all[index[3]])[0];
        decode.insert({e,'e'});

        char f=getElementOnlyInA(all[index[1]],all[index[2]])[0];
        decode.insert({f,'f'});

        char g=removeChar(removeChar(getElementOnlyInA(all[index[2]],all[index[7]]),d),e)[0];
        decode.insert({g,'g'});
        
    }
    int calcOut()
    {
        int res=0;
        for(string a:output){
            string s="";
            for(char c:a){
                s+=decode[c];
            }
            sort(s.begin(),s.end());
            res*=10;
            res+=(todisp.at(s));
        }
        return res;
    }
};

int main()
{
    string s;
    int count=0;
    while (getline(cin, s))
    {
        DecodeDisplay display(s);
        display.searchSol();
        count+= display.calcOut();
    }
    cout << count << endl;
}