#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define fir first
#define sec second

int main(){

    // 1. 입력 받은 좌표들을 x좌표 기준으로 오름차순 정렬
    int n, ey;
    scanf("%d%d",&n,&ey);
    vector<pair<int,int>> a;
    a.push_back({0,0});
    for( int i=0, x, y; i<n; i++ ){
        scanf("%d%d",&x,&y);
        a.push_back({x,y});
    }
    sort(a.begin(),a.end());


    // 2. 이분탐색을 이용한, BFS를 위한 간선 형성
    vector<int> ed[n+1];
    for( int i=0; i<=n; i++ ){
        for( int x=max(0,a[i].fir-2); x<=a[i].fir+2; x++ ){
            int low=0, mid, high=n, sj=0, ej=n;
            while( low<=high ){
                mid = (low+high)/2;
                if( a[mid].fir<x ){ sj = mid+1; low = mid+1;}
                else high = mid-1;
            }
            if( a[sj].fir!=x ) continue;	// sj : 찾을 구간의 시작 인덱스
            low = 0, high = n;
            while( low<=high ){
                mid = (low+high)/2;
                if( a[mid].fir>x ){ ej = mid-1; high = mid-1; }
                else low = mid+1;
            }
            if( ej<sj || a[ej].fir!=x ) continue;	// ej : 찾을 구간의 끝 인덱스
            low = sj, high = ej;
            while( low<=high ){
                mid = (low+high)/2;
                if( a[mid].sec<=a[i].sec ){ sj = mid; low = mid+1; }
                else high = mid-1;
            }
            for( int j=max(0,sj-2), cnt=5; cnt--; j++ ){
                if( a[j].fir==x && abs(a[j].sec-a[i].sec)<=2 && i!=j ){
                    ed[i].push_back(j);
                }
            }
        }
    }

    // 3. BFS : 도착 y좌표까지 이동하는 최소횟수 출력
    int ans=-1;
    queue<pair<int,int>> q;
    q.push({0,0});
    a[0].fir=-1;    // 방문 체크를 이렇게 하였네
    while( !q.empty() ){
        int u = q.front().fir, d = q.front().sec;
        q.pop();
        if( a[u].sec >= ey ){ ans = d; break; }
        for( auto v : ed[u] ){
            if( a[v].fir>=0 ){
                a[v].fir = -1;
                q.push({v,d+1});
            }
        }
    }
    printf("%d",ans);
    return 0;
}
