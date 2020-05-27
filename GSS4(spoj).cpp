#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int N = 1e6+5;
ll sum[4*N],a[N];
void build(int l,int r,int rt){
    if(l==r){
        sum[rt]=a[l];
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
 
void up(int L,int R,int l,int r,int rt){
    if(sum[rt]==(r-l+1)) return;
    if(l==r){
        sum[rt] = floor(sqrt(sum[rt]));
        return;
    }
    int m = (l+r)>>1;
    if(L<=m) up(L,R,lson);
    if(R>m) up(L,R,rson);
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
 
ll query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R) return sum[rt];
    int m = (l+r)>>1;
    ll ret = 0;
    if(L<=m) ret += query(L,R,lson);
    if(R>m) ret += query(L,R,rson);
    return ret;
}
 
int main(){
    int n,q,cas=1;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        build(1,n,1);
        scanf("%d",&q);
        printf("Case #%d:\n",cas++);
        while(q--){
            int c,l,r;
            scanf("%d%d%d",&c,&l,&r);
            if(l>r) swap(l,r); ///l may be greater than r
            if(c==0) up(l,r,1,n,1);
            else printf("%lld\n",query(l,r,1,n,1));
        }
        printf("\n");
    }
	return 0;
}
