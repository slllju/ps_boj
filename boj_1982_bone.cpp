#include<bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> pii;
#define f first
#define s second

#define nn 101
#define inf 1000000
int dp[nn][nn][nn][2];
pii a[nn];

int main(){

    int nm, nf, nc, nr, ans=inf;
    cin >> nm >> nf >> nr >> nc;
    for( int i=0; i<=nr; i++ ){
        if(i) cin >> a[i].f >> a[i].s;
        for( int j=0; j<=nm; j++ )
            for( int k=0; k<=nf; k++ )
                for( int l=0; l<2; l++ )
                    dp[i][j][k][l]=inf;
    }
                    
    dp[0][0][0][0]=0;
    for( int i=1; i<=nr; i++ ){
        for( int j=0; j<=nm; j++ ){
            for( int k=0; k<=nf; k++ ){
                for( int e=0; e<2; e++ ){
                    dp[i][j][k][e] = dp[i-1][j][k][e];
                    for( int l=1; l<=a[i].f; l++ ){
                        if( l<=j ) dp[i][j][k][e] = min( dp[i][j][k][e], dp[i-1][j-l][k][e]+a[i].s );
                        if( l<=k ) dp[i][j][k][e] = min( dp[i][j][k][e], dp[i-1][j][k-l][e]+a[i].s );
                    }
                }
                if( j && k && 1<a[i].f ) dp[i][j][k][1] = min( dp[i][j][k][1], dp[i-1][j-1][k-1][0]+a[i].s );
                if( j==nm && k==nf ) ans = min( ans, min(dp[i][j][k][0],dp[i][j][k][1]) );
            }
        }
    }
    if(ans==inf) cout<<"Impossible";
    else cout<<ans;
    return 0;    
}
