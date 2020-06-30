#include<bits/stdc++.h>
using namespace std;

int a[1500][1500], b[1500];

int main(){
    int n;
    scanf("%d",&n);
    for( int i=0; i<n; i++ ) for( int j=0; j<n; j++ ) scanf("%d",&a[i][j]);
    for( int j=1; j<n; j++ ){
        for( int i=n-1, x=n-1, now=n-1; now>=0; ){
            if( i<0 || (x>=0 && a[x][0] > a[i][j]) ) b[now--] = a[x--][0];
            else b[now--] = a[i--][j];
        }
        for( int i=0; i<n; i++ ) a[i][0] = b[i];
    }
    printf("%d",a[0][0]);
    return 0;
}
