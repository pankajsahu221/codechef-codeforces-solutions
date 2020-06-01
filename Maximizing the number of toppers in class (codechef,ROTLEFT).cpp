#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int main(){
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        ll a;
        vector<ll>v;
        for(int i=0; i<n; i++){
            cin>>a;
            v.push_back(a);
        }
        ll count=0,maxcount=0,max=0;
        for(int i=v.size(); i>=0; i--){
            if(v[i]>max){
                max=v[i];
                count++;
            }
        }
        maxcount=count;
        
        for(int i=0; i<v.size()-1; i++){
            int back=v[0];
            v.erase(v.begin());
            v.push_back(back);
            count=0,max=0;
            
            for(int j=v.size()-1; j>=0; j--){
                if(v[j]>max){
                    max=v[j];
                    count++;
                }
            }
            if(count>maxcount) maxcount=count;
        }
        cout<<maxcount<<endl;
    }
}
