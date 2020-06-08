#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define pb push_back
#define mp make_pair


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        
        vector<int>setu[2500];
        int len[n+3];
        
        for(int i=0; i<n; i++){
            cin>>len[i];
            
          for(int j=0; j<len[i]; j++){
              int a;
              cin>>a;
              setu[i].push_back(a);
          }
        }
        int check=((k+1)*k)/2;
        int count=0;
        for(int i=0; i<n; i++){
            int sum1=0,sum2=0;
            bool visited[k+1]={false};
            for(auto x:setu[i]){
                if(!visited[x]){
                    visited[x]=true;  sum1+=x;
                }
            }
           for(int j=i+1; j<n; j++){
              sum2=0;
               for(auto x:setu[j]){
                  if(!visited[x]){
                      //visited[x]=true;  //we are not marking as visited because if it is added then we get the exact value of check
                      sum2+=x;
                   }
               }
               if(sum2+sum1==check) count++;
           }
           
        }
        
        cout<<count<<endl;
    }
    
}
