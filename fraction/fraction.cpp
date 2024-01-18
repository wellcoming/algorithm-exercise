#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define N
#define P
using namespace std;
int n;



pair<int,int> solve(int a,int b,int c,int d){
    bool x=a>b,y=c>d;
    if (x and y){
        int u= min(a/b,c/d);
        a-=u*b,c-=u*d;
        auto ans=solve(b,a,d,c);
        ans.first+=u*ans.second;
        return ans;
    }
    return {1,1};
}

signed main(){
    int a,b,c,d;
    while (scanf("%d%d%d%d",&a,&b,&c,&d)){
        auto ans= solve(max(a,b),min(a,b),max(c,d),min(c,d));
        printf("%d/%d\n", ans.first,ans.second);
    }

}
