#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define f first
#define s second

#define mxn 500001
int fa[mxn];

int main(){

    int tc;
    scanf("%d",&tc);
    while(tc--){
        string a, b, pw;
        cin >> a >> b >> pw;
        int n = a.size(), m = b.size(), pn = pw.size();
        vector<int> ans;
        map<char,int> pos;
        for( int i=0; i<n; i++ ) pos[a[i]]=i;
        for( int i=0; i<n; i++ ){
            string x;
            for( int j=0, k=0; j<m; j++ ){
                int idx = pos[b[j]]+i; if(idx>=n) idx-=n;
                x += a[idx];
                if(!j) continue;
                while( k && x[j]!=x[k] ) k=fa[k-1];
                if( x[j]==x[k] ) fa[j]=++k;
            }
            int cnt=0;
            for( int j=0, k=0; j<pn; j++ ){
                while( k && pw[j]!=x[k] ) k=fa[k-1];
                if( pw[j]==x[k] ){
                    if(k==m-1){
                        cnt++;
                        k = fa[k];
                    }
                    else k++;
                }
            }
            if(cnt==1) ans.push_back(i);
        }
        if( ans.empty() ) printf("no solution\n");
        else if( ans.size()==1 ) printf("unique: %d\n",ans.front());
        else{
            sort(ans.begin(),ans.end());
            printf("ambiguous: ");
            for( auto i : ans ) printf("%d ",i);
            printf("\n");
        }
    }
    return 0;    
}
