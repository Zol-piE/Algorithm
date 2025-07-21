#include<bits/stdc++.h>
using namespace  std;
int collect(vector<vector<int>> &coins,int n,int m)
{
    vector<vector<int>> dp(n,vector<int>(m,0));
    dp[0][0] = coins[0][0];
    for(int i =1;i<m;i++) dp[0][i] = coins[0][i] + dp[0][i-1];
    for(int i =1;i<n;i++) dp[i][0] = coins[i][0]+ dp[i-1][0];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            dp[i][j] =coins[i][j] + max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n-1][m-1];
}
int main()
{
    int n,m; cin>>n>>m;
    vector<vector<int>> coins(n,vector<int>(m));
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cin>>coins[i][j];
        }
    }
    cout<<collect(coins,n,m);
    return 0;
}
