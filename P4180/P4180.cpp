#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define N 100005
#define R 1
using namespace std;
int n,m;
struct Edge{
    int v,w,nxt;
    bool t{};
}E[3*N];
int head[N],tot;
bool vis[N];
void add_edge(int u,int v,int w){
    E[++tot]={v,w,head[u]};
    head[u]=tot;
    E[++tot]={u,w,head[v]};
    head[v]=tot;
}
priority_queue<Edge*>
void prim(){

}
signed main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; ++i) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
    }
}
