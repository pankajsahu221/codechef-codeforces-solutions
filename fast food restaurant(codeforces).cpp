#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll  t;
    cin>>t;
       while(t--){
           int a,b,c,count=0;
           cin>>a>>b>>c;

           if(a>0 && b>0 && c==0){   
               count=2; a--; b--;
               if(a>1 && b>1){ count++; a--,b--;  }
               } 
           else if(a>0 && b==0 && c>0){ 
               count=2; a--; c--;
               if(a>0 && c>0){ count++; a--; c--; }
               }
           else if(a==0 && b>0 && c>0){  
               count=2; b--; c--;
               if(b>0 && c>0){ count++; b--; c--; }
               }
           else if(a==0 && b==0 && c>0) count=1;
           else if(a==0 && b>0 && c==0) count=1;
           else if(a>0 && b==0 && c==0) count=1;
           else if(a>0 && b>0  && c>0){
                count=3;   //{a} {b} {c};
                a--; b--; c--;

                  if(a>0 && b>0 && c==0){
                       count++;  //{a,b}
                       a--; b--;
                  }   
                  else if(a>0 && b==0 && c>0){
                      count++;  //{a,c}
                      a--; c--;
                  }  
                  else if(a==0 && b>0 && c>0){
                      count++;  //{b,c}
                      b--; c--;
                  }
                  else if(a>0 && b==0 && c==0) count=count;
                  else if(a==0 && b==0 && c>0) count=count;
                  else if(a==0 && b>0 && c==0)  count=count;
                  else if(a>0 && b>0 && c>0){
                          if(a==1 || b==1 || c==1){
                                 count+=2;
                          }
                          else if(a==1 && b==1 && c>1){
                                 count+=2;    
                          }
                          else if(a==1 && b>1 && c==1){
                              count+=2;
                              }
                          else if(a>1 && b==1 && c==1){
                              count+=2;
                              }
                          else if(a==1 && b==1 && c==1){
                               count++;  //{a,b} || {b,c} || {a,c} || {a,b,c}
                          }
                          else if(a>=2 && b>=2 && c>=2){
                               count+=3; // {a,b} {b,c} {a,c}
                               a-=2; b-=2 ;c-=2;

                               if(a>0 && b>0 && c>0){
                                    count++;  // {a,b,c}
                               }
                          }
                  }  
           }
           cout<<count<<endl;
       }
}
