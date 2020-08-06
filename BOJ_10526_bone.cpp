#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define nn 14
ll d[nn][nn], L;
int n;
vector<ll> candi;
bool win, did[nn];

void dfs( bool kind, vector<int> &a, int pre, int idx, int len, int last, ll sum ){
    if( win ) return;
    if( idx==len ){
        sum += d[pre][last];
        if( kind ) candi.push_back(sum);
        else{
            int i = lower_bound(candi.begin(),candi.end(),L-sum)-candi.begin();
            if( 0<=i && i<int(candi.size()) && candi[i]+sum==L ) win = 1;
        }
        return;
    }
    for( auto i : a ){
        if( !did[i] ){
            did[i] = 1;
            dfs( kind, a, i, idx+1, len, last, sum+d[pre][i] );
            did[i] = 0;
        }
    }
}
void midpoint( int m ){

    // 0과 m을 제외한 점들을 두 그룹으로 나누며 진행
    int l1 = (n-2)/2, l2 = n-2-l1;
    vector<int> a1(l1), a2(l2);
    
    for( int i=1; i<(1<<n) && !win ; i++ ){

        int k1=0, k2=0;
        if( (i&(1<<m)) || (i&1) ) continue;

        for( int j=1; j<n; j++ ){
            if( j==m ) continue;
            if( i&(1<<j) ){
                if(l1<=k1){ k1=-1; break; }     // 첫 번째 그룹 초과
                a1[k1++] = j;
                continue;
            }
            if( l2<=k2 ){ k2=-1; break; }       // 두 번째 그룹 초과
            a2[k2++] = j;
        }
        
        if( k1!=l1 || k2!=l2 ) continue;
        // 두 개의 그룹으로 나누기 성공

        // candi : (candidate) 첫 번째 그룹으로 만들 수 있는 경로의 길이
        candi.clear();
        // 첫 번째 그룹 DFS : 모든 경로의 길이 candi에 저장
        dfs( 1, a1, 0, 0, l1, m, 0 );
        
        // 첫 번째 그룹 경로 길이 정렬, 중복 제거 : 이분 탐색 가능
        sort( candi.begin(), candi.end() );
        candi.erase( unique(candi.begin(),candi.end()), candi.end() );
        // 두 번째 그룹 DFS : (L - 경로의 길이)가 candi에 있는지 검사
        dfs( 0, a2, m, 0, l2, 0, 0 );
        
    }
}
int main(){

    // input
    cin >> n >> L;
    for( int i=0; i<n; i++ ) for( int j=0; j<n; j++ ) cin >> d[i][j];
    
    // n=2,3
    if(n==2) win = (d[0][1]+d[1][0]==L);
    else if(n==3) win = ( d[0][1]+d[1][2]+d[2][0]==L || d[0][2]+d[2][1]+d[1][0]==L );
    
    // n >= 4
    else for( int i=1; i<n && !win; i++ ) midpoint(i);
    
    // output
    cout << ( win ? "possible" : "impossible" );
    return 0;
}
