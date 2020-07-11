#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define f first
#define s second
#define mxn 501
#define mxl 19

int h[mxn][mxn];            // heights of grid
int dep[mxn][mxn];          // depth on MST
vector<pii> adj[mxn][mxn];  // edge of MST
pii rt[mxn][mxn][mxl+1];    // [i][j] : (2^j)th root node of i node
int mh[mxn][mxn][mxl+1];    // [i][j] : max height from i to (2^j)th root node
int di[4]={1,0,-1,0};       // direction of four

void dfs( int r, int c, int rr, int cc, int de ){
    if( dep[r][c]>0 ) return;
    dep[r][c] = de;
    rt[r][c][0] = {rr,cc};
    mh[r][c][0] = max(h[r][c],h[rr][cc]);
    for( auto i : adj[r][c] ) dfs( i.f, i.s, r, c, de+1 );
}

pii uf( pii x ){
    if( rt[x.f][x.s][0] != x ) rt[x.f][x.s][0] = uf( rt[x.f][x.s][0] );
    return rt[x.f][x.s][0];
}

int main(){
    int n, m, qry;
    scanf("%d%d%d",&n,&m,&qry);

    // 1. 정점의 입력
    vector<pair<int,pii>> vtx;
    for( int i=1; i<=n; i++ ){
        for( int j=1; j<=m; j++ ){
            scanf("%d",&h[i][j]);
            vtx.push_back({h[i][j],{i,j}});
            rt[i][j][0] = {i,j};
        }
    }
    sort(vtx.begin(),vtx.end());
    
    // 2. MST의 구축
    for( auto x : vtx ){
        int r=x.s.f, c=x.s.s;
        for( int i=0; i<4; i++ ){
            int r2=r+di[i], c2=c+di[3-i];
            if( r2<1 || r2>n || c2<1 || c2>m || dep[r2][c2]==0 ) continue;
            pii u = uf({r,c}), v = uf({r2,c2});
            if( u==v ) continue;
            if( h[u.f][u.s]<h[v.f][v.s] ) rt[v.f][v.s][0] = u;
            else rt[u.f][u.s][0] = v;
            adj[r2][c2].push_back({r,c});
            adj[r][c].push_back({r2,c2});
        }
        dep[r][c]=-1;
    }

    // 3. LCA 구하기
    for( int i=1; i<=n; i++ ) for( int j=1; j<=m; j++ ) rt[i][j][0]={0,0};
    dfs( vtx.front().s.f, vtx.front().s.s, 0, 0, 1 );
    for( int l=1; l<=mxl; l++ ){
        for( int i=1; i<=n; i++ ){
            for( int j=1; j<=m; j++ ){
                if( (1<<l) >= dep[i][j] ) continue;
                pii mid = rt[i][j][l-1];
                rt[i][j][l] = rt[mid.f][mid.s][l-1];
                mh[i][j][l] = max( mh[i][j][l-1], mh[mid.f][mid.s][l-1] );
            }
        }
    }

    // 4. 쿼리 처리하기
    while( qry-- ){
        pii u, v;
        scanf("%d%d%d%d",&u.f,&u.s,&v.f,&v.s);

        pii u2 = u, v2 = v;
        if( dep[u.f][u.s]>dep[v.f][v.s] ) swap(u,v);
        for( int l=0, gap=dep[v.f][v.s]-dep[u.f][u.s]; gap>0; l++ ){
            if( gap%2 ) v = rt[v.f][v.s][l];
            gap /= 2;
        }
        if( u!=v ){
            for( int l=mxl; l>=0; l-- ){
                if( rt[u.f][u.s][l]!=rt[v.f][v.s][l] ){
                    u = rt[u.f][u.s][l];
                    v = rt[v.f][v.s][l];
                }
            }
            u = rt[u.f][u.s][0];
        }
        
        int lca = dep[u.f][u.s];
        u = u2, v = v2;
        int ans = max(h[u.f][u.s],h[v.f][v.s]);
        int gu = dep[u.f][u.s]-lca, gv = dep[v.f][v.s]-lca;
        for( int l=mxl; l>=0; l-- ){
            if( (1<<l) <= gu ){
                gu -= (1<<l);
                ans = max( ans, mh[u.f][u.s][l] );
                u = rt[u.f][u.s][l];
            }
            if( (1<<l) <= gv ){
                gv -= (1<<l);
                ans = max( ans, mh[v.f][v.s][l] );
                v = rt[v.f][v.s][l];
            }
        }
        printf("%d\n",ans);    
    }
    return 0;
}
