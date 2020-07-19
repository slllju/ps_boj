#include<bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;
#define f first
#define s second

#define nn 2002
#define inf 1000000007
int cap[nn][nn], flo[nn][nn], cost[nn][nn];
int a[nn], b[nn];
int path[nn], dist[nn], cnt[nn];
bool inq[nn];
vector<int> adj[nn];

int main(){
    int n, ans=0;
    scanf("%d",&n);
    for( int i=1; i<=n; i++ ) scanf("%d",&a[i]);
    for( int i=1; i<=n; i++ ) scanf("%d",&b[i]);
    int ss=0, ee=n*2+1;
    for( int i=1; i<=n; i++ ){
        adj[ss].push_back(i); adj[n+i].push_back(ee);
        cap[ss][i] = cap[n+i][ee] = 1;
        for( int j=1; j<=n; j++ ){
            adj[i].push_back(n+j);
            adj[n+j].push_back(i);
            cap[i][n+j] = 1;
            if( a[i]>b[j] ){ cost[i][n+j] = -2; cost[n+j][i] = 2; }
            if( a[i]==b[j] ){ cost[i][n+j] = -1; cost[n+j][i] = 1; }
        }
    }
    while(1){
        for( int i=ss; i<=ee; i++ ){
            dist[i]=inf;
            path[i]=-1;
            cnt[i]=0;
        }
        queue<int> qu;
        qu.push(ss);
        dist[ss] = 0;
        bool cyc=0;
        while( !cyc && !qu.empty() ){
            int u = qu.front();
            inq[u] = 0;
            qu.pop();
            for( auto v : adj[u] ){
                if( flo[u][v]<cap[u][v] && dist[u]+cost[u][v]<dist[v] ){
                    dist[v] = dist[u]+cost[u][v];
                    path[v] = u;
                    cnt[v]++;
                    if( cnt[v]>=ee ){ cyc=1; break; }
                    if( !inq[v] ){
                        inq[v] = 1;
                        qu.push(v);
                    }
                }
            }
        }
        if( path[ee]<0 ) break;
        ans -= dist[ee];
        for( int v=ee, u; v!=ss; v=u ){
            u = path[v];
            flo[u][v]++; flo[v][u]--;
        }        
    }
    printf("%d",ans);
    return 0;    
}
