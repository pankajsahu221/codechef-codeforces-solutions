#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[200005];
bool canSwap[200005];


int main(){
    ll t;
    cin>>t;
    
    while(t--){
       ll n,k;
       cin>>n>>k;
       memset(canSwap,false,sizeof(canSwap));
       
       for(int i=1; i<=n; i++){
          cin>>arr[i];
          if(arr[i]!=i) canSwap[arr[i]]=true;
          else canSwap[arr[i]]=false;
       }
       vector<tuple<ll,ll,ll>>ans;
       vector<pair<ll,ll>>extra;
       //vector<pair<int,pair<int,int>>>ans;
       ll flag=0;
       for(int i=1; i<=n; i++){
           if(!canSwap[arr[i]])
               continue;
        
           else{
               flag=0;
               vector<int>got;
               ll ind=i;
               
               while(canSwap[ind]==true){
                   got.push_back(ind);
                   canSwap[ind]=false;
                   ind=arr[ind];
               }
               
               while(got.size()>2){       
                   int p=got.back();
                   got.pop_back();
                   int q=got.back();
                   got.pop_back();
                   int r=got.back();
                   if(got.size()==1)
                       got.pop_back();
                   ans.push_back(tie(r,q,p));
                   k--;
               }
               if(got.size()==2){     //if the length of cycle is 2
                   extra.push_back(make_pair(got[0],got[1]));
               }
           }
              while(extra.size()>1){    
                 ans.push_back(tie(extra[0].first,extra[0].second,extra[1].first));
                 ans.push_back(tie(extra[0].first,extra[1].second,extra[1].first));
                 k-=2;
                 extra.clear();
                }
             }
               if(extra.size()>0){
                   flag=1;
               }
               
        if(flag==1 || k<0) cout<<-1<<"\n";
        else{
            cout<<ans.size()<<"\n";
            for(int i=0; i<ans.size(); i++){
                cout<<get<0>(ans[i])<<" ";
                cout<<get<1>(ans[i])<<" ";
                cout<<get<2>(ans[i])<<"\n";
                }
            }
        }
}
 
