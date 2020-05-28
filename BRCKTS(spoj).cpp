#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long 
ll arr[30005],n,Q;

struct Node{
    int sum,minsum;
}st[120020];

void built(int si,int ss,int se){
    if(ss==se){
        st[si].sum=st[si].minsum=arr[ss];
        return;
    }
    int mid=(ss+se)/2;
    built(2*si,ss,mid);
    built(2*si+1,mid+1,se);
    st[si].sum=st[2*si].sum+st[2*si+1].sum;
    st[si].minsum=min(st[2*si].minsum, st[2*si].sum+st[2*si+1].minsum);
}

void update(int si,int ss,int se,int idx){
    if(ss==se){
        arr[ss]=-arr[ss];
        st[si].sum=st[si].minsum=arr[ss];
        
    }
    else{
        int mid=(ss+se)/2;
        if(idx>=ss && idx<=mid) update(2*si,ss,mid,idx);
        else update(2*si+1,mid+1,se,idx);
        st[si].sum=st[2*si].sum+st[2*si+1].sum;
        st[si].minsum=min(st[2*si].minsum, st[2*si].sum+st[2*si+1].minsum);
    }
}


int main(){
    int t=10,tr=1;
    
    while(t--){
        scanf("%lld",&n);
        ll j=1;
        for(int i=0; i<n; i++){
            char s;
           scanf(" %c",&s);
            if(s=='(') arr[j]=1;
            else arr[j]=-1;
            j++;
        }
        built(1,1,n);
        scanf("%lld",&Q);
        printf("Test %d:\n", tr++);
        
        while(Q--){
            int idx;
            scanf("%d",&idx);
            
            
            if(idx==0){
                
                if(!st[1].sum && !st[1].minsum) printf("YES\n");
                else printf("NO\n");
            }
            else{
                update(1,1,n,idx);
            }
        }
        
    }
    return 0;
}
