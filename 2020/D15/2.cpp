#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,n) for(ll i=0;i<n;i++)
#define fep(i,j,n) for(int i=j;i<n;i++)
typedef array<int,2> ii;
#define MOD 1000000007
int LSB(int x){return x&-x;}

#define MN 12
#define ML 3


struct MemoryGame
{
    vector<ll> starting_numbers;
    map<ll,ll> memo;
    ll currentStep;
    ll last;

    MemoryGame(vector<ll> start):starting_numbers{start}{
        currentStep=0;
        last=starting_numbers.front();
    }

    ll doTurnsForward(ll numStep){
        repl(i,numStep){
            nextTurn();
        }
        return lastVal();
    }

    ll lastVal(){
        return last;
    }

    void reset(){
        memo.clear();
        currentStep=0;
    }

    void nextTurn(){
        ll newLast=0;
        auto posInMemo=memo.find(last);
        if(posInMemo!=memo.end()){
            newLast=currentStep-posInMemo->second;
        }
        if(currentStep<starting_numbers.size()-1){
            newLast=starting_numbers[currentStep+1];
        }
        if(posInMemo==memo.end()) memo.insert({last,currentStep});
        else memo[posInMemo->first]=currentStep;
        currentStep++;
        last=newLast;
    }
};



void test(){
    MemoryGame test({0,3,6});
    assert(test.lastVal()==0);
    test.nextTurn();
    assert(test.lastVal()==3);
    test.nextTurn();
    assert(test.lastVal()==6);
    test.nextTurn();
    assert(test.lastVal()==0);
    test.nextTurn();
    assert(test.lastVal()==3);
    test.nextTurn();
    assert(test.lastVal()==3);
    test.nextTurn();
    assert(test.lastVal()==1);
    test.nextTurn();
    assert(test.lastVal()==0);
    test.nextTurn();
    assert(test.lastVal()==4);
    test.nextTurn();
    assert(test.lastVal()==0);
    test.nextTurn();
}

int main(){
    
    vector<ll> starting;
    string s;
    while(getline(cin,s,',')){
        starting.push_back(stol(s));
    }
    MemoryGame game(starting);
    cout <<game.doTurnsForward(30000000-1)<<endl ;

}
