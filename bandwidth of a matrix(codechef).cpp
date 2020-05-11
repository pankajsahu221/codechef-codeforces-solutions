#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
     while(t--){
         int n;
         cin>>n;
         
         long int count=0;
         int temp;
         
         for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>temp;
                if(temp==1)
                count++;
            }
         }
         int min,ans;
         min=n;
         
         for(int k=0; k<n; k++){
             if(count<=min){
                 ans=k;
                 break;
             }
             min=min+2*(n-k-1);
         }
         cout<<ans<<endl;
     }
     return 0;
}