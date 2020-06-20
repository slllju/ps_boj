#include<cstdio>
using namespace std;

#define mxn 1001
#define inf -1000000000
char a[mxn], b[mxn];
struct dna{ int v, i, j; } d[mxn][mxn];

int main(){
    int n, m, ans=inf, ei, ej, si, sj;
    scanf("%d",&n); scanf("%s",a); scanf("%d",&m); scanf("%s",b);
    for( int i=1; i<=n; i++ ){
        for( int j=1; j<=m; j++ ){
            d[i][j] = {-2,0,0};
            if( a[i-1]==b[j-1] ) d[i][j].v = 3;
            if( d[i-1][j-1].v>0 ) d[i][j] = { d[i][j].v+d[i-1][j-1].v, i-1, j-1 };
            if( i>1 && d[i-1][j].v-2 > d[i][j].v ) d[i][j] = { d[i-1][j].v-2, i-1, j };
            if( j>1 && d[i][j-1].v-2 > d[i][j].v ) d[i][j] = { d[i][j-1].v-2, i, j-1 };
            if( d[i][j].v > ans ){ ans=d[i][j].v; ei=i; ej=j; }
        }
    }
    printf("%d\n",ans);
    for( si=ei, sj=ej; d[si][sj].i; ){
        int i=d[si][sj].i, j=d[si][sj].j;
        si = i, sj = j;
    }
    for( int i=si-1; i<ei; i++ ) printf("%c",a[i]); printf("\n");
    for( int i=sj-1; i<ej; i++ ) printf("%c",b[i]);
    return 0;
}
