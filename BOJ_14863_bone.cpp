#include<bits/stdc++.h>
using namespace std;

#define mxn 100000

int dp[mxn];

int main(){

    int n, k, lim=0, ans=0, m[2], w[2];
    scanf("%d%d",&n,&k);
    for( int i=1; i<=k; i++ ) dp[i]=-1;
    
    while( n-- ){
    
        scanf("%d%d%d%d",&m[0],&w[0],&m[1],&w[1]);
        for( int i=lim; i>=0; i-- ){
            if( dp[i]<0 ) continue;
            for( int j=0; j<2; j++ ){
                if( i+m[j] <= k ){
                    dp[i+m[j]]=max(dp[i+m[j]],dp[i]+w[j]);
                    if( n==0 ) ans=max(ans,dp[i+m[j]]);
                }
            }
            dp[i]=-1;
        }
        lim = min( k, lim+max(m[0],m[1]) );
    
    }

    printf("%d",ans);
    return 0;
}
