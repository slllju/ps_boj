#include<bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;
#define f first
#define s second

#define mxn 100001
int cnt[mxn];
vector<int> adj[mxn];
bool did[mxn];

int main(){
    int n, m, c1, c2, ans=0;
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    while( m-- ){
        int u, v; scanf("%d%d",&u,&v);
        adj[u].push_back(v); cnt[v]++;
        adj[v].push_back(u); cnt[u]++; 
    }
    
    queue<int> qu;
    m = n;
    for( int i=1; i<=n; i++ ) if( cnt[i] < c1 ){ did[i] = 1; qu.push(i); m--; }
    while( !qu.empty() ){
        int u = qu.front(); qu.pop();
        for( auto v : adj[u] ){
            cnt[v]--;
            if( !did[v] && cnt[v]<c1 ){ did[v] = 1; qu.push(v); m--; }
        }
    }

    priority_queue<pii> pq;
    for( int i=1; i<=n; i++ ) if( !did[i] ) pq.push({cnt[i],i});
    for( int i=m; i>0; i-- ){
        if( i>m ) continue;
        int l = c1, r = i-1-c2;
        if( r<l ) break;
        while( !pq.empty() && pq.top().f > r ){
            int u = pq.top().s, l = pq.top().f;
            pq.pop();
            if( did[u] || cnt[u] < l ) continue;
            did[u] = 1; m--; r--;
            for( auto v : adj[u] ){
                if( did[v] ) continue;
                cnt[v]--;
                if( cnt[v] < c1 ){ did[v] = 1; m--; r--; continue; }
                pq.push({cnt[v],v});
            }
        }
        if( i==m ){ ans=i; break; }
    }    
    printf("%d",ans);
    return 0;
}
