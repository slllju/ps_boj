#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define nn 1000
bool a[nn][nn];
int dp[nn][nn];

int main(){
    int n, m;
    scanf("%d%d%d",&n,&m,&dp[0][0]);
    for( int i=0; i<n; i++ ) for( int j=0; j<m; j++ ) scanf("%d",&a[i][j]);
    
    int r=0, c=0;
    for( int i=0; i<n; i++ ){
        if( r==n || c==m ) break;
        for( int j=0; j<m; j++ ){
            if( !dp[i][j] ) continue;
            if( dp[i][j]%2==0 ) a[i][j] = 1-a[i][j];
            if( i+1<n ) dp[i+1][j] += dp[i][j]/2;
            if( j+1<m ) dp[i][j+1] += dp[i][j]/2;
            if( dp[i][j]%2 ){
                if( a[i][j] && j+1<m ) dp[i][j+1]++;
                if( !a[i][j] && i+1<n ) dp[i+1][j]++;
            }
            if( r==i && c==j ){
                if( a[i][j] ) c++;
                else r++;
                if( r==n || c==m ) break;
            }
        }
    }
    printf("%d %d",r+1,c+1);
    return 0;
}
