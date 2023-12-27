#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define lg(x) (31 - __builtin_clz(x))
#define gmax(x,y) (A[x]>A[y]?x:y)
#define N 100005
#define LN 17
using namespace std;
int n,q;
int A[N];
int st[N][LN+1];

int qmax(int l, int r){
    if (l > r) return n+2;
    int p = lg(r-l+1);
    return gmax(st[l][p], st[r-(1<<p)+1][p]);
}

signed main(){
    freopen("rock.out","w",stdout);
    scanf("%d%d", &n,&q);
    A[0]= A[n + 1]=INT_MAX;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        st[i][0] = i;
    }
    for(int p = 1; p <= LN; p++){
        for(int i = 1; i+(1<<p)-1 <= n; i++){
            st[i][p] = gmax(st[i][p-1], st[i+(1<<(p-1))][p-1]);
        }
    }
    while(q--){
        int i,k,ans=0,m,mp;
        bool ed= false;
        scanf("%d%d", &i,&k);
        if (k==1){
            printf("1\n");continue;
        }

        if (i+k-1<=n){
            m=qmax(i,i+k-1);
            if(A[i + k] > A[m]) ans+= i + k - m - 1;
            mp= gmax(qmax(i,m-1),qmax(m+1,i+k-1));
            if(mp<m and A[i + k] > A[mp]) ans++, ed=true;
        }

        if (i-k+1>0){
            m=qmax(i-k+1,i);
            if(A[i - k] > A[m]) ans+= m - i + k - 1;
            mp= gmax(qmax(i-k+1,m-1),qmax(m+1,i));
            if(mp>m and A[i - k] > A[mp]) ans++;
        }
        printf("%d\n", ans);

    }

}
