#include<iostream>
#include<vector>
#include <cstring>
//#include<bits/stdc++.h>
using namespace std;
const int maxn=1E3;
int dp[maxn][maxn];//表示字符串1i长度下和字符串2j长度下的最长公共子序列长度
int main() {
    string s1,s2;
    while(cin>>s1>>s2){
        memset(dp,0,sizeof(dp));
        //cerr<<dp[10][0]<<endl;
        for(int i=1,l1=s1.length();i<=l1;i++){//从1开始，否则会越界
            for(int j=1,l2=s2.length();j<=l2;j++){
                //下标应是i-1和j-1
                if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;//如果i位置和j位置的字符相同,则等于都删除此位置的字符对应的dp加1
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);//不相等，则要么消除字符串1位置i的字符,要么消除字符串2位置j的字符，在此基础上寻找较大的那一个值，
                cerr<<dp[i][j]<<" ";
            }
            cerr<<endl;
        }
        cout<<dp[s1.length()][s2.length()]<<endl;
    }
    return 0;
}
