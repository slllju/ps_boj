#include<bits/stdc++.h>
using namespace std;

#define mxn 3000
#define mxd 1000001

bool chk[mxn][mxn];
int a[mxn], where[mxd];

int main(){
    int n;
    long long ans=0;
    scanf("%d",&n);
    for( int i=0; i<n; i++ ){
        scanf("%d",&a[i]);
        where[a[i]]=i+1;
    }
    
    for( int i=0; i<n; i++ ){
        for( int j=i+1; j<n; j++ ){
            if( chk[i][j] ) continue;
            chk[i][j] = 1;
            int v = a[j] - a[i], cnt = 2, now = j;
            long long sum = a[i] + a[j];
            while( a[now]+v<=a[n-1] && where[a[now]+v] ){
                chk[now][where[a[now]+v]-1] = 1;
                now = where[a[now]+v]-1;
                sum += (long long)(a[now]);
                cnt ++;
            }   
            if( cnt>2 ) ans = max( ans, sum );         
        }
    }
    printf("%lld",ans);
    return 0;
}
