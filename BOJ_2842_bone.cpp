#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

#define max_n 50
#define inf 1000001
#define f first
#define s second

char vil[max_n][max_n];
int hei[max_n][max_n], did[max_n][max_n];

int main(){

    int n, n_k=0, ans = inf;
    int cnt_bs = 0, dr[8] = {-1,-1,-1,0,0,1,1,1}, dc[8] = {-1,0,1,-1,1,-1,0,1};
    
    pair<int,int> pos_p;    // 우체국의 위치
    scanf("%d",&n);
    for( int i=0; i<n; i++ ){
        scanf("%s",vil[i]);
        for( int j=0; j<n; j++ ){
            if( vil[i][j]=='P' ) pos_p = {i,j};
            n_k += (vil[i][j]=='K');              // 집의 개수 세어준다
        }
    }
  
    for( int i=0; i<n; i++ ) for( int j=0; j<n; j++ ) scanf("%d",&hei[i][j]);
    int hp = hei[pos_p.f][pos_p.s];   // hp : 우체국의 높이
    vector<int> h1, h2;               // h1 : 우체국보다 낮은 높이, h2 : 우체국보다 높은 높이
    for( int i=0; i<n; i++ ){
        for( int j=0; j<n; j++ ){
            if( hei[i][j]<=hp ) h1.push_back(hei[i][j]);
            if( hei[i][j]>=hp ) h2.push_back(hei[i][j]);
        }
    }
    sort(h1.begin(),h1.end());        // 이분탐색 위해 오름차순 정렬
    sort(h2.begin(),h2.end());
  
    for( auto bot : h1 ){
        int gap = inf;      // 피로도
        for( int l = 0, h = int(h2.size()-1); l<=h; ){
            int mid = ( l + h )/2, cnt_k = 0;
            // bot 이상, h2[mid] 이하의 높이만으로 모든 집을 방문할 수 있는지 BFS
            did[pos_p.f][pos_p.s] = ++cnt_bs;
            queue<pair<int,int>> qu;
            qu.push(pos_p);
            while( !qu.empty() ){
                for( int i=0; i<8; i++ ){
                    int r = qu.front().f+dr[i], c = qu.front().s+dc[i];
                    if( 0<=r&&r<n&&0<=c&&c<n && bot<=hei[r][c]&&hei[r][c]<=h2[mid] && did[r][c]!=cnt_bs ){
                        did[r][c] = cnt_bs;
                        cnt_k += (vil[r][c]=='K');
                        qu.push({r,c});
                    }
                }
                qu.pop();
            }
            if( cnt_k==n_k ){
                gap = h2[mid] - bot;  // 피로도 갱신
                h = mid - 1;
            }
            else l = mid + 1;
        }
        ans = min( ans, gap );        // 정답 갱신
    }
    
    printf("%d", ans );
    return 0;
}
