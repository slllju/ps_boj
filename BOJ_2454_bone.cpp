#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define mxn 300001
vector<int> tmp[mxn], child[mxn];
int conn[mxn];

int main(){
    int n, k, ans = 0;
    scanf("%d%d",&n,&k);
    for( int i=1, u, v; i<n; i++ ){
        scanf("%d%d",&u,&v);
        tmp[u].push_back(v);            // 트리 형성을 위한 임시 간선
        tmp[v].push_back(u);
    }
    
    conn[1] = 1;                        // 1을 최상위 부모노드로 트리 구성
    vector<int> node;                   // 트리를 BFS 돌면서 정점을 node에 담는다
    queue<int> q;
    q.push(1);
    while( !q.empty() ){
        int u=q.front();
        q.pop();
        node.push_back(u);
        for( auto v : tmp[u] ){
            if( !conn[v] ){
                q.push(v);
                conn[v] = 1;
                child[u].push_back(v);
            }
        }
    }

    for( int i=n-1; i>=0; i-- ){        // 트리 bottom up
        int u = node[i];
        if( !conn[u] ) continue;        // 이미 분할에 쓰인 노드

        vector<pair<int,int>> below;    // u의 자식 중 아직 분할이 안 된 노드들 모으기
        for( auto v : child[u] ) if( conn[v] ) below.push_back({conn[v],v});
        sort(below.begin(),below.end());    // 포함 노드 개수 기준 오름차순 정렬

        int start = 0, cnt = below.size();
        for( int j=0; j<2 && start < cnt; j++ ){    // 가장 작은 집합 두 개 선택
            if( below[start].first+conn[u] > k+1 ) break;
            conn[u] += below[start++].first;
        }
        if( start==2 ){     // 두 갈래로 묶였다면 분할 완료
            ans++;
            conn[u] = 0;    // 분할 완료 표시
        }
        ans += (cnt-start); // 자식 노드 중 분할에 쓰이지 못한 노드들 모두 분할
    }
    if( conn[1] ) ans++;    // 최상위노드가 아직 분할 안 되었다면 분할

    printf("%d",ans);
    return 0;
}
