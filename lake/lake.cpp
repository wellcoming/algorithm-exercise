#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define N 250005
#define P
using namespace std;
int n,m,q;
struct MAP{
    int v[N];
    int* operator[](int x){
        return &v[x*n];
    }
}mp;


signed main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d",&mp[i][j]);
        }
    }

}
