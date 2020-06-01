#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n" 
ll n,k;
vector<ll>adj[200002];
vector<ll>dist;
bool vis[200002];

ll dfs(int start,int dis){
    vis[start]=true;
    ll subtreesize=0;
    
    for(auto x:adj[start]){
        if(!vis[x]){
           subtreesize+=dfs(x,dis+1); 
        }
    }
    dist.push_back(dis-subtreesize);
    return subtreesize+1;
}

int main(){
    cin>>n>>k;
    
    memset(vis,false,sizeof(vis));
    
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    sort(dist.begin(),dist.end(),greater<ll>());
    ll ans=0,pos=0;
    while(k--){
        ans+=dist[pos];
        pos++;
    }
    cout<<ans<<endl;
    return 0;
}
