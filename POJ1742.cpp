#include<iostream>
#include<vector>
#include <cstring>

const int maxn=1E4;
bool dp[maxn];//表示j元下可以拼成
int A[maxn];
int C[maxn];
using namespace std;
int main() {
    int n,m;
    while(cin>>n>>m){

        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        for(int i=0;i<n;i++){
            cin>>C[i];
        }
        if(n==0&&m==0){
            break;
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<n;i++){
          if(A[i]*C[i]>=m){
              for(int j=A[i];j<=m;j++){//如果dp[j-A[i]]可以拼成，则dp[j]也可以拼成
                  if(dp[j-A[i]])dp[j]=true;
              }
          }
          for(int k=1;C[i]>0;k<<=1){//二进制分解成01背包问题，二进制数可以组合成任意一个数，
              int x=min(k,C[i]);//必须要根c[i]比一下，否则x会超出硬币的数量
              for(int j=m;j>=x*A[i];j--){
                  if(dp[j-x*A[i]])dp[j]=true;
              }
              C[i]-=k;
          }
        }
        int cnt=0;
        for(int i=1;i<=m;i++){//价格1~m,所以是从1到m
            if(dp[i])cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
