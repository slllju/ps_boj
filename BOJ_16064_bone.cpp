#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
#define f first
#define s second

#define nn 1001
int ic[nn], dist[nn];

int main(){
    int n, m, ans=0;
    cin>>n>>m;
    vector<pii> adj[n+1];
    while(m--){
        int u, v, d;
        scanf("%d%d%d",&u,&v,&d);
        ic[v]++;
        adj[u].push_back({v,d});
    }
    queue<int> qu;
    for( int i=1; i<=n; i++ ) if( ic[i]==0 ) qu.push(i);
    while( !qu.empty() ){
        int u = qu.front();
        qu.pop();
        if( adj[u].empty() ) ans = max(ans,dist[u]);
        for( auto i : adj[u] ){
            int v = i.f, d = i.s;
            dist[v] = max( dist[v], dist[u]+d );
            if( (--ic[v]) == 0 ) qu.push(v);
        }
    }
    cout << ans;
    return 0;
}
