#include <bits/stdc++.h>
#define int unsigned long long //不知道为什么必须用ll
#define ull unsigned long long
#define N 300005
using namespace std;
int n,m,x;
vector<pair<int,int>> g[N];
int a[N];
int ans[N];
bitset<N> vis;
int oi,ai;
ull all;


void dfs(int u){
    all+=a[u];
    vis[u]=true;
    for (auto p:g[u]){
        int i=p.first,v=p.second;
        if (vis[v])continue;
        dfs(v);
        if (a[v]>=x){
            a[u]=a[u]+a[v]-x;
            ans[++oi]=i;
        } else{
            ans[--ai]=i;
        }
    }
}


signed main(){
    scanf("%llu%llu%llu",&n,&m,&x);
    ai=n;
    for (int i = 1; i <= n; ++i)
        scanf("%llu",&a[i]);
    for (int i = 1; i <= m; ++i) {
        int u,v;
        scanf("%llu%llu",&u,&v);
        g[u].emplace_back(i,v);
        g[v].emplace_back(i,u);
    }
    dfs(1);
    if (all<1ull*x*(n-1)){
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 1; i < n; ++i) {
            printf("%llu\n",ans[i]);
        }
    }
}
