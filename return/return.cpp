#include <bits/stdc++.h>
#define ll long long
#define N 200005
#define L2 18
#define R 1
#define INF LONG_LONG_MAX
using namespace std;
int n,m;
struct Edge{
    int v,l;
};
vector<Edge> g[N];
struct Edge1{
    int u,v,w;
    bool operator<(const Edge1& rhs)const{
        return w>rhs.w;
    }
};
Edge1 edge[N * 2];
ll dis[N*2];
int h[N*2];
int fa[N*2][L2+1];
bool vis[N];

priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> que;

void dijkstra(){
    que={};
    fill(dis,dis+n+1,INF);
    memset(vis,0,(n+1)*(sizeof *vis));

    dis[R]=0;
    que.emplace(0,R);
    while (!que.empty()){
        ll d;int u;
        tie(d,u)=que.top();
        que.pop();
        if (vis[u])continue;
        vis[u]=true;
        for (auto e:g[u]){
            if (vis[e.v])continue;
            if (dis[e.v]>d+e.l){
                dis[e.v]=d+e.l;
                que.emplace(dis[e.v],e.v);
            }
        }
    }
}
int get(int p){
    if (fa[p][L2]==p)return p;
    return fa[p][L2]=get(fa[p][L2]);
}

void kruskal(){
    for (int i = 1; i <= 2*n-1; ++i) fa[i][0]=fa[i][L2]=i;
    sort(edge+1,edge+m+1);
    int cnt=n;
    for (int i = 1; i <= m; ++i) {
        int u=get(edge[i].u),v=get(edge[i].v);
//        printf("%lf\n",1.*clock()/CLOCKS_PER_SEC);
        fflush(stdout);
        if (u==v)continue;
        fa[u][L2]=fa[v][L2]=fa[u][0]=fa[v][0]=++cnt;
        dis[cnt]= min(dis[u],dis[v]);
        h[cnt]=edge[i].w;
        if (cnt==2*n-1)break;
    }
    for (int i = 2*n-1; i >=1 ; --i) {
        for (int j = 1; j <= L2; ++j) {
            fa[i][j]=fa[fa[i][j-1]][j-1];
        }
    }
}

void init(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; ++i) g[i].clear();
    for (int i = 1; i <= m; ++i) {
        int u,v,l,a;
        scanf("%d%d%d%d",&u,&v,&l,&a);
        g[u].push_back({v,l});
        g[v].push_back({u,l});
        edge[i]={u,v,a};
    }
    dijkstra();
    kruskal();
}
ll solve(int v,int p){
    for (int i = L2; i >= 0; --i) {
        if (h[fa[v][i]]<=p)continue;
        v=fa[v][i];
    }
    return dis[v];
}

signed main(){
    int t;
    scanf("%d",&t);
    while (t--){
        init();
        ll ans=0;
        int q,k,s;
        scanf("%d%d%d",&q,&k,&s);
        for (int i = 1; i <= q; ++i) {
            int v,p;
            scanf("%d%d",&v,&p);
            ans= solve((int)((v+ans*k-1)%n+1),(int)((p+ans*k)%(s+1)));
            printf("%lld\n",ans);
        }
    }


}
