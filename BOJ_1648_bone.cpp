#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll,ll> pll;
#define f first
#define s second

#define nn 1<<14
const int mod = 9901;
int dp[nn][2];

int main(){
    int n, m;
    cin >> n >> m;
    int end = (1<<m)-1, t=0;
    dp[0][0]=1;
    for( int i=0; i<n; i++ ){
        for( int j=0; j<m; j++ ){
            for( int k=0; k<=end; k++ ){
                int j2 = 1<<j;
                if( k & j2 ) dp[k-j2][1-t] = (dp[k-j2][1-t]+dp[k][t])%mod;
                else{
                    dp[k+j2][1-t] = (dp[k+j2][1-t]+dp[k][t])%mod;
                    int j3 = 1<<(j+1);
                    if( j < m-1 && !(k&j3) ) dp[k+j3][1-t] = (dp[k+j3][1-t]+dp[k][t])%mod;
                }
                dp[k][t] = 0;
            }
            t=1-t;
        }
    }
    cout << dp[0][t];
    return 0;
}
