//rod cutting problem is same as unbounded knapsack problem.
#include<bits/stdc++.h>
using namespace std;

int perf(int val[],int wt[],int n){
    int dp[n+1][n+1];
    
    for(int i=0; i<n+1; i++)
      dp[0][i]=0;
    for(int i=0; i<n+1; i++)
      dp[i][0]=0;
      
    for(int i=1; i<n+1; i++){
       for(int j=1; j<n+1; j++){
          
          if(wt[i-1]<=j) dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]], dp[i-1][j]);
          else dp[i][j]=dp[i-1][j];
       }
    }
    return dp[n][n];
}

int main(){
    int n;
    cin>>n;
    
    int wt[n],val[n];
    for(int i=0; i<n; i++) cin>>wt[i];
    for(int i=0; i<n; i++) cin>>val[i];
    
    cout<<perf(val,wt,n);
}
