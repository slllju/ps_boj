// https://www.acmicpc.net/problem/10000

#include<cstdio>
#include<algorithm>
using namespace std;

#define mxn 300001
#define inf 2000000001
pair<int,int> a[mxn];
int n;

int circle( int s, int e ){
    int res = 1, lm = a[s].first;
    bool half = 1;
    for( int i=s+1; i<=e; i++ ){
        if( lm!=a[i].first ) half = 0;
        else lm = a[i].second;
        int low=i+1, mid, high=e, j=i;
        while( low<=high ){
            mid = (low+high)/2;
            if( a[mid].first < a[i].second){
                j = max( j, mid );
                low = mid+1;
            }else high = mid-1;
        }
        res += circle(i,j);
        i=j;
    }
    if( s<e && half && lm==a[s].second ) res++;
    return res;
}
int main(){
    int n, lm=inf, rm=-inf;
    scanf("%d",&n);
    for( int i=1,x,r; i<=n; i++ ){
        scanf("%d%d",&x,&r);
        a[i] = {x-r,-x-r};
        lm = min(lm,x-r);
        rm = max(rm,x+r);
    }
    a[0] = {lm-1,-rm-1};
    sort(a,a+n+1);
    for( int i=0; i<=n; i++ ) a[i].second*=-1;
    printf("%d",circle(0,n));
    return 0;
}
