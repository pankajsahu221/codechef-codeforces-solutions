//for great understanding of inversion http://pavelsimo.blogspot.com/2012/09/counting-inversions-in-array-using-BIT.html
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
ll t,n,bit[30020],arr[30020];

void update(ll idx,ll val){
    
    while(idx<=n){
        bit[idx]+=val;
        idx+=idx&(-idx);
    }
}

ll getSum(ll idx){
    ll sum=0;
    
    while(idx>0){
        sum+=bit[idx];
        idx-=idx&(-idx);
    }
    return sum;
}

int main(){
    cin>>t;
    
    while(t--){
        cin>>n;
        
        memset(bit,0,sizeof(bit));
        
        string s[n+9],temp;
        map<string ,ll > m;
        
        for(ll i=1; i<=n; i++){
             cin>>s[i];
        }
        for(ll i=1; i<=n; i++){
            cin>>temp;
            m[temp]=i;
        }
        for(ll i=1; i<=n; i++){
            arr[i]=m[s[i]];
        }
        ll cntinv=0;
        
        for(ll i=n; i>0; i--){
            cntinv+=getSum(arr[i]);
            update(arr[i],1);
        }
         cout<<cntinv<<endl;
        
    }
}
