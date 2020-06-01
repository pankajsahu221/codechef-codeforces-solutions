//for more clear explanation refer to the link.  https://www.geeksforgeeks.org/maximum-subarray-sum-given-range/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
int n,m,arr[100006];

struct Node{
    int presum,sufsum,totsum,subsum;

    void mergee(Node l,Node r){
     
      presum=max(l.presum, l.totsum+r.presum);
    
      sufsum=max(r.sufsum, r.totsum+l.sufsum);
      
      totsum=l.totsum+r.totsum;
    
      subsum=max({ sufsum , presum,l.subsum , r.subsum,l.sufsum+r.presum });
      
    }
}st[400020];

void built(int si,int ss,int se){
    if(ss>se) return;
    if(ss==se){
        st[si].presum=st[si].totsum=st[si].sufsum=st[si].subsum=arr[ss];
        return;
    }
    int mid=(ss+se)/2;
    built(2*si,ss,mid);
    built(2*si+1,mid+1,se);
    st[si].mergee(st[2*si],st[2*si+1]);
}

Node query(int si,int ss,int se,int qs,int qe){
    Node ans;
    ans.presum=ans.subsum=ans.sufsum=ans.totsum=INT_MIN;
    if(qs>se || qe<ss || ss>se) return ans;
    if(qs<=ss && qe>=se ){
        return st[si];
    }
    int mid=(ss+se)/2;
    if(qs>mid) return query(2*si+1,mid+1,se,qs,qe);
    if(qe<=mid) return query(2*si,ss,mid,qs,qe);
    ans.mergee(query(2*si,ss,mid,qs,qe),query(2*si+1,mid+1,se,qs,qe));
    return ans;
}

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
    
    built(1,1,n);
    scanf("%d",&m);
    
    int a,b;
    for(int p=0; p<m; p++){
        
        scanf("%d%d",&a,&b);
        
        printf("%d\n",query(1,1,n,a,b).subsum);
    }
}
