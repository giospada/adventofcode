#include <bits/stdc++.h>

using namespace std;


int main() {
    int sliding=3;
    queue<int> q;
    int last=INT_MAX;
    int cur=0;
    int n;
    int res=0;
    while(cin >>n){
        cur+=n;
        q.push(n);
        if(q.size()==sliding) {
            if(cur>last)
                res++;
            last=cur;
            cur-=q.front();
            q.pop();
        }
    }
    cout <<res<<endl;
}
