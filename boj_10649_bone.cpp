#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define f first
#define s second

#define mxn 20
#define mxd 1<<mxn
pair<ll,pll> a[mxn];
pll dp[mxd];
ll sum[mxd];

int main(){

    int n;
    ll h, ans=-1;    
    scanf("%d%lld",&n,&h);
    for( int i=0; i<n; i++ ) scanf("%lld%lld%lld",&a[i].f,&a[i].s.f,&a[i].s.s);

    for( int i=0; i<(1<<n); i++ ) dp[i]={-1,0};
    dp[0] = {1000000001,0};
    for( int x=0; x<(1<<n)-1; x++ ){
        if( dp[x].f<0 ) continue;
        for( int i=0; i<n; i++ ){
            if( x&(1<<i) ) continue;
            int now = x+(1<<i);
            if( sum[now]==0 ) sum[now] = sum[x] + a[i].f;
            pll tmp = { min(dp[x].f,a[i].s.s-dp[x].s), dp[x].s+a[i].s.f };
            dp[now] = max( dp[now], tmp );
            if( sum[now]>=h ) ans = max( ans, dp[now].f );
        }
    }

    if(ans<0) printf("Mark is too tall");
    else printf("%lld",ans);

    return 0;
}
