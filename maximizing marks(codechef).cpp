#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll n,t;
	
	cin>>n;
	cin>>t;
	
	ll arr[n+1][t+1];
	ll wt[n+1],val[n+1];
	ll dp[n+1][t+1];
	wt[0]=0;
	val[0]=0;
	
	for(ll i=1;i<=n;i++)
	    cin>>val[i];
	
	for(ll i=1;i<=n;i++)
	    cin>>wt[i];
	    
	for(ll i=0;i<=n;i++)
	{
	    for(ll j=0;j<=t;j++)
	    {
	        if(i==0||j==0)
	            {arr[i][j]=0;
	             dp[i][j]=0;}
	          
	        else
	        {     
	        if(j>=wt[i])
	            arr[i][j]=max(arr[i-1][j],val[i]+arr[i-1][j-wt[i]]);
	        else
	            arr[i][j]=arr[i-1][j];
	            
	        if(j>=wt[i])
	            {dp[i][j]=max(dp[i-1][j],val[i]+dp[i-1][j-wt[i]]);
	             dp[i][j]=max(dp[i][j],arr[i-1][j-wt[i]]+2*val[i]);}
	        else
	            dp[i][j]=dp[i-1][j];
	        }
	    }
	}
	
	cout<<dp[n][t]<<endl;
	return 0;
}
