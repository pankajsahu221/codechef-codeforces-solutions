#include<bits/stdc++.h>
#define MAX 1000008
using namespace std;
typedef long long ll;
ll t,n,m,arr[MAX]  = {0},tree[4*MAX] = {0},lazy[4*MAX] = {0}; // To store pending updates 


void updateRangeUtil(ll si, ll ss, ll se, ll us, 
					ll ue, ll diff) 
{ 
	if (lazy[si] != 0) 
	{ 
		tree[si] += (se-ss+1)*lazy[si]; 

		if (ss != se) 
		{ 
			lazy[si*2 + 1] += lazy[si]; 
			lazy[si*2 + 2] += lazy[si]; 
		} 

		lazy[si] = 0; 
	} 

	// out of range 
	if (ss>se || ss>ue || se<us) 
		return ; 

	if (ss>=us && se<=ue) 
	{ 
		tree[si] += (se-ss+1)*diff; 

		if (ss != se) 
		{ 
			lazy[si*2 + 1] += diff; 
			lazy[si*2 + 2] += diff; 
		} 
		return; 
	} 

	ll mid = (ss+se)/2; 
	updateRangeUtil(si*2+1, ss, mid, us, ue, diff); 
	updateRangeUtil(si*2+2, mid+1, se, us, ue, diff); 

	tree[si] = tree[si*2+1] + tree[si*2+2]; 
} 

void updateRange(ll n, ll us, ll ue, ll diff) 
{ 
updateRangeUtil(0, 0, n-1, us, ue, diff); 
} 

ll getSumUtil(ll ss, ll se, ll qs, ll qe, ll si) 
{ 
	if (lazy[si] != 0) 
	{ 
		tree[si] += (se-ss+1)*lazy[si]; 

		if (ss != se) 
		{ 
			lazy[si*2+1] += lazy[si]; 
			lazy[si*2+2] += lazy[si]; 
		} 

		lazy[si] = 0; 
	} 

	// Out of range 
	if (ss>se || ss>qe || se<qs) 
		return 0; 

	if (ss>=qs && se<=qe) 
		return tree[si]; 

	ll mid = (ss + se)/2; 
	return getSumUtil(ss, mid, qs, qe, 2*si+1) + 
		getSumUtil(mid+1, se, qs, qe, 2*si+2); 
} 

ll getSum(ll n, ll qs, ll qe) 
{ 
	// Check for erroneous input values 
	if (qs < 0 || qe > n-1 || qs > qe) 
	{ 
		return -1; 
	} 

	return getSumUtil(0, n-1, qs, qe, 0); 
} 

void constructSTUtil( ll ss, ll se, ll si) 
{ 
	if (ss > se) 
		return ; 

	if (ss == se) 
	{ 
		tree[si] = arr[ss]; 
		return; 
	} 

	ll mid = (ss + se)/2; 
	constructSTUtil(ss, mid, si*2+1); 
	constructSTUtil( mid+1, se, si*2+2); 

	tree[si] = tree[si*2 + 1] + tree[si*2 + 2]; 
} 


int main() 
{ 
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
     
     memset(arr,0,sizeof(arr));
     memset(tree,0,sizeof(tree));
     memset(lazy,0,sizeof(lazy));
		constructSTUtil(0, n-1, 0);
		
      for(ll i=0; i<m; i++){
          ll a;
          scanf("%lld",&a);
          
          if(a==1){
              ll p,q;
              scanf("%lld%lld",&p,&q);
              p--; q--;
              
              printf("%lld\n",getSum(n,p,q));
          }
          else{
              ll p,q,val;
              scanf("%lld%lld%lld",&p,&q,&val);
              p--; q--;
              updateRange(n,p,q,val);
          }
      }
      
	//	getSum(n, 1, 3)); 
	//    updateRange(n, 1, 5, 10);
	//		getSum( n, 1, 3); 

   }
	return 0; 
} 

