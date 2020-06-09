//here is one more solution 
#include<bits/stdc++.h>
#define max 100000
#define mod 1000000007
typedef long long int ll;
using namespace std;
int main() {
	int t,p,q,r,n1,n2,a[max],b[max],c[max],bx;ll sum,s1,s2,s11,s12;
	scanf("%d",&t);
 
	while (t--) {
		sum=0;s1=0;s2=0;n1=0;n2=0;
		scanf("%d %d %d",&p,&q,&r);
		for(int i=0;i<p;i++) scanf("%d",&a[i]);
		for(int i=0;i<q;i++) scanf("%d",&b[i]);
		for(int i=0;i<r;i++) scanf("%d",&c[i]);
		sort(a,a+p); //Sorting all 3 arrays
		sort(b,b+q);
		sort(c,c+r);
		bx=b[q-1]; //Assign max
	//	if ((a[0]<=bx)||(c[0]<=bx)) {
			for (int i=0;i<q;i++) {
				for (;n1<p;n1++) {
					if (a[n1]<=b[i]) s1+=(ll)a[n1];
					else break;
				}
				for (;n2<r;n2++){
					if (c[n2]<=b[i]) s2+=(ll)c[n2];
					else break;
				}
				s1 %= mod; s2 %= mod;
				s11=(ll)(n1)*(ll)(b[i])+s1;
				s12=(ll)(n2)*(ll)(b[i])+s2;
				s11 %= mod; s12 %= mod;
				s11=(s11*s12)%mod;
				sum= (sum+s11)%mod;	
			}
	//	}
		cout<<sum<<"\n";
	}
	return 0;
}
