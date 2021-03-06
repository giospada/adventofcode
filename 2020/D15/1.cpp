#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define fep(i,j,n) for(int i=j;i<n;i++)
typedef array<int,2> ii;
#define MOD 1000000007
int LSB(int x){return x&-x;}

#define MN 12
#define ML 3


struct MemoryGame
{
    vector<int> starting_numbers;
    map<int,int> memo;
    int currentStep;
    int last;

    MemoryGame(vector<int> start):starting_numbers{start}{
        currentStep=1;
        last=starting_numbers.front();
    }

    int doTurnsForward(int numStep){
        rep(i,numStep){
            nextTurn();
        }
        return lastVal();
    }

    int lastVal(){
        return last;
    }

    void reset(){
        memo.clear();
        currentStep=1;
    }

    void nextTurn(){
        int newLast=0;
        auto posInMemo=memo.find(last);
        if(posInMemo!=memo.end()){
            newLast=currentStep-posInMemo->first;
        }
        if(currentStep<starting_numbers.size()){
            newLast=starting_numbers[currentStep+1];
        }
        if(posInMemo!=memo.end()) memo.insert({last,currentStep});
        else memo[posInMemo->first]=currentStep;
        currentStep++;
        last=newLast;
    }
};




int main(){
    MemoryGame test({0,3,6});
    assert(test.lastVal()==0);
    test.nextTurn();
    assert(test.lastVal()==3);
    test.nextTurn();
    assert(test.lastVal()==6);
    test.nextTurn();
    assert(test.lastVal()==0);
    test.nextTurn();
    assert(test.lastVal()==5);
    test.nextTurn();

    return  0;
    int n;
    vector<int> starting;
    while(cin >>n){
        starting.push_back(n);
    }

    MemoryGame game(starting);
    cout <<game.doTurnsForward(2020)<<endl ;

}
