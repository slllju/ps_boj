#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

#define nn (1<<17)

void upt( int x, int d, vi &st ){
    st[x] += d;
    if( x ) upt( x/2, d, st );
}
int find( int x, int l, int r, int k, vi &st ){
    if( l==r ) return l;
    if( st[x*2] < k ) return find(x*2+1,(l+r)/2+1,r,k-st[x*2],st);
    return find(x*2,l,(l+r)/2,k,st);
}
int main(){
    int n, k;
    ll ans = 0;
    scanf("%d%d",&n,&k);
    vi st(nn*2), a(n);
    for( int i=0; i<n; i++ ){
        scanf("%d",&a[i]);
        upt( nn+a[i], 1, st );
        if( i<k-1 ) continue;
        ans += ll( find(1,0,nn-1,(k+1)/2,st) );
        upt( nn+a[i-k+1], -1, st );
    }
    printf("%lld",ans);
    return 0;
}
