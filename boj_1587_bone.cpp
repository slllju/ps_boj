#include<bits/stdc++.h>
using namespace std;

#define nn 1001
int dp[nn][nn];
bool adj[nn][nn];

int main(){
    int n, m, ed, ans=0;
    scanf("%d%d%d",&n,&m,&ed);
    while(ed--){ int u, v; scanf("%d%d",&u,&v); adj[u][v]=1; }
    for( int i=0; i<=n; i++ ){
        for( int j=0; j<=m; j++ ){
            if(1<i&&1<j) dp[i][j] = dp[i-2][j-2]+2;
            if(1<i) dp[i][j] = max( dp[i][j], dp[i-2][j]+1 );
            if(1<j) dp[i][j] = max( dp[i][j], dp[i][j-2]+1 );
            if(adj[i][j]) dp[i][j] = max( dp[i][j], dp[i-1][j-1]+1 );
            ans = max( ans, dp[i][j] );
        }
    }
    printf("%d",ans);
    return 0;
}
