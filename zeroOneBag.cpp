//2022/5/25
#include <bits/stdc++.h>

using namespace std;
const int maxn = 1E4;
using ll = long long;
int V[maxn];
int W[maxn];
int dp[maxn][maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;//背包的个数和背包的最大容量
    for(int i=1;i<=n;i++){
        cin>>V[i]>>W[i];//i个物品对应的体积和价值
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j<V[i]){//如果当前背包容量小于第i个物品的体积则不放入，此时价值等于放入i-1个物品的背包价值
                dp[i][j]=dp[i-1][j];
            }
            //放入的话，此时价值等于当前背包物品的容量-该物品的容量所对应的i-1个物品的价值加上i的价值
            //未必不放入就一定小，有可能dp[i-1[j-V[i]]非常小，然后当前物品的价值也很小，总共价值比不放入的价值小
            //并不是a+b>a的关系，而是a+b?c的关系
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-V[i]]+W[i]);//比较
        }
    }
    cout<<dp[n][m]<<endl;//
    return 0;
}
