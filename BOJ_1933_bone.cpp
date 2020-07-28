#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
#define f first
#define s second

#define nn 100001
pair<pii,int> a[nn];

int main(){
    int n, m=0;
    cin >> n;
    map<int,int> x;
    for( int i=0; i<n; i++ ){
        scanf("%d%d%d",&a[i].f.f,&a[i].s,&a[i].f.s);
        x[a[i].f.f]= x[a[i].f.s] = 0;
    }
    vi rx, h(m+1);
    for( auto i : x ){ x[i.f]=m++; rx.push_back(i.f); }
    sort(a,a+n);

    int now=0;
    priority_queue<pii> pq;
    for( int i=0, j=0; i<m; i++ ){
        while( j<n && x[a[j].f.f]<=i ){
            pq.push({a[j].s,x[a[j].f.s]});
            j++;
        }
        int next = 0;
        while( !pq.empty() ){
            if( i < pq.top().s ){
                next = pq.top().f;
                break;
            }
            pq.pop();
        }
        if( now!=next ){
            now = next;
            printf("%d %d ",rx[i],now);
        }
    }
    return 0;
}
