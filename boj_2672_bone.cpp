#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef double dl;
typedef pair<dl,dl> pdd;
#define f first
#define s second

#define nn 30
pair<pdd,pdd> a[nn];

int main(){
    int n;
    map<dl,int> y;
    vector<dl> ry;
    dl ans=0;
    
    scanf("%d",&n);
    for( int i=0; i<n; i++ ){
        cin >> a[i].f.f >> a[i].f.s >> a[i].s.f >> a[i].s.s;
        a[i].s.f+=a[i].f.f;
        a[i].s.s+=a[i].f.s;
        y[a[i].f.s]=y[a[i].s.s]=1;
    }
    for( auto i : y ) ry.push_back(i.f);
    
    sort(a,a+n);
    for( int i=0; i<ry.size()-1; i++ ){
        dl l=-1, r=-1, y1=ry[i], y2=ry[i+1];
        for( int j=0; j<n; j++ ){
            if( a[j].s.s<=y1 || y2<=a[j].f.s ) continue;
            if( a[j].f.f<=r ) r = max(r,a[j].s.f);
            else{
                if( 0 < r ) ans += (y2-y1)*(r-l);
                l = a[j].f.f;
                r = a[j].s.f;
            }
        }
        if( 0 < r ) ans += (y2-y1)*(r-l);
    }
    if( ans-dl(int(ans))==0 ) printf("%d",int(ans));
    else printf("%.2lf",ans);
    return 0;    
}
