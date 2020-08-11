#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

typedef long long ll;
#define max_n 35
ll a[max_n];
map<ll,int> cnt;
int ans = max_n+1;

void dfs( bool half, int i, int fin, ll now, int cost ){
    if( i==fin ){
        if( half ){
            now ^= ((1ll<<fin)-1);
            if( cnt.count(now) ) ans = min( ans, cost+cnt[now] );
        }
        if( !half ){
            if( cnt.count(now)==0 || cost < cnt[now] ) cnt[now] = cost;
        }
        return;
    }
    dfs( half, i+1, fin, now, cost );
    dfs( half, i+1, fin, now^a[i], cost+1 );
}
int main(){
    int n, m;
    scanf("%d%d",&n,&m);
    for( int i=0; i<n; i++ ) a[i] = 1ll<<i;
    
    while( m-- ){
        int u, v;
        scanf("%d%d",&u,&v);
        a[u-1] |= (1ll<<(v-1));
        a[v-1] |= (1ll<<(u-1));
    }
    dfs( 0, 0, n/2, 0, 0 );
    dfs( 1, n/2, n, 0, 0 );
    
    printf("%d",ans);
    return 0;
}
