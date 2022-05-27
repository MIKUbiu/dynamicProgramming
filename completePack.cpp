//2022/5/27
#include <bits/stdc++.h>

using namespace std;
const int maxn = 1E6;
using ll = long long;
int V[maxn];
int W[maxn];
int dp[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N,v;
    cin>>N>>v;
    for(int i=1;i<=N;i++){
        cin>>V[i]>>W[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=V[i];j<=v;j++){
            //可多次放入同一个物品只需从前往后推
            //只要背包容量充足，就会反复比较，放入和不放入的区别
            dp[j]=max(dp[j],dp[j-V[i]]+W[i]);
        }
    }
    cout<<dp[v]<<endl;
    return 0;
}
