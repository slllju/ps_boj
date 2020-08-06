#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int,int> pii;
#define f first
#define s second
#define va(x) x.begin(),x.end()

bool cmp( pii x, pii y ){
    return x.f==y.f ? x.s<=y.s : x.f<y.f;
}
void cnt( vector<pii> &a, int p, int l, int r, int &ans, int &dup ){
    int n = a.size();
    pii t1 = {p,l}, t2 = {p,r};
    int p1 = lower_bound(va(a),t1) - a.begin();
    int p2 = upper_bound(va(a),t2) - a.begin();
    if( n<=p1 || !cmp(a[p1],t2) ) return;
    dup += (a[p1]==t1) + (a[p2-1]==t2);
    ans += p2-p1;    
}
int main(){

    int n, m;
    scanf("%d",&n);
    vector<pii> x(n), y(n);
    for( int i=0; i<n; i++ ){
        scanf("%d%d",&x[i].f,&x[i].s);
        y[i] = {x[i].s,x[i].f};
    }
    sort(va(x));
    sort(va(y));

    scanf("%d",&m);
    while( m-- ){
        int x1, y1, x2, y2, ans = 0, dup = 0;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        cnt( x, x1, y1, y2, ans, dup );
        cnt( x, x2, y1, y2, ans, dup );
        cnt( y, y1, x1, x2, ans, dup );
        cnt( y, y2, x1, x2, ans, dup );
        printf("%d\n",ans-dup/2);
    }
    return 0;
}
