#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve(){
    string s;
    cin>>s;
    
    
    int n=s.length();
    bool visited[n+9]={false};
    int count=0;
    
    for(int i=0; i<n; i++){
        if(s[i]=='x' && !visited[i]){
            if(s[i-1]=='y' && !visited[i-1]){ visited[i]=true; visited[i-1]=true; count++; continue;  }
            if(s[i+1]=='y' && !visited[i+1]){ visited[i]=true; visited[i+1]=true; count++; continue;  }
        }
        if(s[i]=='y' && !visited[i]){
            if(s[i-1]=='x' && !visited[i-1]){ visited[i]=true; visited[i-1]=true; count++; continue;  }
            if(s[i+1]=='x' && !visited[i+1]){ visited[i]=true; visited[i+1]=true; count++; continue;  }
        }
    }
    cout<<count<<endl;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        solve();
    }
}
