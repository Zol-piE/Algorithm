#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MOD = 1e9 + 7;
#define OP ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int minCoin(vector<int> &coins,int sum,int n)
{
    vector<vector<int>> dp(n,vector<int>(sum+1,0));

    for(int i =0;i<=sum;i++ ) dp[0][i] = i;

    for(int i =1;i<n;i++)
    {
        for(int j =0;j<=sum;j++)
        {
            if(coins[i] > j ) dp[i][j] = dp[i-1][j];
            else
            {
                dp[i][j] = min(dp[i-1][j] , 1+dp[i][j - coins[i]]);
            }
        }
    }
    return dp[n-1][sum];
}
int main()
{
    OP
    int n ; cin>>n;
    vector<int> coins(n);

    for(int i =0;i<n;i++) cin>>coins[i];

    int sum; cin>>sum;

    cout<<minCoin(coins,sum,n)<<endl;

    return 0;
}
