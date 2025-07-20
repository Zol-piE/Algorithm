#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MOD = 1e9 + 7;
#define OP ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int coinChange(vector<int> &coin ,int &sum,int n)
{
    vector<vector<int>> dp(n,vector<int>(sum+1,0));
    for(int i =0;i<n;i++) dp[i][0] = 1; //initialize col-0 ,,sum zero to one

    for(int i =1;i<=sum ; i++)
    {
        if(i % coin[0] == 0 ) dp[0][i] = 1;
        else  dp[0][i] = 0;
    }
    for(int i =1;i<n;i++)
    {
        for(int j =1;j<=sum ;j++)
        {
            if(coin[i] > j ) dp[i][j] = dp[i-1][j];
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j - coin[i]];
            }
        }
    }
    return dp[n-1][sum];
}
signed main()
{
    OP
    int n ; cin>>n;
    vector<int> coins(n);

    for(int i =0;i<n;i++) cin>>coins[i];

    int sum; cin>>sum;

    cout<<coinChange(coins,sum,n);
}


