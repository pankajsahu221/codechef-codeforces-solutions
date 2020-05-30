#include<bits/stdc++.h>
using namespace std;
int arr[100009],n,Q;

struct Node{
    int max1,max2;
    void merge(Node l,Node r){
        
        max1=max(l.max1,r.max1);
        if(l.max1==max1)
           max2=max(l.max2,r.max1);
           
        else
           max2=max(l.max1,r.max2);
    }
}st[400040];

void built(int si,int ss,int se){
    if(ss==se){
        st[si].max1=arr[ss];
        st[si].max2=0;
        return;
    }
    int mid=(ss+se)/2;
    built(2*si,ss,mid);
    built(2*si+1,mid+1,se);
    st[si].merge(st[2*si],st[2*si+1]);
}

void update(int si,int ss,int se,int idx,int val){
    if(ss==se){
        st[si].max1=val;
        st[si].max2=0;
        return;
    }
    else{
        int mid=(ss+se)/2;
        if(idx<=mid) update(2*si,ss,mid,idx,val);
        else update(2*si+1,mid+1,se,idx,val);
        
        st[si].merge(st[2*si],st[2*si+1]);
    }
}

Node query(int si,int ss,int se,int qs,int qe){
    Node ans;
    ans.max1=0;  ans.max2=0;
    if(ss>qe || qs>se) return ans;
    if(qs<=ss && qe>=se) return st[si];
    
    int mid=(ss+se)/2;
    ans.merge(query(2*si,ss,mid,qs,qe),query(2*si+1,mid+1,se,qs,qe));
    return ans;
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    built(1,1,n);
    cin>>Q;
    while(Q--){
        char s;
        cin>>s;
        
        int a,b;
        cin>>a>>b;
        
        if(s=='Q'){
            Node ans=query(1,1,n,a,b);
            cout<<ans.max1+ans.max2<<endl;
        }
        else{
           update(1,1,n,a,b); 
        }
    }
    
}
