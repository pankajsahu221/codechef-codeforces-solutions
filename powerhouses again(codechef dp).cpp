#include<bits/stdc++.h>
using namespace std;

const long long MAXN = 100010, MAXE = 200010, MAXK = 40;
const long long INF = 1000000000000000000;

long long n, e, k, x;
long long phLoc[MAXN], powerHouses[MAXK], marc[MAXN];
long long m, numP, maxC, resp, aux;
long long pop[MAXN], powerHousesCost[MAXK];

vector<long long> graph[MAXN];
vector<long long> cost, people;
vector<pair<long long, long long> > val;

void dfs(long long cur);

int main(){
    scanf("%lld %lld %lld", &n, &e, &k);
    for(long long i = 1; i <= e; i++){
        long long u, v;
        scanf("%lld %lld", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(long long i = 1; i <= n; i++){
        scanf("%lld", &pop[i]);
        phLoc[i] = -1;
    }
    for(long long i = 1; i <= k; i++){
        scanf("%lld", &aux);
        phLoc[aux] = i;
        powerHouses[i] = aux;
    }
    for(long long i = 1; i <= k; i++)
        scanf("%lld", &powerHousesCost[i]);
    scanf("%lld %lld", &x, &m);
    for(long long i = 1; i <= x; i++){
        scanf("%lld", &aux);
        m += powerHousesCost[aux];
    }
    for(long long i = 1; i <= n; i++){
        if(marc[i]) continue;
        numP = 0;
        maxC = INF;
        dfs(i);
        if(maxC == INF) continue;
        cost.push_back(maxC);
        people.push_back(numP);
    }
    if(cost.size() == 1 || cost.size() == 0){
        if(cost[0] <= m) printf("%lld\n", people[0]);
        else printf("0\n");
        return 0;
    }
    long long n1 = cost.size() / 2, n2 = cost.size() - n1;
    for(long long mask1 = 0; mask1 < (1 << n1); mask1++){
        long long auxC = 0, auxP = 0;
        for(long long i = 0; i < n1; i++){
            if(!(mask1 & (1 << i))) continue;
            auxC += cost[i];
            auxP += people[i];
        }
        val.push_back(make_pair(auxC, auxP));
    }
    sort(val.begin(), val.end());
    for(long long i = 1; i < val.size(); i++)
        val[i].second = max(val[i].second, val[i - 1].second);
    for(long long mask2 = 0; mask2 < (1 << n2); mask2++){
        long long auxC = 0, auxP = 0;
        for(long long i = 0; i < n2; i++){
            if(!(mask2 & (1 << i))) continue;
            auxC += cost[i + n1];
            auxP += people[i + n1];
        }
        if(m - auxC < 0) continue;
        long long k = upper_bound(val.begin(), val.end(), make_pair(m - auxC, INF)) - val.begin() - 1;
        k = min(k, (long long)val.size() - 1);
        k = max(k, 0LL);
        if(k >= 0 && k < val.size()) resp = max(resp, val[k].second + auxP);
    }
    printf("%lld\n", resp);
}

void dfs(long long cur){
    marc[cur] = 1;
    numP += pop[cur];
    if(phLoc[cur] != -1)
        maxC = min(maxC, powerHousesCost[phLoc[cur]]);
    for(long long i = 0; i < graph[cur].size(); i++){
        long long viz = graph[cur][i];
        if(marc[viz]) continue;
        dfs(viz);
    }
}