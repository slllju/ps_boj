#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<pair<ll,ll>> vpll;
#define f first
#define s second

void upt( vpll &st, int x, int l, int r, pair<int,int> u ){
    if( r < u.f || u.s < l ) return;
    if( u.f <= l && r <= u.s ){
        st[x].f++;
        st[x].s+=ll(1+l-u.f);
        return;
    }
    int m = (l+r)/2;
    upt( st, x*2+1, l, m, u );
    upt( st, x*2+2, m+1, r, u );
}
void lazy( vpll &st, int x, int l, int r, int u ){
    if( l==r ) return;
    int m = (l+r)/2;
    ll cnt = st[x].f, fro = st[x].s;
    st[x*2+1].f += cnt, st[x*2+1].s += fro;
    st[x*2+2].f += cnt, st[x*2+2].s += fro + cnt*ll(m-l+1);
    st[x] = {0,0};
    if( u<=m ) lazy( st, x*2+1, l, m, u );
    else lazy( st, x*2+2, m+1, r, u );
}
int main(){
    int n, m=1;
    cin >> n;
    while( m < n ) m*=2;
    vpll st(2*m);
    for( int i=0; i<n; i++ ) scanf("%lld",&st[m-1+i].s);
    cin >> n;
    while( n-- ){
        int k, u, v;
        scanf("%d",&k);
        if( k==1 ){
            scanf("%d%d",&u,&v);
            upt( st, 0, 1, m, {u,v} );
        }else{
            scanf("%d",&u);
            lazy( st, 0, 1, m, u );
            printf("%lld\n",st[m+u-2].s);
        }
    }
    return 0;
}
