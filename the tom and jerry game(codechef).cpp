#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

ll recur(ll num){
    while(num>=1){
        if(num%2==0)return recur(num/2);
        else return num;
    }
}

void solve(){
    ll tom,jerry;
    cin>>tom;
    
    if(tom%2!=0){
        cout<<tom/2<<endl; return;
    }
    if(tom%2==0){
       ll numb=recur(tom);
       cout<<numb/2<<endl;
    }
}

int main(){
    ll t;
    cin>>t;
    
    while(t--){
        solve();
    }
}
