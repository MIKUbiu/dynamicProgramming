//2022/6/1
#include <algorithm>
#include<iostream>

using namespace std;
const int maxn = 1E6;
const int INF=1<<20;
int dp[maxn];
int w[maxn];
int v[maxn];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        int num;
        cin>>num;
        for(int i=1;i<=num;i++){
            cin>>v[i]>>w[i];
        }
        fill(dp,dp+maxn,INF);
        dp[0]=0;//置初始值，在此基础上开始推导，没有重量自然没有价值
        for(int i=1;i<=num;i++){
            for(int j=w[i];j<=m-n;j++){
                dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        if(dp[m-n]<INF){//当dp[m-n]还是初始值，表明这个没有被更新，即拼凑不了这个重量
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[m-n]<<"."<<endl;
        }
        else cout<<"This is impossible."<<endl;
    }
    return 0;
}
