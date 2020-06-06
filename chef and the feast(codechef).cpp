#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define pb push_back
#define mp make_pair

int main(){
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        ll cnt=0,val=0,waste=0,a;
        vector<ll>neg;
        
        for(int i=0; i<n; i++){
            cin>>a;
            
            if(a>=0){ val+=a; cnt++; }
            else neg.pb(a);
        }
        sort(neg.begin(),neg.end());
        ll les=0;
        
        for(ll i=neg.size()-1; i>=0; i--){
            if( (val+neg[i])*(cnt+1) > val*cnt ){
                val+=neg[i];
                cnt++;
            }
            else les+=neg[i];
        }
        cout<<(val*cnt)+les<<endl;
    }
}
