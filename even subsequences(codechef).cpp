
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int main(){
    ll t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int arr[n+2];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        ll ans1=pow(2,n)-1;
        ll ans2=(n*(n-1))/2;
        
        cout<<ans1<<endl;
        cout<<ans2<<endl;
    }
}
