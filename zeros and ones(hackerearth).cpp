/*
Since value of each array node can be 0 or 1, so for non-leaf node of a Segment tree, 
its value denotes how many array elements in that range have value 1.
So, for non-leaf node if value is greater than k then it means kth index lies in left sub-tree.
*/
#include<bits/stdc++.h>
using namespace std;
int st[4000010];
int n,Q;

void built(int si,int ss,int se){
    if(ss==se){
        st[si]=1;
        return;
    }
    int mid=(ss+se)/2;
    built(2*si,ss,mid);
    built(2*si+1,mid+1,se);
    st[si]=st[2*si]+st[2*si+1];
}

void update(int si,int ss,int se,int idx){
    if(ss==se && ss==idx){
        st[si]=0;
        return;
    }
    
   int mid=(ss+se)/2;
   if(idx<=mid && idx>=ss)
      update(2*si,ss,mid,idx);
   else 
      update(2*si+1,mid+1,se,idx);
      
   st[si]=st[2*si]+st[2*si+1];
}

int query(int si,int ss,int se,int k){
    if (ss < 1 || se > n || st[si] < k) {
		return -1;
	}
    if(ss==se && k==1){
        return ss;
    }
    int mid=(ss+se)/2;
    if(k>st[2*si]){
        return query(2*si+1,mid+1,se,k-st[2*si]);
    }
    else{
        return query(2*si,ss,mid,k);
    }
}


int main(){
    cin>>n;
    
    built(1,1,n);
    cin>>Q;
    for(int i=0; i<Q; i++){
        int bp;
        cin>>bp;
        
        if(bp){
            int k;
            cin>>k;
            cout<<query(1,1,n,k)<<"\n"; 
        }
        else{
            int idx;
            cin>>idx;
            update(1,1,n,idx);
        }
    }
    
}
