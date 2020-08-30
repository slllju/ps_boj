#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second

#define mxn 10000
int r[mxn];
pair<int,int> a[mxn];

int uf( int x ){
    if( x!=r[x] ) r[x] = uf(r[x]);
    return r[x];
}
int main(){
    int n, ans=0;
    scanf("%d",&n);
    for( int i=0; i<n; i++ ){
        scanf("%d%d",&a[i].f,&a[i].s);
        r[i] = i;
    }
    for( int i=n-1; i>=0; i-- ){
        bool suc = 1;
        for( int j=i+1; j<n; j++ ){
            int j2 = uf(j);
            if( a[j2].f<=a[i].f && a[i].s<=a[j2].s ){
                r[i] = j2;
                suc = 0;
                break;
            }
        }
        if( !suc ) continue;
        ans++;
        for( int j=i+1; j<n; j++ ){
            int i2 = uf(i), j2 = uf(j);
            if( i2==j2 || a[i2].s+1 < a[j2].f || a[j2].s+1 < a[i2].f ) continue;
            int lo = min( a[i2].f, a[j2].f ), hi = max( a[i2].s, a[j2].s );
            a[i2] = a[j2] = {lo,hi};
            r[max(i2,j2)] = min(i2,j2);
        }
    }
    printf("%d",ans);
    return 0;
}
