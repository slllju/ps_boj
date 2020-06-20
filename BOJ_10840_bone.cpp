#include<bits/stdc++.h>
using namespace std;

#define mxn 1501
#define alp 26

char a1[mxn], a2[mxn];
int l1, l2, cnt[alp];

bool ingredient( int n ){
    
    set<string> igd;
    string state="";
    
    for( int i=0; i<alp; i++ ){	// 재가공 문자열인 state 초기화
        cnt[i] = 0;
        state.push_back('a'+i); for( int j=0; j<4; j++ ) state.push_back('0');
    }
  
    for( int i=0, x; i<l1; i++ ){
        x = a1[i]-'a';
        cnt[x]++;
        for( int j=1000, k=1, v=cnt[x]; j; j/=10 ){ state[x*5+k++] = '0'+v/j;  v%=j; }

        if( i<n-1 ) continue;
        igd.insert(state);	// 길이에 해당하는 모든 연속부분문자열 집합에 추가

        x = a1[i-n+1]-'a';
        cnt[x]--;
        for( int j=1000, k=1, v=cnt[x]; j; j/=10 ){ state[x*5+k++] = '0'+v/j; v%=j; }
    }
    
    for( int i=0; i<alp; i++ ){		// 두 번째 문자열을 검사하기 위해 재가공 준비
        cnt[i] = 0;
        for( int j=0, k=1; j<4; j++ ) state[i*5+k++] = '0';
    }
    for( int i=0, x; i<l2; i++ ){
        x = a2[i]-'a';
        cnt[x]++;
        for( int j=1000, k=1, v=cnt[x]; j; j/=10 ){ state[x*5+k++] = '0'+v/j; v%=j; }

        if( i<n-1 ) continue;
        if( igd.count(state) ) return 1;	// 일치하는 것이 발견되면 정답

        x = a2[i-n+1]-'a';
        cnt[x]--;
        for( int j=1000, k=1, v=cnt[x]; j; j/=10 ){ state[x*5+k++] = '0'+v/j; v%=j; }
    }
    return 0;
}

int main(){

    scanf("%s",a1); scanf("%s",a2); l1=strlen(a1), l2 = strlen(a2);
    
    for( int i=min(l1,l2); i; i-- ) if( ingredient(i) ){ printf("%d",i); return 0; }

    printf("0"); return 0;
    
}
