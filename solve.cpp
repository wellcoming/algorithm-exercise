#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define N 5005
#define P
using namespace std;
int n,m,k;
struct Edge{
    int u,w;
};
vector<Edge> g[N];
int in[N],tp[N];
int dp[N][N];
void top(){
    int cnt=0;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if(!in[i]) q.push(i);
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        tp[++cnt]=u;
        for (auto & i : g[u]) {
            int v=i.u;
            if(--in[v]==0) q.push(v);
        }
    }
}

signed main(){
    memset(dp,0x3f,sizeof(dp));
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1; i <= m; ++i) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        in[v]++;
        g[v].push_back({u,w});
    }
    top();
    dp[1][0]=0;
    for (int i = 1; i <= n; ++i) {
        int v=tp[i];
        for (auto & e : g[v]) {
            int u=e.u,w=e.w;
            for (int j = 1; j <= k; ++j) {
                dp[v][j]=min(dp[v][j],dp[u][j-1]+w);
            }
        }
    }
    printf("%d\n",dp[n][k]);

}
