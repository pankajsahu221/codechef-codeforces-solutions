#include<bits/stdc++.h>
using namespace std;
int n,Q,arr[100002];

//st1 max , st2 min

int main(){
    cin>>n>>Q;
    set<int>s;
    
    for(int i=0; i<n; i++){
        int val;
        cin>>val;
        
        if(val==1) s.insert(i);
    }
    while(Q--){
        int a,idx;
        cin>>a>>idx;
        
        if(a==1) s.insert(idx);
        else{
            int l=-1;
            int r=-1;
            set<int>::iterator ltr,rtr;
            
            ltr=s.lower_bound(idx);
            rtr=s.upper_bound(idx);
            
            if(ltr!=s.begin() && s.size()){
                --ltr;
                l=(*ltr);
            }
                    
            if(rtr!=s.end() && s.size())
                r=(*rtr);
                
            cout<<l<<" "<<r<<"\n";
        }
    }
    
}
