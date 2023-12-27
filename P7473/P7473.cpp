#include <bits/stdc++.h>
#define L 0b00
#define R 0b01
#define U 0b10
#define D 0b11
#define id(x,y) ((x)*(n+1)+(y))
#define gx(p) ((p)/(n+1))
#define gy(p) ((p)%(n+1))
#define ha(p1,p2) ((p1)*(n+1)*(n+1)+(p2))
#define N 255
#define P
using namespace std;
int n,m,q;
int g[N*N][4];
int mp[N][N];
unordered_set<int> vis;
struct state{
    int p1,p2,step;
};
queue<state> que;
int bfs(int p1,int p2){
    que=queue<state>();
    vis.clear();
    que.push({p1,p2,0});
    vis.insert(ha(p1,p2));
    while (!que.empty()){
        auto p=que.front();
        que.pop();
        if (p.p1==p.p2)return p.step;
        for (int i = 0; i < 4; ++i) {
            int np1=g[p.p1][i],np2=g[p.p2][i];
            if (p1==np1 and p2==np2)continue;
            if (vis.count(ha(np1,np2)))continue;
            vis.insert(ha(np1,np2));
            que.push({np1,np2,p.step+1});
        }
    }
    return -1;
}

signed main(){
    scanf("%d%d%d",&n,&m,&q);
    for (int x=1;x<=n;++x){
        for (int y=1;y<=n;++y){
            int i=id(x,y);
            g[i][L]=id(1,y);
            g[i][R]=id(n,y);
            g[i][U]=id(x,1);
            g[i][D]=id(x,n);
        }
    }
    for (int i = 1; i <= m; ++i) {
        int x,y;
        scanf("%d%d",&x,&y);
        mp[x][y]=-1;
        for (int l = x+1; l<=n and gx(g[id(l,y)][L])<=x; ++l)
            g[id(l,y)][L]=id(x+1,y);
        for (int l = x-1; l>=1 and gx(g[id(l,y)][R])>=x; --l)
            g[id(l,y)][R]=id(x-1,y);
        for (int l = y+1; l<=n and gy(g[id(x,l)][U])<=y; ++l)
            g[id(x,l)][U]=id(x,y+1);
        for (int l = y-1; l>=1 and gy(g[id(x,l)][D])>=y; --l)
            g[id(x,l)][D]=id(x,y-1);
    }
    for (int i = 1; i <= n; ++i) mp[i][0]=mp[i][n+1]=mp[0][i]=mp[n+1][i]=-1;
    int cnt=0;
    for (int x=1;x<=n;++x){
        for (int y=1;y<=n;++y){
            if (mp[x][y])continue;
            mp[x][y]=++cnt;
            que=queue<state>();
            que.push({x,y,0});
            while (!que.empty()){
                auto p=que.front();
                que.pop();
                if (!mp[p.p1-1][p.p2])mp[p.p1-1][p.p2]=cnt,que.push({p.p1-1,p.p2,0});
                if (!mp[p.p1+1][p.p2])mp[p.p1+1][p.p2]=cnt,que.push({p.p1+1,p.p2,0});
                if (!mp[p.p1][p.p2-1])mp[p.p1][p.p2-1]=cnt,que.push({p.p1,p.p2-1,0});
                if (!mp[p.p1][p.p2+1])mp[p.p1][p.p2+1]=cnt,que.push({p.p1,p.p2+1,0});
            }
        }
    }
    while (q--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if (mp[x1][y1]!=mp[x2][y2]){
            puts("-1");
        } else{
//            bfs(id(x1,y1),id(x2,y2));
            printf("%d\n",bfs(id(x1,y1),id(x2,y2)));
        }
    }
//    printf("%f",1.*clock()/CLOCKS_PER_SEC);


}
