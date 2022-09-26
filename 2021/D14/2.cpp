 #include <bits/stdc++.h>

using namespace std;

#define MAXN 26
#define rep(i,n) for(int i=0;i<n;i++)

typedef  long long ll;

vector<int> v[MAXN*MAXN];
ll freq[MAXN];

int calcVal(char a,char b){
    int vala=a-'A';
    int valb=b-'A';
    return MAXN*valb+vala;  
}
void printVal(int k){
    char a='A'+k%MAXN;
    k-=k%MAXN;
    char b='A'+k/MAXN;
    cout <<a<<b; 
}
int getSecondLetter(int k){
    k-=k%MAXN;
    int b=k/MAXN;
    return b;
}

int calcNext(vector<ll> status[2],int tc){
    //toglie quelli che non sono più riconducibili ad altri
    int curr=tc%2;
    rep(i,status[curr].size()){
        if(status[curr][i]!=0){
//            printVal(i);
 //           cout <<endl;
            if(v[i].size()==0){
                freq[getSecondLetter(i)]+=status[curr][i];      
            }else{
                status[1-curr][v[i][0]]+=status[curr][i];
                status[1-curr][v[i][1]]+=status[curr][i];
            }
            status[curr][i]=0;
        }
    }
}

int main(){
    string init_s;
    getline(cin,init_s);
    string s;
    while(getline(cin,s)){
        if(s=="")continue;
        int cur=calcVal(s[0],s[1]);
        v[cur].push_back(calcVal(s[0],s[6]));
        v[cur].push_back(calcVal(s[6],s[1]));
    }
    vector<ll> status[2]={vector<ll>(MAXN*MAXN,0),vector<ll>(MAXN*MAXN,0)}; 
    for(int i=1;i<init_s.size();i++){
        status[0][calcVal(init_s[i-1],init_s[i])]++;
    }
    freq[init_s[0]-'A']++;
    rep(tc,40){
        calcNext(status,tc);
    }
    rep(i,2)rep(j,status[i].size())freq[getSecondLetter(j)]+=status[i][j];
    ll ma=LLONG_MIN;
    ll mi=LLONG_MAX;
    rep(i,MAXN){
        if(freq[i]!=0){
            cout <<(char)(i+'A')<<":"<<freq[i]<<endl;
            ma=max(freq[i],ma);
            mi=min(freq[i],mi);
        }
    }
    cout <<ma-mi<<endl;
}
