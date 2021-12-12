#include <bits/stdc++.h>


using namespace std;

const int MAXDAYS=9;

int state[MAXDAYS];


int calculateFish(){
    int zero=state[0];
    for(int i=1;i<MAXDAYS;i++){
        state[i-1]=state[i];
    }
    state[MAXDAYS-1]=zero;
    state[MAXDAYS-3]+=zero;
    return zero;

}
vector<int> split(string q,char c){
    vector<int> res;
    size_t last=0;
    size_t next=-1;
    string sub;
    while((next=q.find(c,next+1))!=std::string::npos){
        sub=q.substr(last,next-last);
        res.push_back(stoi(sub)); 
        last=next+1;
    }
    sub=q.substr(last,next-last);
    res.push_back(stoi(sub));
    return res;
}

int main(){
    string s;
    int numFish = 0;
    while (getline(cin, s))
    {
        for (auto &c : split(s, ','))
        {

            state[c]++;
            numFish++;
        }
    }
    for (int i = 0; i < 80; i++)
    {
        numFish += calculateFish();
    }
    cout << numFish;
}