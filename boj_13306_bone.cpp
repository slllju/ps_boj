#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define f first
#define s second

#define mxn 200001
int rt[mxn], g[mxn];
pii qr[mxn*2];
bool f[mxn];

int uf( int x ){
    if( x!=g[x] ) g[x] = uf(g[x]);
    return g[x];
}
int main(){
    int n, q;
    scanf("%d%d",&n,&q);
    for( int i=2; i<=n; i++ ){ scanf("%d",&rt[i]); g[i]=i; }
    rt[1] = g[1] = 1;
    for( int i=1; i<=q+n-1; i++ ){
        int x;
        scanf("%d",&x);
        if(x) scanf("%d%d",&qr[i].f,&qr[i].s);
        else scanf("%d",&qr[i].s);
    }
    for( int i=q+n-1, cnt=q; i; i-- ){
        int u=qr[i].f, v=qr[i].s;
        if( !u ){
            u = uf(rt[v]);
            v = uf(v);
            g[max(u,v)] = min(u,v);
            continue;
        }
        if( uf(u)==uf(v) ) f[cnt]=1;
        cnt--;
    }
    for( int i=1; i<=q; i++ ){
        if( f[i] ) printf("YES\n");
        else printf("NO\n");       
    }
    return 0;
}
