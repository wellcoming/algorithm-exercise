#include <bits/stdc++.h>
#define ll long long
#define id(x) (lower_bound(na+1,na+nn+1,x)-na)
#define N 100005
#define RT 1
using namespace std;
int n,nn,m;
int a[N],na[N];
vector<int> g[N];
struct node{
    int l,r,w;
}t[N<<5];
int rt[N],cnt;
int fa[N],top[N],siz[N],hv[N],dep[N];

int update(int x, int p, int l=1, int r=nn){
    int root=++cnt;
    t[root]=t[p];
    t[root].w++;
    int mid=(l+r)>>1;
    if (l<r){
        if (x<=mid)t[root].l=update(x, t[p].l, l, mid);
        else t[root].r=update(x, t[p].r, mid + 1, r);
    }
    return root;
}

void dfs1(int u,int f){
    fa[u]=f,siz[u]=1,dep[u]=dep[f]+1;
    rt[u]= update(a[u],rt[f]);
    for (auto v:g[u]){
        if (v==f)continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if (siz[v]>siz[hv[u]])hv[u]=v;
    }
}

void dfs2(int u,int tp){
    top[u]=tp;
    if (!hv[u])return;
    dfs2(hv[u],tp);
    for (auto v:g[u]){
        if (v==fa[u]||v==hv[u])continue;
        dfs2(v,v);
    }
}

int lca(int x,int y){
    while (top[x]!=top[y]){
        if (dep[top[x]]<dep[top[y]])swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}

int query(int k,int ua,int ub,int ul,int uf,int l=1,int r=nn) {
    if (l >= r)return l;
    int v=t[t[ua].l].w+t[t[ub].l].w-t[t[ul].l].w-t[t[uf].l].w;
    int mid=(l+r)>>1;
    if (k<=v)return query(k,t[ua].l,t[ub].l,t[ul].l,t[uf].l,l,mid);
    else return query(k-v,t[ua].r,t[ub].r,t[ul].r,t[uf].r,mid+1,r);
}

signed main(){
    scanf("%d%d",&n,&m);
    //点权
    for (int i = 1; i <= n; ++i)
        scanf("%d",&a[i]);
    memcpy(na,a,(n+1)*(sizeof *a));
    sort(na+1,na+n+1);
    nn=unique(na+1,na+n+1)-na-1;
    for (int i = 1; i <= n; ++i)
        a[i]=id(a[i]);
    //树边
    for (int i = 1; i < n; ++i) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    //树链剖分
    dfs1(RT,0);
    dfs2(RT,RT);
    //询问
    int lst=0;
    for (int i = 1; i <= m; ++i) {
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        u^=lst;
        int l= lca(u,v);
        lst= na[query(k,rt[u],rt[v],rt[l],rt[fa[l]])];
        printf("%d\n",lst);
    }

}
