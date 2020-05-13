#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n,m,k;
	cin>>n>>m>>k;
	long long int ing[n],p[n];
	for(int i=0;i<n;i++){
		cin>>ing[i]>>p[i];
	}
	long long int dp[m+1]={0};
	for(int i=0;i<=m;i++){
		for(int j=0;j<n;j++){
			if(i>=p[j]){
				dp[i]=max(dp[i],dp[i-p[j]]+ing[j]);
			}
		}
	}
	long long int ans=dp[m];
	if(k<=ans) cout<<"YES"<<" "<<ans;
	else cout<<"NO"; 
}