#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
#define f first
#define s second

#define nn 500002
bool lr[nn];
int ig[nn];
ll cnt[nn];
pii a[nn];

int main(){
    int n;
    scanf("%lld%d",&cnt[1],&n);
    for( int i=1; i<=n; i++ ){
        char x;
        scanf(" %c %d %d",&x,&a[i].f,&a[i].s);
        ig[a[i].f]++; ig[a[i].s]++;
        lr[i] = ( x=='R' );
    }
    queue<int> qu;
    for( int i=1; i<=n; i++ ) if(!ig[i]) qu.push(i);
    while( !qu.empty() ){
        int u = qu.front();
        qu.pop();
        pii v = a[u];
        if( lr[u] ) swap(v.f,v.s);
        cnt[v.f] += (cnt[u]+1ll)/2ll;
        cnt[v.s] += cnt[u]/2ll;
        if( cnt[u]%2ll ) lr[u] = 1-lr[u];
        if( (--ig[v.f])==0 && v.f>0 ) qu.push(v.f);
        if( (--ig[v.s])==0 && v.s>0 ) qu.push(v.s);
    }
    for( int i=1; i<=n; i++ ){
        if(lr[i]) printf("R");
        else printf("L");
    }
    return 0;
}
