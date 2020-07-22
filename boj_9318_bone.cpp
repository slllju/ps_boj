#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
#define f first
#define s second

#define nn 1002
pair<pii,pii> a[nn];
ll rx[nn*2], ry[nn*2];
bool g[nn*2][nn*2];

void proc(){
    int n;
    scanf("%d",&n);
    map<int,int> x,y;
    for( int i=0; i<n; i++ ){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(!x.count(x1)) x.insert({x1,0});
        if(!x.count(x2)) x.insert({x2,0});
        if(!y.count(y1)) y.insert({y1,0});
        if(!y.count(y2)) y.insert({y2,0});
        a[i]={{x1,y1},{x2,y2}};
    }
    int nx=0, ny=0;
    for( auto i : x ){ x[i.f]=nx; rx[nx++]=i.f; }
    for( auto i : y ){ y[i.f]=ny; ry[ny++]=i.f; }
    for( int i=0; i<n; i++ ){
        a[i].f.f=x[a[i].f.f]; a[i].f.s=y[a[i].f.s];
        a[i].s.f=x[a[i].s.f]; a[i].s.s=y[a[i].s.s];
    }
    sort(a,a+n);
    ll ans=0;
    for( int i=0; i<ny-1; i++ ){
        int x1=-1, x2=-1;
        for( int j=0; j<n; j++ ){
            if( a[j].f.s >= i+1 || a[j].s.s <= i ) continue;
            if( a[j].f.f<=x2 ){ x2 = max(x2,a[j].s.f); continue; }
            if(0<=x1) ans += ll(rx[x2]-rx[x1])*ll(ry[i+1]-ry[i]);
            x1 = a[j].f.f;
            x2 = a[j].s.f;
        }
        if(0<=x1) ans += ll(rx[x2]-rx[x1])*ll(ry[i+1]-ry[i]); 
    }
    printf("%lld\n",ans);
}
int main(){ int tc; scanf("%d",&tc); while(tc--) proc(); return 0; }
