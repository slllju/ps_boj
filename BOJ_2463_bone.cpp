#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define mxn 1000001
int root[mxn], cnt[mxn];
struct edge{ int u, v; long long d; } ed[mxn];
bool cmpe( edge &p, edge &q ){ return p.d<=q.d; }

int uf( int x ){
    if( root[x]!=x ) root[x] = uf(root[x]);
    return root[x];
}
int main(){
    int n, m;
    long long Cost=0, sum, rem=1000000000;
    scanf("%d%d",&n,&m);
    for( int i=1; i<=max(n,m); i++ ){
        if( i<=n ) root[i] = i, cnt[i] = 1;
        if( i<=m ) scanf("%d%d%d",&ed[i-1].u,&ed[i-1].v,&ed[i-1].d);
    }
    sort( ed, ed+m, cmpe );
    for( int i=1; i<m; i++ ) ed[i].d += ed[i-1].d;
    for( int i=m-1; i>=0; i-- ){
        int u = uf(ed[i].u), v = uf(ed[i].v);
        if( u==v ) continue;
        sum = ((long long)(cnt[u])*(long long)(cnt[v])) % rem;
        sum = (sum*ed[i].d) % rem;
        Cost = (Cost+sum) % rem;
        if( u>v ) swap(u,v);
        cnt[u] += cnt[v];
        root[v] = root[u];
    }
    printf("%lld",Cost);
    return 0;
}
