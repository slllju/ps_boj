#include<bits/stdc++.h>
using namespace std;

int a[100][6];

bool sum( int n, int l, int m ){
    int res=0;
    for( int i=0; i<n; i++ ){
        int tmp=2000000000;
        int x = a[i][0]*l-a[i][1];
        if( x<0 ) continue;
        for( int j=0; j<=(x+a[i][4]-1)/a[i][4]; j++ ){
            int y = max(0,(x - j*a[i][4] + a[i][2] - 1))/a[i][2];
            tmp = min( tmp, j*a[i][5]+y*a[i][3]);
        }
        res += tmp;
        if( res>m ) return 0;
    }
    return 1;
}
int main(){
    int n, m, ans=0;
    scanf("%d%d",&n,&m);
    for( int i=0; i<n; i++ ) for( int j=0; j<6; j++ ) scanf("%d",&a[i][j]);

    for( int low=0, high=91000; low<=high; ){
        int mid = (low+high)/2;
        if( sum(n,mid,m) ){ ans=mid; low=mid+1; }
        else high=mid-1;        
    }
    printf("%d",ans);
    
    return 0;
}
