#include <bits/stdc++.h>


#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

#define ML 25
int inp[ML];

int main(){
    map<int,int> last;
    rep(i,ML){
        scanf("%d",inp+i);
        last[inp[i]]=i;
    }
    int i=ML;
    int a;
    while(EOF!=scanf("%d",&a)){
        bool found=0;
        rep(j,ML){
            int sub=a-inp[j];
            if(last.find(sub)!=last.end() and last[sub]>=i-ML){
                found=1;
                break;
            }
        }
        if(!found){
            printf("%d",a);
            return 0;
        }
        inp[i%ML]=a;
        last[a]=i;
        i++; 
    }

}
