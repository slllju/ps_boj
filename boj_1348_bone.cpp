#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define f first
#define s second

#define nn 51
#define cc 101
#define inf 1000000007

char a[nn][nn];
vector<int> adj[cc];
vector<pii> car, par;
int n, m, pn, cn;
int wit[cc], did[cc], dst[nn][nn], ctop[cc][cc];

void bfs( int u ){
    for( int i=0; i<n; i++ ) for( int j=0; j<m; j++ ) dst[i][j]=inf;
    dst[car[u].f][car[u].s]=0;
    queue<pii> qu;
    qu.push(car[u]);
    int di[4]={1,0,-1,0};
    while( !qu.empty() ){
        int i=qu.front().f, j=qu.front().s;
        qu.pop();
        for( int k=0; k<4; k++ ){
            int r=i+di[k], c=j+di[3-k];
            if(0<=r&&r<n&&0<=c&&c<m&&a[r][c]!='X'&&dst[i][j]+1<dst[r][c]){
                dst[r][c]=dst[i][j]+1;
                qu.push({r,c});
            }
        }
    }
    for( int i=0; i<pn; i++ ) ctop[u][i] = dst[par[i].f][par[i].s];
}
bool dfs( int u, int dc ){
    if( did[u]==dc ) return 0;
    did[u] = dc;
    for( auto v : adj[u] ){
        if( wit[v]<0 || dfs(wit[v],dc) ){
            wit[v] = u;
            return 1;
        }
    }
    return 0;
}
int main(){    

    scanf("%d%d",&n,&m);
    for( int i=0; i<n; i++ ){
        scanf("%s",a[i]);
        for( int j=0; j<m; j++ ){
            if( a[i][j]=='C' ) car.push_back({i,j});
            if( a[i][j]=='P' ) par.push_back({i,j});
        }
    }
    cn=car.size(), pn=par.size();
    if(!cn){ printf("0"); return 0; }

    int ans=-1;
    for( int i=0; i<cn; i++ ) bfs(i);
    for( int lo=0, hi=n*m, dc=0; lo<=hi; ){
        int mi = (lo+hi)/2, sum = 0;
        for( int i=0; i<pn; i++ ) wit[i]=-1;
        for( int i=0; i<cn; i++ ){
            adj[i].clear();
            for( int j=0; j<pn; j++ ) if( ctop[i][j]<=mi ) adj[i].push_back(j);
        }
        for( int i=0; i<cn; i++ ) if( dfs(i,++dc) ) sum++;
        if( sum==cn ){ ans=mi; hi=mi-1; }
        else lo=mi+1;        
    }
    printf("%d",ans);
    return 0;
}
