#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int arr[100009],n,Q;
vector<int>st[400009];
vector<pair<int,int>>arr1;

void built(int si,int ss,int se){
    if(ss==se){
        st[si].push_back(arr1[ss-1].second);   //here arr1[ss-1],because vector(arr1) started from 0 and array(arr) from 1
        return;
    }
    int mid=(ss+se)/2;
    built(2*si,ss,mid);
    built(2*si+1,mid+1,se);
    merge(st[2*si].begin(),st[2*si].end(),st[2*si+1].begin(),st[2*si+1].end(),back_inserter(st[si]));
}

int query(int si,int ss,int se,int qs,int qe,int k){
    if(ss==se) return st[si][0];  //we can also use st[si].back();
    int mid=(ss+se)/2;
    int m=(upper_bound(st[2*si].begin(),st[2*si].end(),qe)-st[2*si].begin())
            -(lower_bound(st[2*si].begin(),st[2*si].end(),qs)-st[2*si].begin());
    
    if(m>=k) return query(2*si,ss,mid,qs,qe,k);
    else return query(2*si+1,mid+1,se,qs,qe,k-m);
}

int main(){
    
    scanf("%d%d",&n,&Q);
    for(int i=1; i<=n; i++){
        scanf("%d",&arr[i]);
        arr1.push_back(make_pair(arr[i],i));
    }
    sort(arr1.begin(),arr1.end());
    built(1,1,n);
    while(Q--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        
        int ans=query(1,1,n,a,b,c);
        printf("%d\n",arr[ans]);  
    }
    
}
