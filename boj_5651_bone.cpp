#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define f first
#define s second

#define mxn 301
int cap[mxn][mxn], cnt[mxn][mxn], flow[mxn][mxn];
int path[mxn];

int main(){

    int tc;
    scanf("%d",&tc);
    while(tc--){
        int n, m, ans=0;
        scanf("%d%d",&n,&m);
        vector<int> adj[n+1];
        for( int i=1; i<=n; i++ ){  // 초기화
            for( int j=1; j<=n; j++ ){
                cap[i][j] = 0;
                flow[i][j] = 0;
                cnt[i][j] = 0;
            }
        }
        while(m--){ // 간선 형성
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            if( !cap[u][v] && !cap[v][u] ){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            cap[u][v]+=c;
            cnt[u][v]++;
        }
        while(1){   // 에드몬드카프
            for( int i=1; i<=n; i++ ) path[i]=0;
            queue<int> qu;
            qu.push(1);
            path[1]=1;
            while( !qu.empty() && !path[n] ){
                int u=qu.front();
                qu.pop();
                for( auto v : adj[u] ){
                    if( !path[v] && flow[u][v]<cap[u][v] ){
                        path[v] = u;
                        if(v==n) break;
                        qu.push(v);
                    }
                }
            }
            if( !path[n] ) break;
            int w = 1000000000;
            for( int v=n; v>1; ){
                int u = path[v];
                w = min( w, cap[u][v]-flow[u][v] );
                v = u;
            }
            for( int v=n; v>1; ){
                int u = path[v];
                flow[u][v] += w;
                flow[v][u] -= w;
                v = u;
            }
        }
        for( int u=1; u<=n; u++ ){
            for( auto v : adj[u] ){
                if( cnt[u][v]==0 ) continue;
                queue<int> qu;
                for( int i=1; i<=n; i++ ) path[i]=0;
                path[u]=u;
                qu.push(u);
                while( !qu.empty() && !path[v] ){
                    int u2=qu.front();
                    qu.pop();
                    for( auto v2 : adj[u2] ){
                        if( !path[v2] && flow[u2][v2]<cap[u2][v2] ){
                            path[v2]=u2;
                            if(v2==v) break;
                            qu.push(v2);
                        }
                    }
                }
                if( !path[v] ) ans+=cnt[u][v];
            }
        }
        printf("%d\n",ans);
    }

    return 0;    
}
