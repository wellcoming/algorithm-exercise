#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
int n,m,c,l2;
struct node{
    int v;
    ll w;
    node(int v,ll w):v(v),w(w){}
    bool operator<(const node& rhs)const{
        return w>rhs.w;
    }
};
vector<node> g[N];

priority_queue<node> q;
bool vis[N];
ll dis[N];
ll dijkstra(int f,int t){
    memset(dis,0x3f,(n+5)*(sizeof *dis));
    q.emplace(f,0);
    dis[f]=0;
    while (!q.empty()){
        auto p=q.top();
        q.pop();
        if (vis[p.v])continue;
        if (p.v==t)return p.w;
        vis[p.v]=true;
        for (auto e:g[p.v]){
            if (vis[e.v])continue;
            if (dis[e.v]>p.w+e.w){
                dis[e.v]=p.w+e.w;
                q.emplace(e.v,dis[e.v]);
            }
        }
        for (int i = 0; i <= l2; ++i) {
            int v=(1<<i)^p.v;
            if (vis[v] or v>n)continue;
            if (dis[v]>p.w+c*(1<<i)){
                dis[v]=p.w+c*(1<<i);
                q.emplace(v,dis[v]);
            }
        }
    }
    assert(false);
}
signed main(){
    scanf("%d%d%d",&n,&m,&c);
    l2=31-__builtin_clz(n);
    for (int i = 1; i <= m; ++i) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].emplace_back(v,w);
    }
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%lld\n",dijkstra(a,b));

}
