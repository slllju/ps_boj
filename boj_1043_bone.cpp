#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n, m, k, ans=0, a[50];
    bool f[50], chk[51];
    scanf("%d%d%d",&n,&m,&k);
    
    vector<int> party[n+1], adj[n+1];
    queue<int> qu;
    
    for( int i=1; i<=n; i++ ) chk[i]=0;
    while( k-- ){ int i; scanf("%d",&i); qu.push(i); chk[i]=1; }

    for( int p=0; p<m; p++ ){
        f[p]=1;
        int cnt;
        scanf("%d",&cnt);
        for( int i=0; i<cnt; i++ ) scanf("%d",&a[i]);
        for( int i=0; i<cnt; i++ ){
            party[a[i]].push_back(p);
            for( int j=i+1; j<cnt; j++ ){
                adj[a[i]].push_back(a[j]);
                adj[a[j]].push_back(a[i]);
            }
        }
    }

    while( !qu.empty() ){
        int u = qu.front();
        qu.pop();
        for( auto p : party[u] ) f[p]=0;
        for( auto v : adj[u] ){
            if( !chk[v] ){
                chk[v]=1;
                qu.push(v);
            }
        }
    }
    
    for( int i=0; i<m; i++ ) ans+=f[i];
    printf("%d",ans);
    return 0;
}
