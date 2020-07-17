#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef long long ll;
#define f first
#define s second

#define mxd 1<<21
#define mxn 75000
int st[mxd];        // segment tree of sum
int yi[mxn];        // index of unique y
pii a[mxn];         // coordinates   

int idx_y(int n){
    set<int> y;
    int cnt=0;
    for( int i=0; i<n; i++ ) if(!y.count(a[i].s) ) y.insert(a[i].s);
    map<int,int> idx;
    for( auto i : y ) idx.insert({i,cnt++});
    for( int i=0; i<n; i++ ) yi[i] = idx[a[i].s];
    return cnt;
}
void upd( int x ){
    st[x]++;
    if( x ) upd((x-1)/2);
}
int find( int x, int l, int r, int y ){
    if( y<l ) return 0;
    if( r<=y ) return st[x];
    return find(x*2+1,l,(l+r)/2,y)+find(x*2+2,(l+r)/2+1,r,y);
}
ll solve(){
    // 1. 입력
    int n;
    scanf("%d",&n);
    for( int i=0; i<n; i++ ){ scanf("%d%d",&a[i].f,&a[i].s); a[i].s*=-1; }
    
    // 2. y좌표 압축
    sort(a,a+n);
    for( int i=0; i<n; i++ ) a[i].s*=-1;
    int m = idx_y(n);
    
    // 3. 세그먼트 트리 초기화
    int base=1;
    while( base<m ) base*=2;
    for( int i=0; i<base*2; i++ ) st[i] = 0;
    
    // 4. 섬의 쌍 수 구하기 (=쿼리 처리)
    ll ans=0;
    for( int i=n-1; i>=0; i-- ){
        ans += ll(find(0,0,base-1,yi[i]));
        upd(base-1+yi[i]);
    }
    return ans;
}
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--) printf("%lld\n",solve());
    return 0;
}
