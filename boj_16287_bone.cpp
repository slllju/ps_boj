#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

#define mxn 5000
int a[mxn];

bool uniq( int x, int y, int z, int w ){
    if(x==y||x==z||x==w||y==z||y==w||z==w) return 0;
    return 1;
}
int main(){
    int w, n;
    scanf("%d%d",&w,&n);
    for( int i=0; i<n; i++ ) scanf("%d",&a[i]);
    
    vector<tuple<int,int,int>> sum;
    for( int i=0; i<n; i++ ){
        for( int j=i+1; j<n; j++ ){
            sum.push_back({a[i]+a[j],i,j});
        }
    }
    sort( sum.begin(), sum.end() );
    int len = sum.size();

    bool win=0;
    for( int i=0; i<n && !win; i++ ){
        for( int j=i+1; j<n && !win; j++ ){
            int rem = w - a[i] - a[j], low=0, mid=0, high=len-1;
            if( rem < 2 ) continue;
            while( low<=high ){
                mid = (low+high)/2;
                if( get<0>(sum[mid]) <= rem ) low=mid+1;
                else high=mid-1;
            }
            while( get<0>(sum[mid])<rem && mid<len ) mid++;
            while( mid<len && get<0>(sum[mid])==rem ){
                if( uniq(i,j,get<1>(sum[mid]),get<2>(sum[mid])) ){
                    win = 1;
                    break;
                }
                mid++;
            }
        }
    }

    if(win) printf("YES");
    else printf("NO");
    return 0;
}
