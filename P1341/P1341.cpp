#include <bits/stdc++.h>

#define N 52
#define P
using namespace std;
int n;
bool g[N][N];
char deg[N],m;

char get(){
    char c;
    while ((c=getchar())<'A');
    if (c<='Z')return c-'A';
    return c-'a'+26;
}

void dfs(char u){
    for (char v = N-1; v >= 0; --v) {
        if (g[u][v]){
            g[u][v]= g[v][u]=false;
            dfs(v);
        }
    }
    printf("%c",u<26?u+'A':u-26+'a');
}

signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        char u = get(), v = get();
        g[u][v] = g[v][u] = true;
        deg[u]++, deg[v]++;
    }
    int jc = 0;
    for (char i = 0; i < N; ++i)
        if (deg[i] & 1) {
            jc++;
            m = i;
        }
    if (jc==0){
        for (char i = N-1; i >= 0; --i) {
            if (deg[i]){
                m=i;
                break;
            }
        }
    } else if (jc!=2){
        puts("No Solution");
        return 0;
    }
    dfs(m);
}
