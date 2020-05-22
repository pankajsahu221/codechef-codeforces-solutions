#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

void solve(int tc) {
	ll x, y, l, r;
	cin>>x>>y>>l>>r;
	vector<ll> zs;
	bool eq = true;
	ll curr = 0;
	for(ll i=62; i>=0; --i) {
		ll p = (1LL<<i);
		if((l&p) == (r&p) && eq) {
			curr += r&p;
			continue;
		}
		if(eq) {
			eq = !eq;
		}
		if(r&p) {
			zs.pb(curr+p-1);    //make all the right bits 1(except the current bit)
		}
		curr += r&p;
	}
	zs.pb(r);
	zs.pb(l);
	sort(all(zs));
	ll ans = zs[0];
	for(ll z : zs) {
		if((x&z) * (y&z) > (x&ans) * (y&ans))
			ans = z;
	}
	for(ll i=62; i>=0; --i) {
		ll p = (1LL<<i);
		if((ans&p) == 0)
			continue;
		if((x&p) == 0 && (y&p) == 0 && ans-p >= l)		
			ans -= p;
	}
	cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    for(int tc=1; tc<=t; ++tc) {
        solve(tc);
    }    
    return 0;
}
