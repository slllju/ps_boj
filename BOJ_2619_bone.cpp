#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define mxn 1000
struct co{ int x,y; };
struct li{ int x1,y1,x2,y2; } vert[mxn/2], hori[mxn/2];

bool cmpx( co &p, co &q ){ if( p.x!=q.x ) return p.x<q.x; return p.y<q.y; }
bool cmpy( co &p, co &q ){ if( p.y!=q.y ) return p.y<q.y; return p.x<q.x; }

int main(){
    int n, ans=0;
    scanf("%d",&n);
    // 1. 입력받은 n개의 점으로 수평선, 수직선을 이어준다
    for( int i=0, t=0, x0, y0, x1, y1, x2, y2; i<=n; i++ ){
        if( i<n ) scanf("%d%d",&x2,&y2);
        else x2 = x0, y2 = y0;
        if( !i ) x0 = x2, y0 = y2;
        else{
            if( i==1 ) if( y1==y2 ) t=1;
            if( t ) hori[(i-1)/2] = {x1,y1,x2,y2};
            else vert[(i-1)/2] = {x1,y1,x2,y2};
            t = 1-t;
        }
        x1 = x2, y1 = y2;
    }
    
    // 2. 수평선과 수직선이 만나서 생기는 모든 교차점을 두 집합에 똑같이 저장한다
    n /= 2;
    vector<co> v1,v2;
    for( int i=0; i<n; i++ ){
        if( hori[i].x1>hori[i].x2 ) swap(hori[i].x1,hori[i].x2);
        for( int j=0; j<n; j++ ){
            if( vert[j].y1>vert[j].y2 ) swap(vert[j].y1,vert[j].y2);
            if( vert[j].x1<hori[i].x1 || hori[i].x2<vert[j].x1 ) continue;
            if( hori[i].y1<vert[j].y1 || vert[j].y2<hori[i].y1 ) continue;
            v1.push_back({vert[j].x1,hori[i].y1});
            v2.push_back({vert[j].x1,hori[i].y1});
        }
    }
    
    // 3. 교차점 집합 v1은 x좌표 기준으로, v2는 y좌표 기준으로 오름차순 정렬한다
    sort( v1.begin(), v1.end(), cmpx );
    sort( v2.begin(), v2.end(), cmpy );
    
    // 4. 모든 교차점을 하나씩 살펴보면서 단순사각형이 만들어지는지 확인한다
    int l1 = v1.size(), l2 = v2.size();
    for( int i=0, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5; i<=l1-4; i++ ){
        // (x1,y1) : 집합 v1에서 i번째 점
        x1 = v1[i].x, y1 = v1[i].y;
        
        // (x2,y2): 집합 v1에서 i+1번째 점. (x1,y1)과 수직관계여야 한다
        x2 = v1[i+1].x, y2 = v1[i+1].y;
        if( x1!=x2 ) continue;
        
        // (x3,y3): (x1,y1)이 오른쪽으로 가장 먼저 만나는 점으로, 수평관계여야 한다
        int low=0, high=l2-1, mid;
        while( low<=high ){
            mid = (low+high)/2;
            if( v2[mid].y==y1 && v2[mid].x==x1 ) break;
            if( y1<v2[mid].y || (y1==v2[mid].y&&x1<v2[mid].x) ) high = mid-1;
            else low = mid+1;
        }
        if( mid==l2-1 || y1!=v2[mid+1].y ) continue;
        x3 = v2[mid+1].x, y3 = v2[mid+1].y;
        
        // (x4,y4): (x2,y2)에서 오른쪽으로 가장 먼저 만나는 점으로, 수평관계여야 한다
        low=0, high=l2-1;
        while( low<=high ){
            mid = (low+high)/2;
            if( v2[mid].y==y2 && v2[mid].x==x2 ) break;
            if( y2<v2[mid].y || (y2==v2[mid].y&&x2<v2[mid].x) ) high = mid-1;
            else low = mid+1;
        }
        if( mid==l2-1 || y2!=v2[mid+1].y ) continue;
        x4 = v2[mid+1].x, y4 = v2[mid+1].y;

        // (x5,y5): (x3,y3)에서 윗방향으로 가장 먼저 만나는 점으로, 수직관계여야 한다
        low=0, high=l1-1;
        while( low<=high ){
            mid = (low+high)/2;
            if( v1[mid].y==y3 && v1[mid].x==x3 ) break;
            if( x3<v1[mid].x || (x3==v1[mid].x&&y3<v1[mid].y) ) high = mid-1;
            else low = mid+1;
        }
        if( mid==l1-1 || x3!=v1[mid+1].x ) continue;
        x5 = v1[mid+1].x, y5 = v1[mid+1].y;

        // (x4,y4)와 (x5,y5)가 같은 점이어야 한다.
        if( x4!=x5 || y4!=y5 ) continue;

        // 네 변이 모두 어떠한 변에 속해야 한다.
        bool e13=0, e24=0, e12=0, e34=0;
        for( int j=0; j<n; j++ ){
            if( hori[j].y1==y1 && hori[j].x1<=x1 && x3<=hori[j].x2 ) e13 = 1;
            if( hori[j].y1==y2 && hori[j].x1<=x2 && x4<=hori[j].x2 ) e24 = 1;
            if( vert[j].x1==x1 && vert[j].y1<=y1 && y2<=vert[j].y2 ) e12 = 1;
            if( vert[j].x1==x3 && vert[j].y1<=y3 && y4<=vert[j].y2 ) e34 = 1;
        }
        if( e13 && e24 && e12 && e34 ) ans++;
    }
    printf("%d",ans);
    return 0;
}
