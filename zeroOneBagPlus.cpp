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
        for(int j=v;j>=V[i];j--){
            //后一个状态由前一个状态推出
            //只能从后往前推，不能从前往后推
            //推完i后，i-1也就消失了
            dp[j]=max(dp[j],dp[j-V[i]]+W[i]);//max里的dp[j]依然是i-1时的值
        }
    }
    cout<<dp[v]<<endl;
    return 0;
}
