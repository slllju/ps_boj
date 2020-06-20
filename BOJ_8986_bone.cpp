#include<bits/stdc++.h>
using namespace std;

#define mx_n 100001
#define inf 100000000000000
typedef long long ll;

ll a[mx_n];
int n;

ll dist( ll x ){
    ll gap = x, res=0;
    for( int i=1; i<n; i++ ){ res+=abs(gap-a[i]); gap+=x; }
    return res;
}
int main(){
    
    ll low=1, mid, high=1, ans=inf, t1, t2, t3;
    scanf("%d",&n);
    for( int i=0; i<n; i++ ){ scanf("%lld",&a[i]); if(i) high = max(high,a[i]-a[i-1]); }

    while( low<=high ){
    
        if( high-low <= 1 ){
            ans = min( ans, min(dist(low),dist(high)) );
            break;
        }
        
        mid = (low+high)/2;
        
        // 삼분 탐색을 위해 세 가지 값을 구해서 서로 비교한다
        // t2 is distance of middle
        // t1 is distance of middle of low and mid
        // t3 is distance of middle of mid and high 
        
        t1=dist((low+mid-1)/2), t2=dist(mid), t3=dist((mid+high+1)/2);       
        
        ans = min( ans, min(t2,min(t1,t3)) );
        if( t1 < t3 ) high=(mid+high+1)/2-1;
        else low=(low+mid-1)/2+1;
    }

    printf("%lld",ans);
    return 0;
}
