// https://www.acmicpc.net/problem/2465
// I solved this problem on May 15, 2020.

#include<cstdio>
#include<algorithm>
using namespace std;

#define mxt (1<<18)
#define mxn 100000
int st[mxt], cnt[mxn], stu[mxn];

void st_init( int l, int r, int x ){    // initialization of segment tree
    st[x] = r-l+1;
    if( l==r ) return;
    st_init( l, (l+r)/2, x*2+1 );
    st_init( (l+r)/2+1, r, x*2+2 );
}
int st_find( int sum, int l, int r, int x ){    // find a wanted value on segment tree
    if( l==r ) return l;
    if( sum <= st[x*2+1] ) return st_find( sum, l, (l+r)/2, x*2+1 );
    return st_find( sum-st[x*2+1], (l+r)/2+1, r, x*2+2 );
}
void st_update( int p, int l, int r, int x ){   // update the segment tree
    st[x]--;
    if( l==r ) return;
    if( p<=(l+r)/2 ) st_update( p, l, (l+r)/2, x*2+1 );
    else st_update( p, (l+r)/2+1, r, x*2+2 );
}
int main(){
    int n;
    scanf("%d",&n);
    for( int i=0; i<n; i++ ) scanf("%d",&stu[i]);
    for( int i=0; i<n; i++ ) scanf("%d",&cnt[i]);
    sort( stu, stu+n );
    st_init( 0, n-1, 0 );
    for( int i=n-1, j; i>=0; i-- ){
        j = st_find( cnt[i]+1, 0, n-1, 0 );   // stu[j] has cnt[i] shorter people before him
        cnt[i] = stu[j];        
        st_update( j, 0, n-1, 0 );
    }
    for( int i=0; i<n; i++ ) printf("%d\n",cnt[i]);
    return 0;
}
