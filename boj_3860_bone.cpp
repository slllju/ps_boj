#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
#define f first
#define s second

#define nn 30
#define inf 1000000007
int a[nn][nn], dist[nn][nn];
pair<pii,int> ho[nn][nn];

void proc(int n, int m){
    int g, h, di[4]={1,0,-1,0};
    for( int i=0; i<n; i++ ){
        for( int j=0; j<m; j++ ){
            a[i][j]=0;
            dist[i][j]=inf;
        }
    }
    scanf("%d",&g);
    while(g--){
        int r,c;
        scanf("%d%d",&r,&c);
        a[r][c]=1;
    }
    scanf("%d",&h);
    while(h--){
        int r1,c1,r2,c2,t;
        scanf("%d%d%d%d%d",&r1,&c1,&r2,&c2,&t);
        a[r1][c1]=2;
        ho[r1][c1]={{r2,c2},t};
    }
    dist[0][0]=0;
    bool cyc=0;
    for( int t=0; t<=n*m; t++ ){
        for( int i=0; i<n; i++ ){
            for( int j=0; j<m; j++ ){
                if( dist[i][j]==inf || a[i][j]==1 || (i==n-1&&j==m-1) ) continue;
                if( a[i][j]==0 ){
                    for( int k=0; k<4; k++ ){
                        int r = i+di[k], c = j+di[3-k], d = dist[i][j] + 1;
                        if( 0<=r && 0<=c && r<n && c<m && a[r][c]!=1 && d<dist[r][c] ){
                            dist[r][c] = d;
                            if( t==n*m ) cyc=1;
                        }
                    }
                }
                if( a[i][j]==2 ){
                    int r = ho[i][j].f.f, c = ho[i][j].f.s, d = dist[i][j]+ho[i][j].s;
                    if( d<dist[r][c] ){
                        dist[r][c] = d;
                        if( t==n*m ) cyc=1;
                    }
                }
            }
        }
    }
    if( cyc ) printf("Never\n");
    else if( dist[n-1][m-1]!=inf ) printf("%d\n",dist[n-1][m-1]);
    else printf("Impossible\n");
}
int main(){
    while(1){
        int n, m;
        scanf("%d%d",&n,&m);
        if(!n) break;
        proc(n,m);
    }
    return 0;    
}
