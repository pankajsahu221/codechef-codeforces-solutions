#include<bits/stdc++.h>
using namespace std;
int n,W,val[610],wt[610],maxi=0;
vector<int> adj[610];
vector<int> modi;
bool visited[610];


int knapsack(vector<int> modi){
    int dp[610][W+1];
    
    for(int i=0; i<modi.size()+1; i++){
       for(int j=0; j<W+1; j++){
           
           if(i==0 || j==0) dp[i][j]=0;
           else if(wt[modi[i-1]]<=j) dp[i][j]=max(val[modi[i-1]]+ dp[i-1][j-wt[modi[i-1]]], dp[i-1][j]);
           else dp[i][j]=dp[i-1][j];
       }
    }
    return dp[modi.size()][W];
}

void dfs(int curr){
    visited[curr]=true;
    modi.push_back(curr);
    int leaf=1;
    
    for(auto x:adj[curr]){
        if(!visited[x]){
            leaf=0;
            dfs(x);
        }
    }
    if(leaf==1)    //if there is a leaf node then we calculate the max in the knapsack
       maxi=max(maxi,knapsack(modi));
    
    modi.pop_back();
}

int main(){
    cin>>n;
    
    for(int i=0; i<n-1; i++){
       int a,b;
       cin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a);
    }
    for(int i=1; i<n+1; i++) cin>>val[i];
    for(int i=1; i<n+1; i++) cin>>wt[i];
    
    cin>>W;
    
    memset(visited,false,sizeof(visited));
    dfs(1);
    cout<<maxi;
    
    return 0;
}