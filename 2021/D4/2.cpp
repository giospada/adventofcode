
#include <iostream>
#include <vector>
#include <set>

#define ROWBOARD 5


using namespace std;

typedef long  long ll;

struct Board{
private:
    void ereseFromArray(multiset<int> tmp[ROWBOARD],int val){
        int count;
        for(int i=0;i<ROWBOARD;i++){
            if((count=tmp[i].count(val))!=0){
                erase+=count*val;
                tmp[i].erase(val);
                if(tmp[i].size()==0){
                    done=true;
                }
            }
        }
    }
    
public:
    ll tot=0;
    ll erase=0;
    multiset<int> row[ROWBOARD]; 
    multiset<int> col[ROWBOARD]; 
    bool done=false; 
    void insert(int x,int y,int value){
        row[x].insert(value);
        col[y].insert(value);
        tot+=value;
    }
    

    bool eraseVal(int val){
        ereseFromArray(row,val);
        ereseFromArray(col,val);
        return done;
    }
};

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


int  main(){
    vector<int> v;
    string q;
    getline(cin,q);
    vector<int> query=split(q,',');
    vector<Board> board; 

    int x=0,y=0,n;

    while(cin >>n){
        if(x==0 and y==0)board.emplace_back();
        board.back().insert(x,y,n);
        x++;
        if(x>=ROWBOARD)x=0,y++;
        if(y>=ROWBOARD){
            y=0;
        }
    }
    int cBoard=0;
    for(int q:query){
        for(auto &i:board){
            if(i.done)continue;
            if(i.eraseVal(q)){
                cBoard++;
                if(cBoard==board.size()){
                    cout <<(i.tot-(i.erase/2))*q<<endl;
                }
            }
        }
    }
}
