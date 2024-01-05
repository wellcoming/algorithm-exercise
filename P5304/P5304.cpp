#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define N 100005
#define P
using namespace std;
int n,m,k;
int p[N];
int s[N];
struct node{
    int v;
    ll w;
    bool operator<(const node& rhs)const{
        return w>rhs.w;
    }
};
vector<node> g[N];
//unordered_map<int,int> s;
void init(){
    scanf("%d%d%d",&n,&m,&k);

    for (int i = 1; i <= n; ++i) g[i].clear();
    memset(s,0,(n+1)*(sizeof *s));

    for (int i = 1; i <= m; ++i) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for (int i = 1; i <= k; ++i)
        scanf("%d",&p[i]);
    sort(p+1,p+k+1);
    for (int i = 1; i <= k; ++i)
        s[p[i]]=i;

}
priority_queue<node> q;
bool vis[N];
ll dis[N];
ll dijkstra(int fli,int fri,int tli,int tri){
    q={};
    memset(vis,0,(n+1)*(sizeof *vis));
    fill(dis,dis+n+1,LLONG_MAX);
    for (int i = fli; i <= fri; ++i) q.push({p[i],dis[p[i]]=0});
    while (!q.empty()){
        node u=q.top();
        q.pop();
        if (vis[u.v])continue;
        if (tli<=s[u.v]&&s[u.v]<=tri)return u.w;
        vis[u.v]=true;
        for (auto e:g[u.v]){
            if (vis[e.v])continue;
            if (dis[e.v]>u.w+e.w){
                q.push({e.v,dis[e.v]=u.w+e.w});
            }
        }
    }
    return LLONG_MAX;
}

ll solve(int l=1,int r=k){
    if (r-l+1<2)return LLONG_MAX;
    int mid=(l+r)>>1;
    ll ans= min(dijkstra(l,mid,mid+1,r),dijkstra(mid+1,r,l,mid));

}


signed main(){
    int t;
    scanf("%d",&t);
    while (t--){

    }
}
