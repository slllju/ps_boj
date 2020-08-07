#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int,int> pii;
#define f first
#define s second
#define va(x) x.begin(),x.end()

int main(){
    
    int n, m;
    
    scanf("%d",&n);
    vector<pii> a(n);
    for( int i=0; i<n; i++ ) scanf("%d%d",&a[i].f,&a[i].s);
    sort(va(a));

    scanf("%d",&m);
    vector<pii> b(m);
    for( int i=0; i<m; i++ ) scanf("%d%d",&b[i].f,&b[i].s);
    sort(va(b));

    for( int i=0; i<m; i++ ){
        bool win = 1;
        int dr = b[i].f-a[0].f, dc = b[i].s-a[0].s;
        for( int j=1; j<n && win; j++ ){
            pii x = { a[j].f+dr, a[j].s+dc };
            int k = lower_bound(va(b),x)-b.begin();
            if( k<0 || k>=m || b[k].f!=x.f || b[k].s!=x.s ) win = 0;
        }
        if( win ){
            printf("%d %d\n",dr,dc);
            break;
        }
    }
    
    return 0;
}
