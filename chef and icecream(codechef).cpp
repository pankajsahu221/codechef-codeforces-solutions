#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve(){
    int n;
        cin>>n;
        
        int arr[n+9];
        int c5=0,c10=0,c15=0;
        
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        for(int i=0; i<n; i++){
            if(arr[i]==5) c5++;
            if(arr[i]==10){
                if(c5>0){ c5--; c10++; continue; }
                else{ cout<<"NO"<<endl; return;  } 
            }
            if(arr[i]==15){
                if(c10>0){ c10--; c15++; continue; }
                if(c5>=2){ c5--; c5--; c15++; continue; }
                else{ cout<<"NO"<<endl; return;  }
            }
        }
        cout<<"YES"<<endl;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        solve();
    }
}
