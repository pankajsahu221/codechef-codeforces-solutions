#include<bits/stdc++.h>
using namespace std;
int mpcost;
bool visited[100005];
vector<int>adj[100005];
int val[100005],res[100005];

void dfs(int curr){
    visited[curr]=true;
    mpcost+=val[curr];
    
    for(auto x:adj[curr]){
        
        if(!visited[x])
          dfs(x);
    }
}

int main(){
    memset(visited,false,sizeof(visited));
   int n,e,k;
   cin>>n>>e>>k;
   
   while(e--){
      int a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
   }
   
   for(int i=1; i<=n; i++){
       cin>>val[i];
   }
   int ph[40];
   for(int i=1; i<=k; i++){
       
      cin>>ph[i];
   }
   int phcost[40];
   for(int i=1; i<=k; i++){
      cin>>phcost[i];
   }
   int phown,bank;
   cin>>phown>>bank;
   
   while(phown--){
      int a;
      cin>>a;
      
      bank+=phcost[a];
   }
   memset(res,0,sizeof(res));
   for(int i=1; i<=n; i++){
      mpcost=0;
      memset(visited,false,sizeof(visited));
      dfs(i);
      res[i]=mpcost;
    // cout<<res[i]<<" ";  
   }
   int dp[k+1][bank+1];
   for(int i=0; i<k+1; i++)
      dp[i][0]=0;
      
    for(int i=0; i<bank+1; i++)
      dp[0][i]=0;    
        
   for(int i=1; i<k+1; i++){
      for(int j=1; j<bank+1; j++){
          
          if(phcost[i]<=j) dp[i][j]=max(res[ph[i]]+dp[i-1][j-phcost[i]], dp[i-1][j]);
          else dp[i][j]=dp[i-1][j];
      }
   }
   cout<<dp[k][bank];
   //cout<<bank;
   
   
}
