#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int n,Q,arr[500005];
int st[2000020],st2[2000020];
 
int count(int num){
    int sum=0;
    
    while(num){
        if(num&1) sum++;
        num=num>>1;
    }
    return sum;
}
 
void built(int si,int ss,int se){
    if(ss==se){
        st[si]=arr[ss];
        st2[si]=count(arr[ss]);
        return;
    }
    int mid=(ss+se)/2;
    built(2*si,ss,mid);
    built(2*si+1,mid+1,se);
    st[si]=st[2*si]+st[2*si+1];
    st2[si]=st2[2*si]+st2[2*si+1];
}
 
void update1(int si,int ss,int se,int idx,int a){
    if(ss<1 || se>n || ss>se) return;
    if(ss==se && a==1){
      st[si]=2*st[si] + 1;
      st2[si]=count(st[si]);
      return;
    }
    if(ss==se && a==2){
      st[si]=floor(st[si]/2);
      st2[si]=count(st[si]);
      return;
    }
    else{
       int mid=(ss+se)/2;
       if(ss<=idx && mid>=idx)  update1(2*si,ss,mid,idx,a);
       else  update1(2*si+1,mid+1,se,idx,a);
       st[si]=st[2*si]+st[2*si+1];
       st2[si]=st2[2*si]+st2[2*si+1];
    }
    return;
}
 
int query(int si,int ss,int se,int qs,int qe){    //to get the total no. of 1s.
    if(qs>se || qe<ss) return 0;
    if(qs<=ss && qe>=se) return st2[si];
    int mid=(ss+se)/2;
    
    return query(2*si,ss,mid,qs,qe)+query(2*si+1,mid+1,se,qs,qe);
}
 
int main(){
    cin>>n>>Q;
    for(int i=1; i<=n; i++) arr[i]=0;
    
    built(1,1,n);
   // built2(1,1,n);
    
    while(Q--){
        int a;
        cin>>a;
        
        if(a==1){
            int idx;
            cin>>idx;
            
            update1(1,1,n,idx,a);
        }
        else if(a==2){
            int idx;
            cin>>idx;
            
            update1(1,1,n,idx,a);
        }
        else{
            int x,y;
            cin>>x>>y;
            
            cout<<query(1,1,n,x,y)<<endl;
            
        }
    }
    
}
