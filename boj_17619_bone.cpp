#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define f first
#define s second

#define mxn 100001
int rt[mxn];
pair<pii,int> a[mxn];

int uf( int x ){
    if( x!=rt[x] ) rt[x] = uf(rt[x]);
    return rt[x];
}
int main(){
    int n, q;
    scanf("%d%d",&n,&q);
    for( int i=1; i<=n; i++ ){
        scanf("%d%d%d",&a[i].f.f,&a[i].f.s,&a[i].s);
        a[i].s = i;
        rt[i] = i;
    }
    sort(a+1,a+n+1);
    for( int i=1; i<n; i++ ){
        int i2 = i;
        for( int j=i+1; j<=n && a[j].f.f<=a[i].f.s; j++ ){
            int u = uf(a[i].s), v = uf(a[j].s);
            rt[max(u,v)] = min(u,v);
            if( a[i].f.s < a[j].f.s ) break;
            i2 = j;
        }
        i = i2;
    }
    for( int i=1; i<=q; i++ ){
        int u, v;
        scanf("%d%d",&u,&v);
        printf("%d\n",uf(u)==uf(v));
    }
    return 0;
}
