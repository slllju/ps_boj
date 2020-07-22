#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
#define f first
#define s second

#define nn 1000
pii a[nn];
bool g[nn*2+2][nn*2+2];
map<int,int> x,y, rx, ry;

int sum( int r, int c ){
    if( r%2 || c%2 ) return 0;
    return (rx[r/2]-rx[r/2-1])*(ry[c/2]-ry[c/2-1]);
}
int dfs( int r, int c, int n, int m ){
    if( r<0 || c<0 || r>n || c>n || g[r][c] ) return 0;
    g[r][c]=1;
    int res=sum(r,c), d[4]={1,0,-1,0};
    for( int i=0; i<4; i++ ) res+=dfs(r+d[i],c+d[3-i],n,m);
    return res;
}
int main(){
    
    int n, ans=0;
    scanf("%d",&n);
    
    for( int i=0; i<n; i++ ){
        scanf("%d%d",&a[i].f,&a[i].s);
        if(!x.count(a[i].f)) x.insert({a[i].f,1});
        if(!y.count(a[i].s)) y.insert({a[i].s,1});
    }

    int nx=0; for( auto i : x ){ x[i.f]=nx; rx[nx++]=i.f; }
    int ny=0; for( auto i : y ){ y[i.f]=ny; ry[ny++]=i.f; }
    
    for( int i=0; i<=n; i++ ){
        int r1=x[a[i%n].f], c1=y[a[i%n].s], r2=x[a[(i+1)%n].f], c2=y[a[(i+1)%n].s];
        if( r1>r2 ) swap(r1,r2);
        if( c1>c2 ) swap(c1,c2);
        if(r1==r2 ) for( int c=c1*2+1; c<=c2*2+1; c++ ) g[r1*2+1][c]=1;
        else for( int r=r1*2+1; r<=r2*2+1; r++ ) g[r][c1*2+1]=1;
    }

    nx*=2;
    ny*=2;
    dfs(0,0,nx,ny);
    
    for( int i=0; i<nx; i++ ){
        for( int j=0; j<ny; j++ ){
            if( g[i][j] ) continue;
            int tmp=dfs(i,j,nx,ny);
            ans = max( ans, tmp );
        }
    }
    printf("%d",ans);
    return 0;
}
