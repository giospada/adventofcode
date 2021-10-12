#include <bits/stdc++.h>

#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;


int ans=217430975;
vector<ll> arr;


int main(){
    int n=0,a;
    while(EOF!=scanf("%d",&a)){
        arr.push_back(a);
        n++;
    }
    int j=0;
    int sum=0;
    for(int i=0;i<n;i++){
        while(sum<ans&&j<n){
            sum+=arr[j];
            j++;
        }
        if(sum==ans&&j-i>2){
            ll mi=LONG_MAX;
            ll ma=0;
            for(int k=i;k<j;k++){
                mi=min(mi,arr[k]);
                ma=max(ma,arr[k]);
            }
            printf("%lld\n",mi+ma);
            printf("%lld %lld\n",mi,ma);
            printf("%d %d\n",i,j);
            printf("%lld %lld\n",arr[i],arr[j-1]);
        }
        sum-=arr[i];
    }

}
