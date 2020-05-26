/*
The numbers are small, so you can afford keeping all distinct numbers in the range with bitset.
If number is present in the range we put a 1 in the "number'th" bit.
So the amount of different numbers in a range is easy to find with counting 1 bits.
*/
// Time Complexity: O(N + (Q * Log(N))
// Space Complexity: O(M * N)
#include <bits/stdc++.h>
using namespace std;
const int N = 1E5 + 5;
const int M = 5E3 + 5;
int a[N];
int b[N];
bitset<M> rst;
bitset<M> segt_a[4 * N];
bitset<M> segt_b[4 * N];
void build_a(int node, int start, int end) {
    if(start == end) {
        segt_a[node].set(a[start]);
        return;
    }
    int mid = (start + end) >> 1;
    build_a(node << 1, start, mid);
    build_a((node << 1) + 1, mid + 1, end);
    segt_a[node] = segt_a[node << 1] | segt_a[(node << 1) + 1];
    return;
}
void build_b(int node, int start, int end) {
    if(start == end) {
        segt_b[node].set(b[start]);
        return;
    }
    int mid = (start + end) >> 1;
    build_b(node << 1, start, mid);
    build_b((node << 1) + 1, mid + 1, end);
    segt_b[node] = segt_b[node << 1] | segt_b[(node << 1) + 1];
    return;
}
bitset<M> query_a(int node, int start, int end, int L, int R) {
    if(start > R || end < L)
        return rst;
    if(start >= L && end <= R)
        return segt_a[node];
    int mid = (start + end) >> 1;
    return query_a(node << 1, start, mid, L, R) | query_a((node << 1) + 1, mid + 1, end, L, R);
}
bitset<M> query_b(int node, int start, int end, int L, int R) {
    if(start > R || end < L)
        return rst;
    if(start >= L && end <= R)
        return segt_b[node];
    int mid = (start + end) >> 1;
    return query_b(node << 1, start, mid, L, R) | query_b((node << 1) + 1, mid + 1, end, L, R);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    for(int i = 1; i <= n; i ++)
        cin >> b[i];
    build_a(1, 1, n);
    build_b(1, 1, n);
    int q;
    cin >> q;
    int L1, R1, L2, R2;
    while(q --) {
        cin >> L1 >> R1 >> L2 >> R2;
        int ans = (query_a(1, 1, n, L1, R1) | query_b(1, 1, n, L2, R2)).count();
        cout << ans << '\n';
    }
    return 0;
}
