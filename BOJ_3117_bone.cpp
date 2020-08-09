#include<iostream>
#include<algorithm>
using namespace std;

#define nn 100001
#define hh 31

int a[nn];
int root[nn][hh];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for( int i=1; i<=n; i++ ) scanf("%d",&a[i]);
    for( int i=1; i<=m; i++ ) scanf("%d",&root[i][0]);
    for( int j=1; j<hh; j++ ){
        for( int i=1; i<=m; i++ ){
            root[i][j] = root[root[i][j-1]][j-1];
        }
    }
    for( int i=1; i<=n; i++ ){
        int x = a[i], y = k-1;
        for( int j=hh-1; j>=0; j-- ){
            if( (1<<j) <= y ){
                y -= (1<<j);
                x = root[x][j];
            }
        }
        printf("%d ",x);
    }
    return 0;
}
