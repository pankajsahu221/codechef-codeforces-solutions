/*
Think of a particular element A[i]. After 1 round it becomes A[i-1] & A[i] & A[i+1].
After 2 rounds it becomes (A[i-2] & A[i-1] & A[i]) & (A[i-1] & A[i] & A[i+1]) & (A[i] & A[i+1] & A[i+2]) ,
which simplifies to A[i-2] & A[i-1] & A[i] & A[i+1] & A[i+2].
So you can see that after K rounds it becomes A[i-K] & A[i-K+1] & ... A[i] & ... A[i+K-1] & A[i+K]. 
Now this is a simple range query on a segment tree built on the array A.
Likewise you must query for each element in A to get the whole array after K rounds. Also remember that the array is cyclic,
so you may have to adjust your queries so that it works out.
*/

#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long
ll int a[23000],ans[20005],st[100005];
 
void build(int si,int ss,int se){
 
    if(ss==se){
        st[si]=a[ss];
        return;
    }
    int mid=(ss+se)/2;
    build(2*si,ss,mid);
    build(2*si+1,mid+1,se);
    st[si]=st[2*si]&st[2*si+1];
}
 
ll query(int si,int ss,int se,int qs,int qe){
    if(ss>se||qs>se||ss>qe)
        return 8589934591;
    if(qs<=ss&&qe>=se)
        return st[si];
    int mid=(ss+se)/2;
    
    return query(2*si,ss,mid,qs,qe)&query(2*si+1,mid+1,se,qs,qe);
}
 
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll int t,i,j,k,n;
 
    cin>>t;
    while(t--){
 
        cin>>n>>k;
        for(i=1;i<=n;++i){
            cin>>a[i];
        }
        build(1,1,n);
        for(i=1;i<=n;++i){
                if(i+k>n){
                    ans[i]=query(1,1,n,i,n);
                    ans[i]&=query(1,1,n,1,(i+k)%n);
                }
                else
                    ans[i]=query(1,1,n,i,(i+k));
                if(i-k<=0){
                    ans[i]&=query(1,1,n,1,i);
                    ans[i]&=query(1,1,n,n-k+i,n);
                }
                else
                    ans[i]&=query(1,1,n,i-k,i);
 
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
 
    return 0;
}
