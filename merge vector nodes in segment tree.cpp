//This is the fine and easy solution but it's giving tle...(don't know how to fix)..
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int arr[100009],n,Q;
vector<int>st[400009];

vector<int>mergee(vector<int>v1,vector<int>v2){
    vector<int>v;
    int i=0,j=0;

    while(i<v1.size() && j<v2.size()){
        if(v1[i]<=v2[j]){
            v.push_back(v1[i]);
            i++;
        }
        else{
            v.push_back(v2[j]);
            j++;
        }
    }
    for(int k=i; k<v1.size(); k++) v.push_back(v1[k]);
    for(int k=j; k<v2.size(); k++) v.push_back(v2[k]);

    return v;
}

void built(int si,int ss,int se){
    if(ss==se){
        st[si].push_back(arr[ss]);
        return;
    }
    int mid=(ss+se)/2;
    built(2*si,ss,mid);
    built(2*si+1,mid+1,se);
    st[si]=mergee(st[2*si],st[2*si+1]);
}

vector<int>query(int si,int ss,int se,int qs,int qe){
    vector<int>ans;
    if(qs>se || qe<ss) return ans;
    if(qs<=ss && qe>=se) return st[si];

    int mid=(ss+se)/2;
    return mergee(query(2*si,ss,mid,qs,qe),query(2*si+1,mid+1,se,qs,qe));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cin>>n>>Q;
    scanf("%d%d",&n,&Q);
    for(int i=1; i<=n; i++){
        scanf("%d",&arr[i]);  //cin>>arr[i];
    }
    built(1,1,n);
    while(Q--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);   //cin>>a>>b>>c;

        c--;
        vector<int>v=query(1,1,n,a,b); //by performing the query,we will get the merged vector
      //  for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
        //cout<<endl;
        printf("%d\n",v[c]);   //cout<<v[c]<<endl;
    }

}
