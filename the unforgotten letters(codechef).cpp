//The que. can be solved using greedy approach
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    
    while(t--){
       ll n,tym;
       cin>>n>>tym;
       tym*=60;
       ll naklitym=tym;
       
       ll arr[n],visited[n],tot=0;
       for(int i=0; i<n; i++){
          cin>>arr[i];  tot+=arr[i];
       }
       
        if(tot<tym) cout<<tot<<"\n";
        if(tot==tym) cout<<n<<"\n";
        
        else{
            ll count1=0;
           sort(arr,arr+n,greater<int>());
           bool vis[n+9]={false};
       
          ll p=0;
           for(int i=0; i<n; i++){
              if(arr[i]<=tym){
                  tym-=arr[i];
                  p+=arr[i];
                  count1++;
                  vis[i]=true;
              }
              else{
                  break;
              }
            }
            
           for(int i=n-1; i>0; i--){
                  if(tym<=arr[i] && vis[i]==false){
                      
                      p+=arr[i];
                      count1++;
                      break;
                  }    
               }
             
            if(p==naklitym) cout<<count1<<"\n";
            else  cout<<count1<<" "<<p-naklitym<<"\n";
        }
    }
}